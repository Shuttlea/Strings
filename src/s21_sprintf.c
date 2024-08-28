#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  char *tmp_str = str;  // Для обработки используй локальную tmp_str
  Specs specs = {0};
  va_list ap;
  va_start(ap, format);

  while (*format != '\0') {
    if (*format == '%') {
      format++;
      format += parcer(&specs, format, ap);
      if (*format == 'c' || *format == '%') {
        if (*format == '%') specs.percent = true;
        spec_c(ap, tmp_str, specs);
        if (specs.width != 0)
          tmp_str += specs.width - 1;
        else if (specs.width == 0)
          tmp_str += specs.width;
        format++;
      } else if (*format == 'd' || *format == 'i' || *format == 'u') {
        if (*format == 'u') {
          spec_u(ap, &tmp_str, specs);
        } else
          spec_d(ap, &tmp_str, specs);
        format++;
      } else if (*format == 'f') {
        spec_f(ap, &tmp_str, specs);
        format++;
      } else if (*format == 'e' || *format == 'E') {
        if (*format == 'E') specs.spec_E = true;
        spec_e(ap, &tmp_str, specs);
        format++;
      } else if (*format == 'g' || *format == 'G') {
        if (*format == 'G') specs.spec_G = true;
        spec_g(ap, &tmp_str, specs);
        format++;
      } else if (*format == 'x' || *format == 'X') {
        if (*format == 'X') specs.spec_X = true;
        spec_x(ap, &tmp_str, specs);
        format++;
      } else if (*format == 'o') {
        spec_o(ap, &tmp_str, specs);
        format++;
      } else if (*format == 'p') {
        spec_p(ap, &tmp_str, specs);
        format++;
      } else if (*format == 'n') {
        spec_n(ap, str, tmp_str);
        format++;
        tmp_str--;
      } else if (*format == 's') {
        spec_s(ap, &tmp_str, specs);
        format++;
      } else
        exit(1);
      zeroid(&specs);
    } else if (*format != '\0') {
      *tmp_str = *format;
      format++;
    }
    tmp_str++;
  }
  *tmp_str = '\0';
  va_end(ap);
  return s21_strlen(str);
}

/* add by trosstar */
void spec_u(va_list ap, char **str, Specs specs) {
  long unsigned int ch = 0;
  if (specs.spec_short_int)
    ch = (short unsigned)va_arg(ap, unsigned int);
  else if (specs.spec_long_int)
    ch = va_arg(ap, long unsigned int);
  else
    ch = (unsigned)va_arg(ap, unsigned int);

  int j = 0;
  char str_tmp[800] = {0};
  char c = specs.spec_zero ? '0' : ' ';
  while (ch != 0) {
    *(str_tmp + j) = "0123456789"[ch % 10];
    j++;
    ch /= 10;
  }

  int count = j;
  int count_plas_zero = j;
  int long_ = j;
  int x = specs.width;
  int y = specs.accur;
  if (x > y) {
    for (; ((x - j) > 0) || ((y - j) > 0); x--, y--) {
      if (y - j > 0) {
        str_tmp[count++] = '0';
        long_++;
        count_plas_zero++;
        continue;
      }
      if (x > 0) {
        str_tmp[count++] = c;
        long_++;
      }
    }
  } else {
    for (; ((x - j) > 0) || ((y - j) > 0); x--, y--) {
      if (y > 0) {
        str_tmp[count++] = '0';
        count_plas_zero++;
      } else if (x > 0)
        str_tmp[count++] = ' ';
      long_++;
    }
  }

  char b;
  for (int i = 0; i < long_ / 2; i++) {
    b = str_tmp[i];
    str_tmp[i] = str_tmp[long_ - i - 1];
    str_tmp[long_ - i - 1] = b;
  }

  if (specs.spec_minus) {
    if (count > j) {
      for (int i = 0; i < (long_ - count_plas_zero); i++) {
        int temp = str_tmp[0];
        for (int i = 0; i < (count - 1); i++) str_tmp[i] = str_tmp[i + 1];
        str_tmp[count - 1] = temp;
      }
    }
  }

  for (int i = 0; i < long_; i++) {
    **str = str_tmp[i];
    (*str)++;
  }
  (*str)--;
}

void spec_c(va_list ap, char *str, Specs specs) {
  char ch = '%';
  if (!specs.percent) ch = (char)va_arg(ap, int);
  if (specs.spec_minus == true) {
    *(str++) = ch;
    for (int i = 0; i < specs.width; i++) *(str++) = ' ';
  } else if (specs.spec_minus == false) {
    for (int i = 0; i < specs.width - 1; i++)
      *(str++) = specs.spec_zero ? '0' : ' ';
    *str = ch;
  }
}

void spec_d(va_list ap, char **str, Specs specs) {
  long long ch = 0;
  long ch_for_count = 0;
  int counter = 0, sign = 0, negative = 0;
  if (specs.spec_short_int)
    ch = (short)va_arg(ap, int);
  else if (specs.spec_long_int)
    ch = (long)va_arg(ap, long);
  else
    ch = (int)va_arg(ap, int);
  ch_for_count = ch;
  if (ch < 0) {
    negative = 1;
    ch = -ch;
  }
  if (negative || specs.spec_plus == true || specs.spec_space) sign = 1;
  while (ch_for_count != 0) {
    ch_for_count = ch_for_count / 10;
    counter++;
  }
  if (!specs.point) specs.accur = 6;
  if (!counter && specs.accur) counter = 1;

  int len = specs.width > specs.accur + sign ? specs.width : specs.accur + sign;
  char var[counter > len ? counter : len];
  int i = number_to_char_mass(ch, specs, var, 0, counter - specs.accur);
  if (specs.point)
    for (; i < specs.accur; i++) var[i] = '0';
  if (specs.spec_zero && !specs.spec_minus)
    for (; i < specs.width - sign; i++) var[i] = '0';
  if (sign) var[i++] = sign_token(negative, specs);
  if (!specs.spec_minus)
    for (; i < specs.width; i++) var[i] = ' ';

  int counter_for_minus = i--;
  for (; i >= 0; i--) {
    **str = var[i];
    (*str)++;
  }
  if (specs.spec_minus) {
    int len = specs.width - specs.accur - sign;
    if (len < 0) {
      len = 0;
    }
    char var_for_spaces[len];
    spaces_with_minus(str, var_for_spaces, specs, counter_for_minus);
  }
  (*str)--;
}

int parcer(Specs *specs, const char *format, va_list ap) {
  int counter_of_letter = 0, flag = 0, num_extr_shift = 0;
  while (!flag) {
    if (*format == '+') {
      specs->spec_plus = true;
      counter_of_letter++;
      format++;
    }
    if (*format == '-') {
      specs->spec_minus = true;
      counter_of_letter++;
      format++;
    }
    if (*format == '.') {
      specs->point = true;
      counter_of_letter++;
      format++;
    }
    if (*format == ' ') {
      specs->spec_space = true;
      counter_of_letter++;
      format++;
    }
    if (*format == '0') {
      if (!specs->point) {
        specs->spec_zero = true;
      }
      counter_of_letter++;
      format++;
    }
    if (*format >= '1' && *format <= '9') {
      int num_extr_shift_local = num_extractor(specs, format);
      format += num_extr_shift_local;
      num_extr_shift += num_extr_shift_local;
    }
    if (*format == 'h') {
      specs->spec_short_int = true;
      counter_of_letter++;
      format++;
    }
    if (*format == 'l') {
      specs->spec_long_int = true;
      counter_of_letter++;
      format++;
    }
    if (*format == 'L') {
      specs->spec_long_double = true;
      counter_of_letter++;
      format++;
    }
    if (*format == '*') {
      width_and_accur_from_arg(specs, ap);
      counter_of_letter++;
      format++;
    }
    if (*format == '#') {
      specs->spec_sharp = true;
      counter_of_letter++;
      format++;
    }
    flag = formatwalk(*format);
  }
  return counter_of_letter + num_extr_shift;
}

int formatwalk(char format) {
  int end_of_format = 0;
  if (format == 'd' || format == 'c' || format == 'f' || format == 's' ||
      format == 'e' || format == 'E' || format == 'g' || format == 'G' ||
      format == 'i' || format == 'o' || format == 'u' || format == 'x' ||
      format == 'X' || format == 'p' || format == 'n' || format == '%')
    end_of_format = 1;

  return end_of_format;
}

void zeroid(Specs *specs) {
  specs->percent = false;
  specs->spec_plus = false;
  specs->spec_minus = false;
  specs->spec_space = false;
  specs->accur = 0;
  specs->width = 0;
  specs->spec_zero = false;
  specs->spec_short_int = false;
  specs->spec_long_int = false;
  specs->spec_long_double = false;
  specs->star_before_point = false;
  specs->star_after_point = false;
  specs->number_sign = false;
  specs->point = false;
  specs->spec_E = false;
  specs->spec_G = false;
  specs->spec_X = false;
  specs->format_shift = 0;
}

int num_extractor(Specs *specs, const char *format) {
  int counter = 0;
  while (*format >= 48 && *format <= 57) {
    counter++;
    format++;
  }
  format -= counter;
  char num[counter];
  for (int i = 0; i < counter; i++) num[i] = *(format++);
  num[counter] = '\0';
  if (specs->point == false)
    s21_atoi_before_point(specs, num);
  else if (specs->point == true)
    s21_atoi_after_point(specs, num);
  specs->format_shift += counter;

  return counter;
}

void s21_atoi_after_point(Specs *specs, char *num) {
  int accur = 0;
  if (*num < 0) {
    specs->spec_minus = true;
    *num = -*num;
  }
  while (*num != 0) {
    accur *= 10;
    accur += (int)(*num - 48);
    num++;
  }
  specs->accur = accur;
}

void s21_atoi_before_point(Specs *specs, char *num) {
  int width = 0;
  if (*num < 0) {
    specs->spec_minus = true;
    *num = -*num;
  }
  while (*num != 0) {
    width *= 10;
    width += (int)(*num - 48);
    num++;
  }
  specs->width = width;
}

void spec_f(va_list ap, char **str, Specs specs) {
  long double ch = 0;
  int negative = 0, sign = 0, int_counter = 0, point = 0;

  if (specs.spec_long_double)
    ch = (long double)va_arg(ap, long double);
  else
    ch = (double)va_arg(ap, double);
  if (specs.accur == 0 && !specs.point) specs.accur = 6;
  if (ch < 0) {
    negative = 1;
    ch = -ch;
  }
  if ((negative || specs.spec_plus || specs.spec_space)) sign = 1;
  long long int int_ch =
      specs.accur == 0 ? (long long)round(ch) : (long long)(ch);
  double prov = ch - (long double)int_ch;
  long long float_ch = round((prov)*pow(10, specs.accur));

  int ch_for_counter = int_ch;
  while (ch_for_counter != 0) {
    ch_for_counter = ch_for_counter / 10;
    int_counter++;
  }

  char var[specs.width > int_counter + specs.accur + 1
               ? specs.width
               : int_counter + specs.accur + 1];
  int i = number_to_char_mass(float_ch, specs, var, 0, 0);
  if (specs.accur != 0 || specs.spec_sharp) {
    var[i++] = '.';
    point = 1;
  }
  if (!int_counter)
    var[i++] = '0';
  else
    i = number_to_char_mass(
        int_ch, specs, var, i,
        int_counter + ((specs.accur == 0 && !specs.spec_sharp) ? 0 : 1));
  if (specs.spec_zero && !specs.spec_minus)
    for (; i < specs.width - sign; i++) var[i] = '0';
  if (sign) var[i++] = sign_token(negative, specs);
  if (!specs.spec_minus)
    for (; i < specs.width; i++) var[i] = ' ';

  for (i--; i >= 0; i--) {
    **str = var[i];
    (*str)++;
  }
  if (specs.spec_minus) {
    for (int j = 0; j < specs.width - specs.accur -
                            (int_counter > 0 ? int_counter : 1) - sign - point;
         j++) {
      **str = ' ';
      (*str)++;
    }
  }
  (*str)--;
}

void spec_e(va_list ap, char **str, Specs specs) {
  long double ch = 0;
  int negative = 0, sign = 0;

  if (specs.spec_long_double)
    ch = (long double)va_arg(ap, long double);
  else
    ch = (double)va_arg(ap, double);
  if (ch < 0.0) {
    negative = 1;
    ch = -ch;
  }
  if (negative || specs.spec_plus == true || specs.spec_space) sign = 1;
  if (ch != 0)
    spec_e_not_zero(ch, str, specs, negative, sign);
  else if (ch == 0)
    spec_e_zero(str, specs, negative, sign);
}

/* add by rossartt */
void spec_s(va_list ap, char **str, Specs specs) {
  char *add_str = 0;
  add_str = va_arg(ap, char *);
  int len = s21_strlen(add_str);
  **str = '\0';

  if (specs.point && specs.accur >= 0 && specs.accur < len) len = specs.accur;
  if (specs.width > len) {
    int len_spaces = specs.width - len;
    char spaces[len_spaces + 1];
    for (int i = 0; i < len_spaces; i++) spaces[i] = ' ';
    spaces[len_spaces] = '\0';
    if (specs.spec_minus) {
      s21_strncat(*str, add_str, len);
      s21_strncat(*str, spaces, len_spaces);
    } else {
      if (specs.spec_zero) {
        s21_memset(spaces, '0', len_spaces);
      }
      s21_strncat(*str, spaces, len_spaces);
      s21_strncat(*str, add_str, len);
    }
  } else
    s21_strncat(*str, add_str, len);
  *str += s21_strlen(*str) - 1;
}

void width_and_accur_from_arg(Specs *specs, va_list ap) {
  int size = va_arg(ap, int);
  if (!specs->point) {
    if (size < 0) {
      specs->spec_minus = true;
      specs->width = -size;
    } else
      specs->width = size;
  } else if (specs->point)
    if (size > 0) specs->accur = size;
}

char sign_token(int negative, Specs specs) {
  char sign = ' ';
  if (!negative && specs.spec_space)
    sign = ' ';
  else if (specs.spec_plus && !negative)
    sign = '+';
  else if (negative)
    sign = '-';
  return sign;
}

void spec_e_not_zero(long double ch, char **str, Specs specs, int negative,
                     int sign) {
  int exp_counter = 0;
  double ch_for_sign = ch;

  if (ch >= 1) {
    while (ch >= 1) {
      ch /= 10;
      exp_counter++;
    }
    exp_counter--;
  } else if (ch < 1) {
    while (ch < 1) {
      ch *= 10;
      exp_counter++;
    }
    ch /= 10;
  }
  if (!specs.point) specs.accur = 6;
  long long full_ch = round(
      ch *
      pow(10,
          specs.accur +
              (fabsl(ch - 1.0L) < 1.0L / (powl(10, specs.accur + 1)) ? 0 : 1)));
  char var[specs.accur + 5];  // чтобы вместить целое, точку, + и экспоненту
  var[0] = '\0';
  int i = writting_exp(
      var, 0,
      exp_counter -
          (fabsl(ch - 1.0L) < 1.0L / (powl(10, specs.accur + 1)) ? 1 : 0));
  ;
  var[i++] = ch_for_sign >= 1.0 ? '+' : '-';
  var[i++] = specs.spec_E ? 'E' : 'e';
  int del1 = 0, j = i;
  for (; j < specs.accur + 4; j++) {
    del1 = full_ch % 10;
    var[j] = (char)(del1 + 48);
    full_ch = full_ch / 10;
  }
  i = j;
  if (specs.accur >= 1 || specs.spec_sharp) var[i++] = '.';
  var[i++] = (char)((full_ch % 10) + 48);
  if (specs.spec_zero && !specs.spec_minus)
    for (; i < specs.width - sign; i++) var[i] = '0';
  if (sign) var[i++] = sign_token(negative, specs);
  if (!specs.spec_minus)
    for (; i < specs.width; i++) var[i] = ' ';

  for (i--; i >= 0; i--) {
    **str = var[i];
    (*str)++;
  }
  if (specs.spec_minus) spaces_with_minus_for_specs_e_g(str, specs, sign, -1);
  (*str)--;
}

void spec_e_zero(char **str, Specs specs, int negative, int sign) {
  if (!specs.point) {
    specs.accur = 6;
  }
  int i = 0;
  char var[specs.accur + 4];
  for (; i < 2; i++) var[i] = '0';
  var[i++] = '+';
  var[i++] = specs.spec_E ? 'E' : 'e';
  for (; i < specs.accur + 4; i++) var[i] = '0';
  if (specs.accur > 0 || specs.spec_sharp) var[i++] = '.';
  var[i++] = '0';
  if (sign) var[i++] = sign_token(negative, specs);
  if (!specs.spec_minus)
    for (; i < specs.width + sign; i++) var[i] = ' ';
  for (i--; i >= 0; --i) {
    **str = var[i];
    (*str)++;
  }
  if (specs.spec_minus) {
    char var_for_spaces[specs.width];
    int j = 0;
    if (specs.spec_minus && specs.width > specs.accur + 5 + (sign | 1)) {
      for (; j < specs.width - specs.accur - 5 - sign - 1; j++)
        var_for_spaces[j] = ' ';
      for (j--; j >= 0; j--) {
        **str = var_for_spaces[j];
        (*str)++;
      }
    }
  }
  (*str)--;
}

void spec_g(va_list ap, char **str, Specs specs) {
  long double ch = 0.0;
  int negative = 0, sign = 0;

  if (specs.spec_long_double)
    ch = va_arg(ap, long double);
  else
    ch = (double)va_arg(ap, double);
  if (ch < 0) {
    negative = 1;
    ch = -ch;
  }
  if (negative || specs.spec_plus == true || specs.spec_space) sign = 1;
  if (ch < 1 && ch > 0)
    spec_g_for_num_less_one(ch, str, specs, negative, sign);
  else if (ch > 1)
    spec_g_for_num_more_one(ch, str, specs, negative, sign);
  else if (ch == 0.0)
    spec_g_zero(str, specs, negative, sign);
  (*str)--;
}

void spec_g_for_num_less_one(long double ch, char **str, Specs specs,
                             int negative, int sign) {
  if (!specs.spec_long_double) ch = (double)ch;
  int exp_counter = 0, zero = 0, i_zero = 0, deleted_zeros = 0, point = 0,
      trash_zero_for_spec_minus = 0;
  while (ch < 1) {
    ch *= 10;
    exp_counter++;
  }
  ch /= 10;
  if (fabsl(ch - 1.0L) < 1.0L / (powl(10, specs.accur + 1))) {
    ch /= 10;
    exp_counter--;
  }
  if (!specs.point)
    specs.accur = 6;
  else if (specs.accur == 0)
    specs.accur = 1;
  long long int full_ch = round(ch * pow(10, specs.accur));
  if (exp_counter <= 4) {
    char var[specs.accur + exp_counter + sign +
             1];  // для нолей, запятой и числа
    int i = number_to_char_mass(full_ch, specs, var, 0, 1);
    for (; i < specs.accur + exp_counter - 1; i++) var[i] = '0';
    if (specs.accur != exp_counter || specs.spec_sharp) {
      var[i++] = '.';
      point = 1;
    }
    if (point) var[i++] = '0';
    for (; i_zero < i; i_zero++) {
      if (var[i_zero] != '0') zero = 1;
      if (!zero) deleted_zeros++;
    }
    if (specs.spec_zero && !specs.spec_minus)
      for (; i < specs.width + deleted_zeros - sign; i++) var[i] = '0';
    if (sign) var[i++] = sign_token(negative, specs);
    if (!specs.spec_minus)
      for (; i < specs.width + deleted_zeros; i++) var[i] = ' ';
    i--;
    for (int j = 0, trash_zeros = 1; j <= i; j++) {
      if (var[j] != '0') trash_zeros = 0;
      if (trash_zeros && var[j] == '0' && !specs.spec_sharp) var[j] = 'G';
    }
    for (; i >= 0; i--) {
      if (var[i] != 'G') {
        **str = var[i];
        (*str)++;
      } else
        trash_zero_for_spec_minus++;
    }
    if (specs.spec_minus) {
      char var_for_spaces[specs.width - specs.accur - 5 - sign];
      var_for_spaces[0] = '\0';
      int j = 0;
      for (; j < specs.width - specs.accur - exp_counter - sign +
                     trash_zero_for_spec_minus;
           j++)
        var_for_spaces[j] = ' ';
      for (j--; j >= 0; j--) {
        **str = var_for_spaces[j];
        (*str)++;
      }
    }
  } else if (exp_counter > 4)
    spec_g_num_less_one_sci_not(full_ch, str, specs, negative, sign,
                                exp_counter);
}

void spec_g_num_less_one_sci_not(long long full_ch, char **str, Specs specs,
                                 int negative, int sign, int exp_counter) {
  char var[specs.accur + 5];  // чтобы вместить целое, точку, + и экспоненту
  int deleted_zero = 0;
  int i = writting_exp(var, 0, exp_counter);
  var[i++] = '-';
  var[i++] = specs.spec_G ? 'E' : 'e';
  i = number_to_char_mass(
      full_ch, specs, var, i,
      3);  // +4 на эспоненту и - 1 так как первое чиселка за точкой
  if (specs.accur > 1 || specs.spec_sharp) var[i++] = '.';
  var[i++] = (char)((full_ch / pow(10, specs.accur - 1)) + 48);
  if (specs.spec_zero)
    for (; i < specs.width - sign; i++) var[i] = '0';
  if (sign) var[i++] = sign_token(negative, specs);

  for (int j = 0; j <= 10; j++) {  // 10 - с потолка
    if ((var[j] == 'e' || var[j] == 'E') &&
        !specs.spec_sharp) {  // Conditional jump or move depends on
                              // uninitialised value(s)
      j++;
      while (
          var[j] ==
          '0') {  // Conditional jump or move depends on uninitialised value(s)
        var[j++] = 'G';
        deleted_zero++;
      }
    }
  }

  if (!specs.spec_minus)
    for (; i < specs.width + deleted_zero; i++) var[i] = ' ';
  for (i--; i >= 0; i--) {
    if (var[i] != 'G') {
      **str = var[i];
      (*str)++;
    }
  }
  if (specs.spec_minus)
    spaces_with_minus_for_specs_e_g(str, specs, sign, deleted_zero);
}

int number_to_char_mass(long long full_ch, Specs specs, char *var, int i,
                        int shift_for_counter) {
  for (int del = 0; i < specs.accur + shift_for_counter; i++) {
    del = full_ch % 10;
    var[i] = (char)(del + 48);
    full_ch /= 10;
  }
  return i;
}

void spec_g_for_num_more_one(long double ch, char **str, Specs specs,
                             int negative, int sign) {
  if (!specs.spec_long_double) ch = (double)ch;
  int exp_counter = 0;
  while (ch >= 1) {
    ch /= 10;
    exp_counter++;
  }
  if (!specs.point) specs.accur = 6;
  if (exp_counter <= specs.accur) {
    char var[specs.accur];
    long long int full_ch =
        round(ch * pow(10, (specs.accur > 1 ? specs.accur : 1)));
    int i = number_to_char_mass(full_ch, specs, var, 0, -exp_counter);
    ;
    int point = 0, zero = 0, deleted_zeros = 0;
    for (int i_zero = 0; i_zero < i; i_zero++) {
      if (var[i_zero] != '0') zero = 1;
      if (!zero) deleted_zeros++;
    }
    if ((specs.accur != exp_counter && zero) || specs.spec_sharp) {
      var[i++] = '.';
      point = 1;
    }
    long long int_part_of_num =
        (full_ch / (pow(10, specs.accur - exp_counter)));
    i = number_to_char_mass(int_part_of_num, specs, var, i, point);
    if (specs.spec_zero && !specs.spec_minus)
      for (; i < specs.width + deleted_zeros - sign; i++) var[i] = '0';
    if (sign) var[i++] = sign_token(negative, specs);
    if (!specs.spec_minus)
      for (; i < specs.width + deleted_zeros; i++) var[i] = ' ';
    i--;
    for (int j = 0, trash_zeros = 1; j <= i; j++) {
      if (var[j] != '0' && !specs.spec_sharp) trash_zeros = 0;
      if (trash_zeros && var[j] == '0' && !specs.spec_sharp &&
          j < specs.accur - exp_counter)
        var[j] = 'G';
    }
    int trash_zero_for_spec_minus = 0;
    for (; i >= 0; i--) {
      if (var[i] != 'G') {
        **str = var[i];
        (*str)++;
      } else
        trash_zero_for_spec_minus++;
    }
    if (specs.spec_minus)
      spaces_with_minus_for_specs_e_g(
          str, specs, sign,
          (specs.spec_sharp ? -2 : trash_zero_for_spec_minus) +
              (point ? 4 : 5));
  } else if (exp_counter > specs.accur)
    spec_g_for_num_more_one_if_int_part_bigger_accur(ch, str, specs, negative,
                                                     sign, exp_counter);
}

void spec_g_for_num_more_one_if_int_part_bigger_accur(long double ch,
                                                      char **str, Specs specs,
                                                      int negative, int sign,
                                                      int exp_counter) {
  long long full_ch = round(ch * pow(10, (specs.accur > 1 ? specs.accur : 1)));
  char var[specs.accur + 5];
  int deleted_zeros = 0, point = 0;
  int i = writting_exp(var, 0, exp_counter - (full_ch > 9 ? 0 : 1));
  var[i++] = '+';
  var[i++] = specs.spec_G ? 'E' : 'e';
  if (full_ch > 9) deleted_zeros++;
  if (full_ch % 10 == 0 && !specs.spec_sharp) point = 1;
  i = number_to_char_mass_for_g(full_ch, specs, var, i, &deleted_zeros, 3,
                                point);
  if (specs.accur > 1 || specs.spec_sharp) var[i++] = '.';
  if (full_ch > 9)
    var[i++] = (char)((full_ch /
                       pow(10, (specs.accur - 1 > 0 ? specs.accur - 1 : 1))) +
                      48);
  else
    var[i++] = (char)(full_ch + 48);
  if (specs.spec_zero && !specs.spec_minus)
    for (; i < specs.width - sign; i++) var[i] = '0';
  if (sign) var[i++] = sign_token(negative, specs);
  if (!specs.spec_minus)
    for (; i < specs.width; i++) var[i] = ' ';
  for (i--; i >= 0; i--) {
    **str = var[i];
    (*str)++;
  }
  if (specs.spec_minus)
    spaces_with_minus_for_specs_e_g(str, specs, sign, deleted_zeros);
}

int writting_exp(char *var, int i, int exp_counter) {
  for (int del = 0, exp_counter_for_count = exp_counter;
       i < (exp_counter >= 10 ? 2 : 1); i++) {
    del = exp_counter_for_count % 10;
    var[i] = (char)(del + 48);
    exp_counter_for_count /= 10;
  }
  if (exp_counter < 10) var[i++] = '0';
  return i;
}

void spaces_with_minus(char **str, char *var_for_spaces, Specs specs,
                       int counter_for_minus) {
  int j = 0;
  for (; j < specs.width - counter_for_minus; j++) var_for_spaces[j] = ' ';
  for (j--; j >= 0; j--) {
    **str = var_for_spaces[j];
    (*str)++;
  }
}

void spec_g_zero(char **str, Specs specs, int negative, int sign) {
  if (!specs.point) specs.accur = 6;
  char var[specs.width > specs.accur ? specs.width : specs.accur];
  int i = 0;
  if (specs.spec_sharp) {
    for (; i < specs.accur - 1; i++) var[i] = '0';
    var[i++] = '.';
  }
  var[i++] = '0';
  if (specs.spec_zero) {
    for (; i < specs.width - sign; i++) var[i] = '0';
  }
  if (sign) var[i++] = sign_token(negative, specs);
  if (!specs.spec_minus)
    for (; i < specs.width; i++) var[i] = ' ';
  int counter_for_minus = i;
  for (i--; i >= 0; i--) {
    **str = var[i];
    (*str)++;
  }
  if (specs.spec_minus) {
    char var_for_spaces[specs.width - specs.accur - sign];
    spaces_with_minus(str, var_for_spaces, specs, counter_for_minus);
  }
}

void spec_x(va_list ap, char **str, Specs specs) {
  uint64_t ch = 0;
  uint32_t ch_mask = 15;
  int counter = 0, i = 0;
  if (specs.spec_short_int)
    ch = (uint16_t)va_arg(ap, int);
  else if (specs.spec_long_int)
    ch = va_arg(ap, long);
  else
    ch = (uint32_t)va_arg(ap, int);
  char var[specs.width > 16 ? specs.width : 16];
  if (ch != 0 || specs.accur) {
    do {
      uint32_t mask = ch & ch_mask;
      if (mask < 10)
        var[i] = (char)(mask + 48);
      else if (mask >= 10 && mask <= 15)
        var[i] = specs.spec_X ? (char)(mask + 55) : (char)(mask + 87);
      ch = ch >> 4;
      i++;
      counter++;
    } while (ch > 0);
  }
  int shift = specs.spec_sharp ? 2 : 0;
  if (specs.spec_zero && !specs.spec_minus)
    for (; i < specs.width - shift; i++)  // -2 для 0х
      var[i] = '0';
  for (; i < specs.accur; i++) var[i] = '0';
  if (specs.spec_sharp) {
    var[i++] = specs.spec_X ? 'X' : 'x';
    var[i++] = '0';
  }
  if (!specs.spec_minus)
    for (; i < specs.width; i++) var[i] = ' ';
  for (i--; i >= 0; i--) {
    **str = var[i];
    (*str)++;
  }
  if (specs.spec_minus) {
    char var_for_spaces[specs.width];
    int j = 0;
    if (specs.spec_minus && specs.width > counter + shift) {
      for (; j < specs.width - (counter > specs.accur ? counter : specs.accur) -
                     shift;
           j++)
        var_for_spaces[j] = ' ';
      for (j--; j >= 0; j--) {
        **str = var_for_spaces[j];
        (*str)++;
      }
    }
  }
  (*str)--;
}

void spec_o(va_list ap, char **str, Specs specs) {
  uint64_t ch_mask = 7;
  uint64_t o_ch = 0;
  int counter = 0, i = 0;

  if (specs.spec_short_int)
    o_ch = (uint16_t)va_arg(ap, int);
  else if (specs.spec_long_int)
    o_ch = va_arg(ap, long int);
  else
    o_ch = (uint32_t)va_arg(ap, int);
  char var[22];
  if (o_ch != 0 || specs.accur) {
    do {
      uint32_t mask = o_ch & ch_mask;
      var[i] = (char)(mask + 48);
      o_ch >>= 3;
      i++;
      counter++;
    } while (o_ch > 0);
  }
  int shift = specs.spec_sharp ? 1 : 0;
  if (specs.spec_zero && !specs.spec_minus)
    for (; i < specs.width - shift; i++) var[i] = '0';
  for (; i < specs.accur - shift; i++) var[i] = '0';
  if (specs.spec_sharp) var[i++] = '0';
  if (!specs.spec_minus)
    for (; i < specs.width; i++) var[i] = ' ';
  for (i--; i >= 0; i--) {
    **str = var[i];
    (*str)++;
  }
  if (specs.spec_minus) {
    char var_for_spaces[specs.width];
    int j = 0;
    if (specs.spec_minus && specs.width > counter + shift) {
      for (; j < specs.width - (counter > specs.accur ? counter : specs.accur) -
                     shift;
           j++)
        var_for_spaces[j] = ' ';
      j--;
    }
    for (; j >= 0; j--) {
      **str = var_for_spaces[j];
      (*str)++;
    }
  }
  (*str)--;
}

void spec_p(va_list ap, char **str, Specs specs) {
  specs.spec_sharp = true;
  specs.spec_long_int = true;
  specs.spec_short_int = false;
  spec_x(ap, str, specs);
}

void spec_n(va_list ap, char *str, char *tmp_str) {
  int *ch = va_arg(ap, int *);
  *ch = tmp_str - str;
}

void spaces_with_minus_for_specs_e_g(char **str, Specs specs, int sign,
                                     int deleted_zeros) {
  for (int j = 0; j < specs.width - specs.accur - 5 - sign + deleted_zeros;
       j++) {
    **str = ' ';
    (*str)++;
  }
}

int number_to_char_mass_for_g(long long full_ch, Specs specs, char *var, int i,
                              int *deleted_zeros, int shift_for_counter,
                              int point) {
  for (int j = i, del = 0, zero = 0; j < specs.accur + shift_for_counter; j++) {
    del = full_ch % 10;
    if (del != 0 || !point) zero = 1;
    if (!zero) (*deleted_zeros)++;
    if (zero) var[i++] = (char)(del + 48);
    full_ch /= 10;
  }
  return i;
}
