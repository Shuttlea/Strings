#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "s21_string.h"

typedef struct {
  bool percent;
  bool spec_plus;
  bool spec_minus;
  bool spec_space;
  bool spec_zero;
  bool spec_short_int;
  bool spec_long_int;
  bool spec_long_double;
  bool star_before_point;
  bool star_after_point;
  bool number_sign;
  bool point;
  bool spec_E;
  bool spec_G;
  bool spec_X;
  bool spec_sharp;
  int accur;
  int width;
  int format_shift;
  int str_shift;
} Specs;

int s21_sprintf(char *str, const char *format, ...);

int parcer(Specs *specs, const char *format, va_list ap);

void spec_c(va_list ap, char *str, Specs specs);
void spec_d(va_list ap, char **str, Specs specs);
void spec_s(va_list ap, char **str, Specs specs);
void spec_f(va_list ap, char **str, Specs specs);
void spec_e(va_list ap, char **str, Specs specs);
void spec_g(va_list ap, char **str, Specs specs);
void spec_x(va_list ap, char **str, Specs specs);
void spec_o(va_list ap, char **str, Specs specs);
void spec_p(va_list ap, char **str, Specs specs);
void spec_n(va_list ap, char *str, char *tmp_str);
void spec_u(va_list ap, char **str, Specs specs);
void spec_e_not_zero(long double ch, char **str, Specs specs, int negative,
                     int sign);
void spec_e_zero(char **str, Specs specs, int negative, int sign);

void spec_g_for_num_less_one(long double ch, char **str, Specs specs,
                             int negative, int sign);
void spec_g_num_less_one_sci_not(long long full_ch, char **str, Specs specs,
                                 int negative, int sign, int exp_counter);
void spec_g_for_num_more_one(long double ch, char **str, Specs specs,
                             int negative, int sign);
void spec_g_for_num_more_one_if_int_part_bigger_accur(long double ch,
                                                      char **str, Specs specs,
                                                      int negative, int sign,
                                                      int exp_counter);
void spec_g_zero(char **str, Specs specs, int negative, int sign);

void spaces_with_minus(char **str, char *var_for_spaces, Specs specs,
                       int counter_for_minus);
void spaces_with_minus_for_specs_e_g(char **str, Specs specs, int sign,
                                     int deleted_zeros);

void s21_atoi_before_point(Specs *specs, char *num);
void s21_atoi_after_point(Specs *specs, char *num);

int number_to_char_mass(long long full_ch, Specs specs, char *var, int i,
                        int shift_for_counter);
int number_to_char_mass_for_g(long long full_ch, Specs specs, char *var, int i,
                              int *deleted_zeros, int shift_for_counter,
                              int point);

int formatwalk(char format);
void zeroid(Specs *specs);
int num_extractor(Specs *specs, const char *format);
void width_and_accur_from_arg(Specs *specs, va_list ap);
char sign_token(int negative, Specs specs);
int writting_exp(char *var, int i, int exp_counter);

#endif