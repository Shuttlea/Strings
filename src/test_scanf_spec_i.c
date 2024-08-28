#include "s21_string_tests.h"

START_TEST(scanf_spec_i_1) {
  char *str = "123";
  char *format = "%i";
  int x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_int_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_i_2) {
  char *str = "0xABC";
  char *format = "%5i";
  int x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_int_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_i_3) {
  char *str = "461";
  char *format = "%*i";
  ck_assert_int_eq(sscanf(str, format), s21_sscanf(str, format));
}
END_TEST

START_TEST(scanf_spec_i_4) {
  char *str = "-013";
  char *format = "%hi";
  short x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_int_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_i_5) {
  char *str = "-0xFFFFFFFFF";
  char *format = "%li";
  long x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_int_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_i_6) {
  char *str = "101023711 044567 0xB";
  char *format = "%i %6i %hi";
  int x1, x2, s21_x1, s21_x2;
  short x3, s21_x3;
  ck_assert_int_eq(sscanf(str, format, &x1, &x2, &x3),
                   s21_sscanf(str, format, &s21_x1, &s21_x2, &s21_x3));
  ck_assert_int_eq(x1, s21_x1);
  ck_assert_int_eq(x2, s21_x2);
  ck_assert_int_eq(x3, s21_x3);
}
END_TEST

Suite *test_scanf_spec_i() {
  Suite *test_set = suite_create("s21_scanf_spec_i");
  TCase *test_group = tcase_create("spec_i");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, scanf_spec_i_1);
  tcase_add_test(test_group, scanf_spec_i_2);
  tcase_add_test(test_group, scanf_spec_i_3);
  tcase_add_test(test_group, scanf_spec_i_4);
  tcase_add_test(test_group, scanf_spec_i_5);
  tcase_add_test(test_group, scanf_spec_i_6);

  return test_set;
}
