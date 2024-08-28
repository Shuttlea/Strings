#include "s21_string_tests.h"

START_TEST(sprintf_spec_x_1) {
  char str[50], s21_str[50];
  char *format = "|%x|";
  int x = 100;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_x_2) {
  char str[50], s21_str[50];
  char *format = "|%10x|";
  int x = -65;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_x_3) {
  char str[50], s21_str[50];
  char *format = "|%-8x|";
  int x = 130;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_x_4) {
  char str[50], s21_str[50];
  char *format = "|%+x|";
  int x = 121;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_x_5) {
  char str[50], s21_str[50];
  char *format = "|% x|";
  int x = 77;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_x_6) {
  char str[50], s21_str[50];
  char *format = "|%05x|";
  int x = -25;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_x_7) {
  char str[50], s21_str[50];
  char *format = "|%.5x|";
  int x = 69;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_x_8) {
  char str[50], s21_str[50];
  char *format = "|%.3x|";
  int x = -1459;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_x_9) {
  char str[50], s21_str[50];
  char *format = "|%hx|";
  unsigned short x = 55;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_x_10) {
  char str[50], s21_str[50];
  char *format = "|%lx|";
  long x = 55;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_x_11) {
  char str[50], s21_str[50];
  char *format = "|%5.3x|";
  int x = 2165;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_x_12) {
  char str[50], s21_str[50];
  char *format = "|%3.7x|";
  int x = 17899;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_x_13) {
  char str[50], s21_str[50];
  char *format = "|%-10.2x|";
  int x = 45987;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_x_14) {
  char str[50], s21_str[50];
  char *format = "|%*.3x|";
  int x = -17;
  int star = 8;
  ck_assert_int_eq(sprintf(str, format, star, x),
                   s21_sprintf(s21_str, format, star, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_x_15) {
  char str[50], s21_str[50];
  char *format = "|%3.*x|";
  int x = 56879;
  int star = 2;
  ck_assert_int_eq(sprintf(str, format, star, x),
                   s21_sprintf(s21_str, format, star, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_x_16) {
  char str[50], s21_str[50];
  char *format = "|%-0.0x|";
  int x = 45987;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_x_17) {
  char str[50], s21_str[50];
  char *format = "|%-0.0x|";
  int x = 0;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

Suite *test_sprintf_spec_x() {
  Suite *test_set = suite_create("s21_sprintf_spec_x");
  TCase *test_group = tcase_create("spec_x");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, sprintf_spec_x_1);
  tcase_add_test(test_group, sprintf_spec_x_2);
  tcase_add_test(test_group, sprintf_spec_x_3);
  tcase_add_test(test_group, sprintf_spec_x_4);
  tcase_add_test(test_group, sprintf_spec_x_5);
  tcase_add_test(test_group, sprintf_spec_x_6);
  tcase_add_test(test_group, sprintf_spec_x_7);
  tcase_add_test(test_group, sprintf_spec_x_8);
  tcase_add_test(test_group, sprintf_spec_x_9);
  tcase_add_test(test_group, sprintf_spec_x_10);
  tcase_add_test(test_group, sprintf_spec_x_11);
  tcase_add_test(test_group, sprintf_spec_x_12);
  tcase_add_test(test_group, sprintf_spec_x_13);
  tcase_add_test(test_group, sprintf_spec_x_14);
  tcase_add_test(test_group, sprintf_spec_x_15);
  tcase_add_test(test_group, sprintf_spec_x_16);
  tcase_add_test(test_group, sprintf_spec_x_17);

  return test_set;
}
