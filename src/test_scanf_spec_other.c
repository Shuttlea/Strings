#include "s21_string_tests.h"

START_TEST(scanf_spec_other_1) {
  char *str = "str %n str";
  char *format = "%n";
  int x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_int_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec__other_2) {
  char *str = "%%";
  char *format = "%%";
  ck_assert_int_eq(sscanf(str, format), s21_sscanf(str, format));
}
END_TEST

Suite *test_scanf_spec_other() {
  Suite *test_set = suite_create("s21_scanf_spec_other");
  TCase *test_group = tcase_create("spec_other");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, scanf_spec_other_1);
  tcase_add_test(test_group, scanf_spec__other_2);

  return test_set;
}
