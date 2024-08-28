#include "s21_scanf.h"

int s21_isspace(char c) {
  return (c == ' ' || c == '\t' || c == '\n' || c == '\0');
}

int s21_sscanf(const char *str, const char *format, ...) {
  int res = 0;
  va_list va;
  va_start(va, format);
  int flag_quit = 1;
  s21_size_t j = 0;
  char ch;
  for (s21_size_t i = 0;
       i < s21_strlen(format) && j < s21_strlen(str) && flag_quit; i++) {
    ch = format[i];
    switch (ch) {
      case ' ':
      case '\t':
      case '\n':
        while (s21_isspace(str[j]) && j < s21_strlen(str)) j++;
        break;
      case '%':
        read(&i, &j, str, format, va, &res);
        break;
      default:
        if (ch != str[j])
          flag_quit = 0;
        else
          j++;
        break;
    }
  }
  va_end(va);
  return res;
}

void read(s21_size_t *i, s21_size_t *j, const char *str, const char *format,
          va_list va, int *res) {
  char *ch;
  struct rd_frm read_format = {1, 0, ' ', 0};
  int read_flag = 1;
  while (read_flag && format[*i] != '\0') {
    *i = *i + 1;
    switch (format[*i]) {
      case '*':
        read_format.save = 0;
        break;
      case 48 ... 57:
        read_format.width = read_format.width * 10 + format[*i] - 48;
        break;
      case 'h':
      case 'l':
      case 'L':
        read_format.lenth = format[*i];
        break;
      case 'c':
        if (read_format.save) {
          ch = va_arg(va, char *);
          *ch = str[*j];
          *res = *res + 1;
        }
        *j = *j + 1;
        read_flag = 0;
        ReadFormatReload(&read_format);
        break;
      case 'd':
        read_format.base = 10;
        ScanInt(va, &read_format, str, j, res);
        read_flag = 0;
        break;
      case 'i':
        ScanInt(va, &read_format, str, j, res);
        read_flag = 0;
        break;
      case 'o':
        read_format.base = 8;
        ScanUnSignInt(va, &read_format, str, j, res);
        read_flag = 0;
        break;
      case 'u':
        read_format.base = 10;
        ScanUnSignInt(va, &read_format, str, j, res);
        read_flag = 0;
        break;
      case 'x':
      case 'X':
        read_format.base = 16;
        ScanUnSignInt(va, &read_format, str, j, res);
        read_flag = 0;
        break;
      case 'e':
      case 'E':
      case 'f':
      case 'g':
      case 'G':
        ScanDouble(va, &read_format, str, j, res);
        read_flag = 0;
        break;
      case 'p':
        read_format.base = 16;
        read_format.lenth = 'l';
        ScanUnSignInt(va, &read_format, str, j, res);
        read_flag = 0;
        break;
      case 'n':
        *va_arg(va, int *) = (int)*j;
        read_flag = 0;
        ReadFormatReload(&read_format);
        break;
      case '%':
        if (str[*j] == '%') *j = *j + 1;
        read_flag = 0;
        ReadFormatReload(&read_format);
        break;
      case 's':
        ScanString(va, &read_format, str, j, res);
        read_flag = 0;
      default:
        break;
    }
  }
}

void ReadFormatReload(struct rd_frm *read_format) {
  read_format->save = 1;
  read_format->width = 0;
  read_format->lenth = ' ';
  read_format->base = 0;
}

void ScanInt(va_list va, struct rd_frm *read_format, const char *str1,
             s21_size_t *j, int *res) {
  char *tmp, *str8 = NULL;
  const char *str;
  s21_size_t i;
  for (; s21_isspace(str1[*j]); *j = *j + 1)
    ;
  if (read_format->width < s21_strlen(str1) && read_format->width != 0) {
    str8 = malloc(sizeof(char) * (read_format->width + 1));
    for (i = 0; i < read_format->width; i++) str8[i] = str1[*j + i];
    str8[i] = '\0';
    str = str8;
  } else
    str = str1 + *j;
  if (read_format->save) {
    switch (read_format->lenth) {
      case ' ':
        *va_arg(va, int *) = (int)strtol(str, &tmp, read_format->base);
        break;
      case 'h':
        *va_arg(va, short int *) =
            (short int)strtol(str, &tmp, read_format->base);
        break;
      case 'l':
        *va_arg(va, long int *) =
            (long int)strtol(str, &tmp, read_format->base);
        break;
    }
    if (str != tmp) *res = *res + 1;
  } else
    strtol(str, &tmp, read_format->base);

  if (str != tmp)
    *j = *j + tmp - str;
  else
    *j = s21_strlen(str1);
  if (str8 != NULL) {
    free(str8);
  }
  ReadFormatReload(read_format);
}

void ScanUnSignInt(va_list va, struct rd_frm *read_format, const char *str1,
                   s21_size_t *j, int *res) {
  char *tmp, *str8 = NULL;
  const char *str;
  s21_size_t i;
  for (; s21_isspace(str1[*j]); *j = *j + 1)
    ;
  if (read_format->width < s21_strlen(str1) && read_format->width != 0) {
    str8 = malloc(sizeof(char) * (read_format->width + 1));
    for (i = 0; i < read_format->width; i++) str8[i] = str1[*j + i];
    str8[i] = '\0';
    str = str8;
  } else
    str = str1 + *j;
  if (read_format->save) {
    switch (read_format->lenth) {
      case ' ':
        *va_arg(va, unsigned int *) =
            (unsigned int)strtoul(str, &tmp, read_format->base);
        break;
      case 'h':
        *va_arg(va, unsigned short int *) =
            (unsigned short int)strtoul(str, &tmp, read_format->base);
        break;
      case 'l':
        *va_arg(va, unsigned long int *) =
            (unsigned long int)strtoul(str, &tmp, read_format->base);
        break;
    }
    if (str != tmp) *res = *res + 1;
  } else
    strtoul(str, &tmp, read_format->base);
  if (str != tmp)
    *j = *j + tmp - str;
  else
    *j = s21_strlen(str1);
  if (str8 != NULL) {
    free(str8);
  }
  ReadFormatReload(read_format);
}

void ScanDouble(va_list va, struct rd_frm *read_format, const char *str1,
                s21_size_t *j, int *res) {
  char *tmp, *str8 = NULL;
  const char *str;
  s21_size_t i;
  for (; s21_isspace(str1[*j]); *j = *j + 1)
    ;
  if (read_format->width < s21_strlen(str1) && read_format->width != 0) {
    str8 = malloc(sizeof(char) * (read_format->width + 1));
    for (i = 0; i < read_format->width; i++) str8[i] = str1[*j + i];
    str8[i] = '\0';
    str = str8;
  } else
    str = str1 + *j;
  if (read_format->save) {
    switch (read_format->lenth) {
      case ' ':
        *va_arg(va, float *) = strtof(str, &tmp);
        break;
      case 'l':
        *va_arg(va, double *) = strtod(str, &tmp);
        break;
      case 'L':
        *va_arg(va, long double *) = strtold(str, &tmp);
        break;
    }
    if (str != tmp) *res = *res + 1;
  } else
    strtold(str, &tmp);

  if (str != tmp)
    *j = *j + tmp - str;
  else
    *j = s21_strlen(str1);
  if (str8 != NULL) {
    free(str8);
  }
  ReadFormatReload(read_format);
}

void ScanString(va_list va, struct rd_frm *read_format, const char *str,
                s21_size_t *j, int *res) {
  char *tmp;
  s21_size_t i;
  if (read_format->save) {
    tmp = va_arg(va, char *);
    for (i = 0; !s21_isspace(str[*j + i]) &&
                (read_format->width == 0 || i < read_format->width);
         i++)
      tmp[i] = str[*j + i];
    tmp[i] = '\0';
    *j = *j + i;
    *res = *res + 1;
  } else {
    for (; !s21_isspace(str[*j]); *j = *j + 1)
      ;
  }
  ReadFormatReload(read_format);
}
