#include "s21_string_tests.h"

START_TEST(sprintf_spec_o_1) {
  char str[50], s21_str[50];
  char *format = "|%o|";
  int x = 100;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_o_2) {
  char str[50], s21_str[50];
  char *format = "|%10o|";
  int x = -65;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_o_3) {
  char str[50], s21_str[50];
  char *format = "|%-8o|";
  int x = 130;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_o_4) {
  char str[50], s21_str[50];
  char *format = "|%+o|";
  int x = 121;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_o_5) {
  char str[50], s21_str[50];
  char *format = "|% o|";
  int x = 77;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_o_6) {
  char str[50], s21_str[50];
  char *format = "|%05o|";
  int x = -25;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_o_7) {
  char str[50], s21_str[50];
  char *format = "|%.5o|";
  int x = 69;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_o_8) {
  char str[50], s21_str[50];
  char *format = "|%.3o|";
  int x = -1459;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_o_9) {
  char str[50], s21_str[50];
  char *format = "|%ho|";
  unsigned short x = 55;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_o_10) {
  char str[50], s21_str[50];
  char *format = "|%lo|";
  long x = 55;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_o_11) {
  char str[50], s21_str[50];
  char *format = "|%5.3o|";
  int x = 2165;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_o_12) {
  char str[50], s21_str[50];
  char *format = "|%3.7o|";
  int x = 17899;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_o_13) {
  char str[50], s21_str[50];
  char *format = "|%-10.2o|";
  int x = 45987;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_o_14) {
  char str[50], s21_str[50];
  char *format = "|%*.3o|";
  int x = -17;
  int star = 8;
  ck_assert_int_eq(sprintf(str, format, star, x),
                   s21_sprintf(s21_str, format, star, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_o_15) {
  char str[50], s21_str[50];
  char *format = "|%3.*o|";
  int x = 56879;
  int star = 2;
  ck_assert_int_eq(sprintf(str, format, star, x),
                   s21_sprintf(s21_str, format, star, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_o_16) {
  char str[50], s21_str[50];
  char *format = "|%0.0o|";
  int x = 45987;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_o_17) {
  char str[50], s21_str[50];
  char *format = "|%0.0o|";
  int x = 0;
  ck_assert_int_eq(sprintf(str, format, x), s21_sprintf(s21_str, format, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

Suite *test_sprintf_spec_o() {
  Suite *test_set = suite_create("s21_sprintf_spec_o");
  TCase *test_group = tcase_create("spec_o");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, sprintf_spec_o_1);
  tcase_add_test(test_group, sprintf_spec_o_2);
  tcase_add_test(test_group, sprintf_spec_o_3);
  tcase_add_test(test_group, sprintf_spec_o_4);
  tcase_add_test(test_group, sprintf_spec_o_5);
  tcase_add_test(test_group, sprintf_spec_o_6);
  tcase_add_test(test_group, sprintf_spec_o_7);
  tcase_add_test(test_group, sprintf_spec_o_8);
  tcase_add_test(test_group, sprintf_spec_o_9);
  tcase_add_test(test_group, sprintf_spec_o_10);
  tcase_add_test(test_group, sprintf_spec_o_11);
  tcase_add_test(test_group, sprintf_spec_o_12);
  tcase_add_test(test_group, sprintf_spec_o_13);
  tcase_add_test(test_group, sprintf_spec_o_14);
  tcase_add_test(test_group, sprintf_spec_o_15);
  tcase_add_test(test_group, sprintf_spec_o_16);
  tcase_add_test(test_group, sprintf_spec_o_17);
  return test_set;
}
