#include "s21_string_tests.h"

START_TEST(sprintf_spec_p_1) {
  char str[50], s21_str[50];
  char *format = "|%p|";
  int x = 100;
  ck_assert_int_eq(sprintf(str, format, &x), s21_sprintf(s21_str, format, &x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_p_2) {
  char str[50], s21_str[50];
  char *format = "|%10p|";
  int x = -65;
  ck_assert_int_eq(sprintf(str, format, &x), s21_sprintf(s21_str, format, &x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_p_3) {
  char str[50], s21_str[50];
  char *format = "|%-8p|";
  int x = 130;
  ck_assert_int_eq(sprintf(str, format, &x), s21_sprintf(s21_str, format, &x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_p_4) {
  char str[50], s21_str[50];
  char *format = "|%p|";
  int x = 121;
  ck_assert_int_eq(sprintf(str, format, &x), s21_sprintf(s21_str, format, &x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_p_5) {
  char str[50], s21_str[50];
  char *format = "|%p|";
  int x = 77;
  ck_assert_int_eq(sprintf(str, format, &x), s21_sprintf(s21_str, format, &x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_p_6) {
  char str[50], s21_str[50];
  char *format = "|%05p|";
  int x = -25;
  ck_assert_int_eq(sprintf(str, format, &x), s21_sprintf(s21_str, format, &x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_p_7) {
  char str[50], s21_str[50];
  char *format = "|%.5p|";
  int x = 69;
  ck_assert_int_eq(sprintf(str, format, &x), s21_sprintf(s21_str, format, &x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_p_8) {
  char str[50], s21_str[50];
  char *format = "|%.3p|";
  int x = -1459;
  ck_assert_int_eq(sprintf(str, format, &x), s21_sprintf(s21_str, format, &x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_p_9) {
  char str[50], s21_str[50];
  char *format = "|%hp|";
  short x = 55;
  ck_assert_int_eq(sprintf(str, format, &x), s21_sprintf(s21_str, format, &x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_p_10) {
  char str[50], s21_str[50];
  char *format = "|%lp|";
  long x = 55;
  ck_assert_int_eq(sprintf(str, format, &x), s21_sprintf(s21_str, format, &x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_p_11) {
  char str[50], s21_str[50];
  char *format = "|%5.3p|";
  int x = 2165;
  ck_assert_int_eq(sprintf(str, format, &x), s21_sprintf(s21_str, format, &x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_p_12) {
  char str[50], s21_str[50];
  char *format = "|%3.7p|";
  int x = 17899;
  ck_assert_int_eq(sprintf(str, format, &x), s21_sprintf(s21_str, format, &x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_p_13) {
  char str[50], s21_str[50];
  char *format = "|%-10.2p|";
  int x = 45987;
  ck_assert_int_eq(sprintf(str, format, &x), s21_sprintf(s21_str, format, &x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_p_14) {
  char str[50], s21_str[50];
  char *format = "|%*.3p|";
  int x = -17;
  int star = 8;
  ck_assert_int_eq(sprintf(str, format, star, &x),
                   s21_sprintf(s21_str, format, star, &x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_p_15) {
  char str[50], s21_str[50];
  char *format = "|%3.*p|";
  int x = 56879;
  int star = 2;
  ck_assert_int_eq(sprintf(str, format, star, &x),
                   s21_sprintf(s21_str, format, star, &x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

Suite *test_sprintf_spec_p() {
  Suite *test_set = suite_create("s21_sprintf_spec_p");
  TCase *test_group = tcase_create("spec_p");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, sprintf_spec_p_1);
  tcase_add_test(test_group, sprintf_spec_p_2);
  tcase_add_test(test_group, sprintf_spec_p_3);
  tcase_add_test(test_group, sprintf_spec_p_4);
  tcase_add_test(test_group, sprintf_spec_p_5);
  tcase_add_test(test_group, sprintf_spec_p_6);
  tcase_add_test(test_group, sprintf_spec_p_7);
  tcase_add_test(test_group, sprintf_spec_p_8);
  tcase_add_test(test_group, sprintf_spec_p_9);
  tcase_add_test(test_group, sprintf_spec_p_10);
  tcase_add_test(test_group, sprintf_spec_p_11);
  tcase_add_test(test_group, sprintf_spec_p_12);
  tcase_add_test(test_group, sprintf_spec_p_13);
  tcase_add_test(test_group, sprintf_spec_p_14);
  tcase_add_test(test_group, sprintf_spec_p_15);

  return test_set;
}
