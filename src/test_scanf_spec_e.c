#include "s21_string_tests.h"

START_TEST(scanf_spec_e_1) {
  char *str = "12.3";
  char *format = "%e";
  float x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_float_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_e_2) {
  char *str = "5e-3";
  char *format = "%5e";
  float x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_float_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_e_3) {
  char *str = "0.007";
  char *format = "%*e";
  ck_assert_int_eq(sscanf(str, format), s21_sscanf(str, format));
}
END_TEST

START_TEST(scanf_spec_e_4) {
  char *str = "-7e20";
  char *format = "%Le";
  long double x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_ldouble_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_e_5) {
  char *str = "23.711 44e3 999999.987664";
  char *format = "%e %6e %Le";
  float x1, x2, s21_x1, s21_x2;
  long double x3, s21_x3;
  ck_assert_int_eq(sscanf(str, format, &x1, &x2, &x3),
                   s21_sscanf(str, format, &s21_x1, &s21_x2, &s21_x3));
  ck_assert_float_eq(x1, s21_x1);
  ck_assert_float_eq(x2, s21_x2);
  ck_assert_ldouble_eq(x3, s21_x3);
}
END_TEST

START_TEST(scanf_spec_e_6) {
  char *str = "40e+13";
  char *format = "%le";
  double x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_double_eq(x, s21_x);
}
END_TEST

Suite *test_scanf_spec_e() {
  Suite *test_set = suite_create("s21_scanf_spec_e");
  TCase *test_group = tcase_create("spec_e");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, scanf_spec_e_1);
  tcase_add_test(test_group, scanf_spec_e_2);
  tcase_add_test(test_group, scanf_spec_e_3);
  tcase_add_test(test_group, scanf_spec_e_4);
  tcase_add_test(test_group, scanf_spec_e_5);
  tcase_add_test(test_group, scanf_spec_e_6);

  return test_set;
}
