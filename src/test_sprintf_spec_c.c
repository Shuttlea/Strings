#include "s21_string_tests.h"

START_TEST(sprintf_spec_c_1) {
  char str[50], s21_str[50];
  char *format = "|%c|";
  char c = 'w';
  ck_assert_int_eq(sprintf(str, format, c), s21_sprintf(s21_str, format, c));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_c_2) {
  char str[50], s21_str[50];
  char *format = "|%5c|";
  char c = 'Z';
  ck_assert_int_eq(sprintf(str, format, c), s21_sprintf(s21_str, format, c));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_c_3) {
  char str[50], s21_str[50];
  char *format = "|%-4c|";
  char c = 'q';
  ck_assert_int_eq(sprintf(str, format, c), s21_sprintf(s21_str, format, c));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_c_4) {
  char str[50], s21_str[50];
  char *format = "|%4c|";
  char c = 'g';
  ck_assert_int_eq(sprintf(str, format, c), s21_sprintf(s21_str, format, c));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_c_5) {
  char str[50], s21_str[50];
  char *format = "|% 4c|";
  char c = 'v';
  ck_assert_int_eq(sprintf(str, format, c), s21_sprintf(s21_str, format, c));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_c_6) {
  char str[50], s21_str[50];
  char *format = "|%-05c|";
  char c = 'n';
  ck_assert_int_eq(sprintf(str, format, c), s21_sprintf(s21_str, format, c));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_c_7) {
  char str[50], s21_str[50];
  char *format = "|%.8c|";
  char c = 'P';
  ck_assert_int_eq(sprintf(str, format, c), s21_sprintf(s21_str, format, c));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_c_8) {
  char str[50], s21_str[50];
  char *format = "|%*c|";
  char c = 'a';
  int star = 10;
  ck_assert_int_eq(sprintf(str, format, star, c),
                   s21_sprintf(s21_str, format, star, c));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_c_9) {
  char str[50], s21_str[50];
  char *format = "|%8lc|";
  unsigned long c = 'f';
  ck_assert_int_eq(sprintf(str, format, c), s21_sprintf(s21_str, format, c));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_c_10) {
  char str[50], s21_str[50];
  char *format = "|%c| |%4c| |% 7c| |%-5c|";
  char c1 = 'a', c2 = 'b', c3 = 'c', c4 = 'd';
  ck_assert_int_eq(sprintf(str, format, c1, c2, c3, c4),
                   s21_sprintf(s21_str, format, c1, c2, c3, c4));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

Suite *test_sprintf_spec_c() {
  Suite *test_set = suite_create("s21_sprintf_spec_c");
  TCase *test_group = tcase_create("spec_c");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, sprintf_spec_c_1);
  tcase_add_test(test_group, sprintf_spec_c_2);
  tcase_add_test(test_group, sprintf_spec_c_3);
  tcase_add_test(test_group, sprintf_spec_c_4);
  tcase_add_test(test_group, sprintf_spec_c_5);
  tcase_add_test(test_group, sprintf_spec_c_6);
  tcase_add_test(test_group, sprintf_spec_c_7);
  tcase_add_test(test_group, sprintf_spec_c_8);
  tcase_add_test(test_group, sprintf_spec_c_9);
  tcase_add_test(test_group, sprintf_spec_c_10);

  return test_set;
}
