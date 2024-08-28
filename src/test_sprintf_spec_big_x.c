#include "s21_string_tests.h"

START_TEST(sprintf_spec_X_1) {
  char str[50], s21_str[50];
  char *format = "|%X|";
  int x = 100;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_X_2) {
  char str[50], s21_str[50];
  char *format = "|%10X|";
  int x = -65;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_X_3) {
  char str[50], s21_str[50];
  char *format = "|%-8X|";
  int x = 130;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_X_4) {
  char str[50], s21_str[50];
  char *format = "|%+X|";
  int x = 121;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_X_5) {
  char str[50], s21_str[50];
  char *format = "|% X|";
  int x = 77;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_X_6) {
  char str[50], s21_str[50];
  char *format = "|%05X|";
  int x = -25;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_X_7) {
  char str[50], s21_str[50];
  char *format = "|%.5X|";
  int x = 69;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_X_8) {
  char str[50], s21_str[50];
  char *format = "|%.3X|";
  int x = -1459;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_X_9) {
  char str[50], s21_str[50];
  char *format = "|%hX|";
  unsigned short x = 55;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_X_10) {
  char str[50], s21_str[50];
  char *format = "|%lX|";
  long x = 55;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_X_11) {
  char str[50], s21_str[50];
  char *format = "|%5.3X|";
  int x = 2165;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_X_12) {
  char str[50], s21_str[50];
  char *format = "|%3.7X|";
  int x = 17899;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_X_13) {
  char str[50], s21_str[50];
  char *format = "|%-10.2X|";
  int x = 45987;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_X_14) {
  char str[50], s21_str[50];
  char *format = "|%*.3X|";
  int x = -17;
  int star = 8;
  ck_assert_int_eq(sprintf(str, format, star, x),
                   s21_sprintf(s21_str, format, star, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_X_15) {
  char str[50], s21_str[50];
  char *format = "|%3.*X|";
  int x = 56879;
  int star = 2;
  ck_assert_int_eq(sprintf(str, format, star, x),
                   s21_sprintf(s21_str, format, star, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

Suite *test_sprintf_spec_X() {
  Suite *test_set = suite_create("s21_sprintf_spec_X");
  TCase *test_group = tcase_create("spec_X");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, sprintf_spec_X_1);
  tcase_add_test(test_group, sprintf_spec_X_2);
  tcase_add_test(test_group, sprintf_spec_X_3);
  tcase_add_test(test_group, sprintf_spec_X_4);
  tcase_add_test(test_group, sprintf_spec_X_5);
  tcase_add_test(test_group, sprintf_spec_X_6);
  tcase_add_test(test_group, sprintf_spec_X_7);
  tcase_add_test(test_group, sprintf_spec_X_8);
  tcase_add_test(test_group, sprintf_spec_X_9);
  tcase_add_test(test_group, sprintf_spec_X_10);
  tcase_add_test(test_group, sprintf_spec_X_11);
  tcase_add_test(test_group, sprintf_spec_X_12);
  tcase_add_test(test_group, sprintf_spec_X_13);
  tcase_add_test(test_group, sprintf_spec_X_14);
  tcase_add_test(test_group, sprintf_spec_X_15);

  return test_set;
}
