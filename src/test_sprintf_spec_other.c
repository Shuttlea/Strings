#include "s21_string_tests.h"

START_TEST(sprintf_spec_other_1) {
  char str[50], s21_str[50];
  char *format = "100 100 %n 100";
  int num = 0, s21_num = 0;
  ck_assert_int_eq(sprintf(str, format, &num),
                   s21_sprintf(s21_str, format, &s21_num));
  ck_assert_int_eq(num, s21_num);
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_other_2) {
  char str[50], s21_str[50];
  char *format = "100 100 %%";
  ck_assert_int_eq(sprintf(str, format), s21_sprintf(s21_str, format));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

Suite *test_sprintf_spec_other() {
  Suite *test_set = suite_create("s21_sprintf_spec_other");
  TCase *test_group = tcase_create("spec_other");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, sprintf_spec_other_1);
  tcase_add_test(test_group, sprintf_spec_other_2);

  return test_set;
}
