#include "s21_string_tests.h"

START_TEST(scanf_spec_E_1) {
  char *str = "12.3";
  char *format = "%E";
  float x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_float_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_E_2) {
  char *str = "5E-3";
  char *format = "%5E";
  float x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_float_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_E_3) {
  char *str = "0.007";
  char *format = "%*E";
  ck_assert_int_eq(sscanf(str, format), s21_sscanf(str, format));
}
END_TEST

START_TEST(scanf_spec_E_4) {
  char *str = "-7E20";
  char *format = "%LE";
  long double x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_ldouble_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_E_5) {
  char *str = "23.711 44E3 999999.987664";
  char *format = "%E %6E %LE";
  float x1, x2, s21_x1, s21_x2;
  long double x3, s21_x3;
  ck_assert_int_eq(sscanf(str, format, &x1, &x2, &x3),
                   s21_sscanf(str, format, &s21_x1, &s21_x2, &s21_x3));
  ck_assert_float_eq(x1, s21_x1);
  ck_assert_float_eq(x2, s21_x2);
  ck_assert_ldouble_eq(x3, s21_x3);
}
END_TEST

Suite *test_scanf_spec_E() {
  Suite *test_set = suite_create("s21_scanf_spec_E");
  TCase *test_group = tcase_create("spec_E");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, scanf_spec_E_1);
  tcase_add_test(test_group, scanf_spec_E_2);
  tcase_add_test(test_group, scanf_spec_E_3);
  tcase_add_test(test_group, scanf_spec_E_4);
  tcase_add_test(test_group, scanf_spec_E_5);

  return test_set;
}
