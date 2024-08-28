#include "s21_string_tests.h"

START_TEST(scanf_spec_g_1) {
  char *str = "12.3";
  char *format = "%g";
  float x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_float_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_g_2) {
  char *str = "5e-3";
  char *format = "%5g";
  float x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_float_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_g_3) {
  char *str = "0.007";
  char *format = "%*g";
  ck_assert_int_eq(sscanf(str, format), s21_sscanf(str, format));
}
END_TEST

START_TEST(scanf_spec_g_4) {
  char *str = "-7e20";
  char *format = "%Lg";
  long double x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_ldouble_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_g_5) {
  char *str = "23.711 44e3 999999.987664";
  char *format = "%g %6g %Lg";
  float x1, x2, s21_x1, s21_x2;
  long double x3, s21_x3;
  ck_assert_int_eq(sscanf(str, format, &x1, &x2, &x3),
                   s21_sscanf(str, format, &s21_x1, &s21_x2, &s21_x3));
  ck_assert_float_eq(x1, s21_x1);
  ck_assert_float_eq(x2, s21_x2);
  ck_assert_ldouble_eq(x3, s21_x3);
}
END_TEST

Suite *test_scanf_spec_g() {
  Suite *test_set = suite_create("s21_scanf_spec_g");
  TCase *test_group = tcase_create("spec_g");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, scanf_spec_g_1);
  tcase_add_test(test_group, scanf_spec_g_2);
  tcase_add_test(test_group, scanf_spec_g_3);
  tcase_add_test(test_group, scanf_spec_g_4);
  tcase_add_test(test_group, scanf_spec_g_5);

  return test_set;
}
