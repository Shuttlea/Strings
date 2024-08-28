#include "s21_string_tests.h"

START_TEST(sprintf_spec_E_1) {
  char str[50], s21_str[50];
  char *format = "|%E|";
  float num = 10.76;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_E_2) {
  char str[50], s21_str[50];
  char *format = "|%7E|";
  float num = 54.898;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_E_3) {
  char str[50], s21_str[50];
  char *format = "|%6.3E|";
  float num = -45.648;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_E_4) {
  char str[50], s21_str[50];
  char *format = "|%1.7E|";
  float num = 98.534;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_E_5) {
  char str[50], s21_str[50];
  char *format = "|%-2.10E|";
  float num = 7.16;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_E_6) {
  char str[50], s21_str[50];
  char *format = "|%.10E|";
  float num = 7.62;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_E_7) {
  char str[50], s21_str[50];
  char *format = "|%.5E|";
  float num = -122.9;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_E_8) {
  char str[50], s21_str[50];
  char *format = "|% 7E|";
  float num = 256.01;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_E_9) {
  char str[50], s21_str[50];
  char *format = "|%+4E|";
  float num = 1.12;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_E_10) {
  char str[50], s21_str[50];
  char *format = "|%3E|";
  float num = 1245.001;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_E_11) {
  char str[50], s21_str[50];
  char *format = "|%11.11E|";
  float num = -1245.045645601;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_E_12) {
  char str[50], s21_str[50];
  char *format = "|%11.0E|";
  float num = 21.11;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_E_13) {
  char str[50], s21_str[50];
  char *format = "|%9.9E|";
  float num = 888.22;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_E_14) {
  char str[50], s21_str[50];
  char *format = "|%-8.8E|";
  float num = 4617.235;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_E_15) {
  char str[50], s21_str[50];
  char *format = "|%.0E|";
  float num = 77.99;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_E_16) {
  char str[50], s21_str[50];
  char *format = "|%-5.1E|";
  float num = 116.43;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_E_17) {
  char str[50], s21_str[50];
  char *format = "|%010E|";
  float num = -75.36;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_E_18) {
  char str[50], s21_str[50];
  char *format = "|%#E|";
  float num = 116.0;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_E_19) {
  char str[50], s21_str[50];
  char *format = "|%*E|";
  float x = 82.175;
  int star = 10;
  ck_assert_int_eq(sprintf(str, format, star, x),
                   s21_sprintf(s21_str, format, star, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_E_20) {
  char str[50], s21_str[50];
  char *format = "|%5.*E|";
  float x = -981.956;
  int star = 3;
  ck_assert_int_eq(sprintf(str, format, star, x),
                   s21_sprintf(s21_str, format, star, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_E_21) {
  char str[100], s21_str[100];
  char *format = "|%5.1E| |%3.8E| |%4E| |%-5E| |%08E| |% E|";
  float x1 = -981.05, x2 = 67.65, x3 = -56.3, x4 = 3.13, x5 = -167.01,
        x6 = 0.0001;
  ck_assert_int_eq(sprintf(str, format, x1, x2, x3, x4, x5, x6),
                   s21_sprintf(s21_str, format, x1, x2, x3, x4, x5, x6));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

Suite *test_sprintf_spec_E() {
  Suite *test_set = suite_create("s21_sprintf_spec_E");
  TCase *test_group = tcase_create("spec_E");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, sprintf_spec_E_1);
  tcase_add_test(test_group, sprintf_spec_E_2);
  tcase_add_test(test_group, sprintf_spec_E_3);
  tcase_add_test(test_group, sprintf_spec_E_4);
  tcase_add_test(test_group, sprintf_spec_E_5);
  tcase_add_test(test_group, sprintf_spec_E_6);
  tcase_add_test(test_group, sprintf_spec_E_7);
  tcase_add_test(test_group, sprintf_spec_E_8);
  tcase_add_test(test_group, sprintf_spec_E_9);
  tcase_add_test(test_group, sprintf_spec_E_10);
  tcase_add_test(test_group, sprintf_spec_E_11);
  tcase_add_test(test_group, sprintf_spec_E_12);
  tcase_add_test(test_group, sprintf_spec_E_13);
  tcase_add_test(test_group, sprintf_spec_E_14);
  tcase_add_test(test_group, sprintf_spec_E_15);
  tcase_add_test(test_group, sprintf_spec_E_16);
  tcase_add_test(test_group, sprintf_spec_E_17);
  tcase_add_test(test_group, sprintf_spec_E_18);
  tcase_add_test(test_group, sprintf_spec_E_19);
  tcase_add_test(test_group, sprintf_spec_E_20);
  tcase_add_test(test_group, sprintf_spec_E_21);

  return test_set;
}
