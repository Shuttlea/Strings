#ifndef S21_SCANF_H
#define S21_SCANF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

#define BUF 500

struct rd_frm {
  int save;
  s21_size_t width;
  char lenth;
  int base;
};

int s21_isspace(char c);
int s21_sscanf(const char *str, const char *format, ...);
void read(s21_size_t *i, s21_size_t *j, const char *str, const char *format,
          va_list va, int *res);
void ReadFormatReload(struct rd_frm *read_format);
void ScanInt(va_list va, struct rd_frm *read_format, const char *str,
             s21_size_t *j, int *res);
void ScanUnSignInt(va_list va, struct rd_frm *read_format, const char *str,
                   s21_size_t *j, int *res);
void ScanDouble(va_list va, struct rd_frm *read_format, const char *str,
                s21_size_t *j, int *res);
void ScanString(va_list va, struct rd_frm *read_format, const char *str,
                s21_size_t *j, int *res);

#endif
