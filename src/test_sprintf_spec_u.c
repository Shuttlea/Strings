#include "s21_string_tests.h"

START_TEST(sprintf_spec_u_1) {
  char str[50], s21_str[50];
  char *format = "|%u|";
  unsigned x = 100;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_u_2) {
  char str[50], s21_str[50];
  char *format = "|%10u|";
  unsigned x = -65;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_u_3) {
  char str[50], s21_str[50];
  char *format = "|%-8u|";
  unsigned x = 130;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_u_4) {
  char str[50], s21_str[50];
  char *format = "|%+u|";
  unsigned x = 121;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_u_5) {
  char str[50], s21_str[50];
  char *format = "|% u|";
  unsigned x = 77;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_u_6) {
  char str[50], s21_str[50];
  char *format = "|%05u|";
  unsigned x = -25;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_u_7) {
  char str[50], s21_str[50];
  char *format = "|%.5u|";
  unsigned x = 69;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_u_8) {
  char str[50], s21_str[50];
  char *format = "|%.3u|";
  unsigned x = -1459;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_u_9) {
  char str[50], s21_str[50];
  char *format = "|%hu|";
  unsigned short x = 55;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_u_10) {
  char str[50], s21_str[50];
  char *format = "|%lu|";
  unsigned long x = 55;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_u_11) {
  char str[50], s21_str[50];
  char *format = "|%5.3u|";
  unsigned x = 2165;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_u_12) {
  char str[50], s21_str[50];
  char *format = "|%3.7u|";
  unsigned x = 17899;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_u_13) {
  char str[50], s21_str[50];
  char *format = "|%-10.2u|";
  unsigned x = 45987;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_u_14) {
  char str[50], s21_str[50];
  char *format = "|%*.3u|";
  unsigned x = -17;
  int star = 8;
  ck_assert_int_eq(sprintf(str, format, star, x),
                   s21_sprintf(s21_str, format, star, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_u_15) {
  char str[50], s21_str[50];
  char *format = "|%3.*u|";
  unsigned x = 56879;
  int star = 2;
  ck_assert_int_eq(sprintf(str, format, star, x),
                   s21_sprintf(s21_str, format, star, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_u_16) {
  char str[50], s21_str[50];
  char *format = "|%lu|";
  unsigned long x = -879;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_u_17) {
  char str[50], s21_str[50];
  char *format = "|%0.0u|";
  int x = -879;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_u_18) {
  char str[50], s21_str[50];
  char *format = "|%0.0u|";
  int x = 0;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

Suite *test_sprintf_spec_u() {
  Suite *test_set = suite_create("s21_sprintf_spec_u");
  TCase *test_group = tcase_create("spec_u");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, sprintf_spec_u_1);
  tcase_add_test(test_group, sprintf_spec_u_2);
  tcase_add_test(test_group, sprintf_spec_u_3);
  tcase_add_test(test_group, sprintf_spec_u_4);
  tcase_add_test(test_group, sprintf_spec_u_5);
  tcase_add_test(test_group, sprintf_spec_u_6);
  tcase_add_test(test_group, sprintf_spec_u_7);
  tcase_add_test(test_group, sprintf_spec_u_8);
  tcase_add_test(test_group, sprintf_spec_u_9);
  tcase_add_test(test_group, sprintf_spec_u_10);
  tcase_add_test(test_group, sprintf_spec_u_11);
  tcase_add_test(test_group, sprintf_spec_u_12);
  tcase_add_test(test_group, sprintf_spec_u_13);
  tcase_add_test(test_group, sprintf_spec_u_14);
  tcase_add_test(test_group, sprintf_spec_u_15);
  tcase_add_test(test_group, sprintf_spec_u_16);
  tcase_add_test(test_group, sprintf_spec_u_17);
  tcase_add_test(test_group, sprintf_spec_u_18);

  return test_set;
}
