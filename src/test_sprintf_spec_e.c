#include "s21_string_tests.h"

START_TEST(sprintf_spec_e_1) {
  char str[50], s21_str[50];
  char *format = "|%e|";
  float num = 10.76;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_2) {
  char str[50], s21_str[50];
  char *format = "|%7e|";
  float num = 54.898;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_3) {
  char str[50], s21_str[50];
  char *format = "|%6.3e|";
  float num = -45.648;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_4) {
  char str[50], s21_str[50];
  char *format = "|%1.7e|";
  float num = 98.534;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_5) {
  char str[50], s21_str[50];
  char *format = "|%-2.10e|";
  float num = 7.16;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_6) {
  char str[50], s21_str[50];
  char *format = "|%.10e|";
  float num = 7.62;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_7) {
  char str[50], s21_str[50];
  char *format = "|%.5e|";
  float num = -122.9;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_8) {
  char str[50], s21_str[50];
  char *format = "|% 7e|";
  float num = 256.01;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_9) {
  char str[50], s21_str[50];
  char *format = "|%+4e|";
  float num = 1.12;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_10) {
  char str[50], s21_str[50];
  char *format = "|%3e|";
  float num = 1245.001;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_11) {
  char str[50], s21_str[50];
  char *format = "|%11.11e|";
  float num = -1245.045645601;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_12) {
  char str[50], s21_str[50];
  char *format = "|%11.0e|";
  float num = 21.11;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_13) {
  char str[50], s21_str[50];
  char *format = "|%9.9e|";
  float num = 888.22;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_14) {
  char str[50], s21_str[50];
  char *format = "|%-8.8e|";
  float num = 4617.235;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_15) {
  char str[50], s21_str[50];
  char *format = "|%.0e|";
  float num = 77.99;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_16) {
  char str[50], s21_str[50];
  char *format = "|%-5.1e|";
  float num = 116.43;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_17) {
  char str[50], s21_str[50];
  char *format = "|%010e|";
  float num = -75.36;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_18) {
  char str[50], s21_str[50];
  char *format = "|%#e|";
  float num = 116.0;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_19) {
  char str[50], s21_str[50];
  char *format = "|%*e|";
  float x = 82.175;
  int star = 10;
  ck_assert_int_eq(sprintf(str, format, star, x),
                   s21_sprintf(s21_str, format, star, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_20) {
  char str[50], s21_str[50];
  char *format = "|%5.*e|";
  float x = -981.956;
  int star = 3;
  ck_assert_int_eq(sprintf(str, format, star, x),
                   s21_sprintf(s21_str, format, star, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_21) {
  char str[100], s21_str[100];
  char *format = "|%5.1e| |%3.8e| |%4e| |%-5e| |%08e| |% e|";
  float x1 = -981.05, x2 = 67.65, x3 = -56.3, x4 = 3.13, x5 = -167.01,
        x6 = 0.0001;
  ck_assert_int_eq(sprintf(str, format, x1, x2, x3, x4, x5, x6),
                   s21_sprintf(s21_str, format, x1, x2, x3, x4, x5, x6));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_22) {
  char str[50], s21_str[50];
  char *format = "|%0e|";
  float num = 0.0;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_23) {
  char str[50], s21_str[50];
  char *format = "|%-0e|";
  float num = 0.0;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_24) {
  char str[50], s21_str[50];
  char *format = "|%-09.2e|";
  float num = 0.0;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_25) {
  char str[50], s21_str[50];
  char *format = "|%0.0e|";
  float num = 7127.9943;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_26) {
  char str[50], s21_str[50];
  char *format = "|%-0.0e|";
  float num = 0.0;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

Suite *test_sprintf_spec_e() {
  Suite *test_set = suite_create("s21_sprintf_spec_e");
  TCase *test_group = tcase_create("spec_e");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, sprintf_spec_e_1);
  tcase_add_test(test_group, sprintf_spec_e_2);
  tcase_add_test(test_group, sprintf_spec_e_3);
  tcase_add_test(test_group, sprintf_spec_e_4);
  tcase_add_test(test_group, sprintf_spec_e_5);
  tcase_add_test(test_group, sprintf_spec_e_6);
  tcase_add_test(test_group, sprintf_spec_e_7);
  tcase_add_test(test_group, sprintf_spec_e_8);
  tcase_add_test(test_group, sprintf_spec_e_9);
  tcase_add_test(test_group, sprintf_spec_e_10);
  tcase_add_test(test_group, sprintf_spec_e_11);
  tcase_add_test(test_group, sprintf_spec_e_12);
  tcase_add_test(test_group, sprintf_spec_e_13);
  tcase_add_test(test_group, sprintf_spec_e_14);
  tcase_add_test(test_group, sprintf_spec_e_15);
  tcase_add_test(test_group, sprintf_spec_e_16);
  tcase_add_test(test_group, sprintf_spec_e_17);
  tcase_add_test(test_group, sprintf_spec_e_18);
  tcase_add_test(test_group, sprintf_spec_e_19);
  tcase_add_test(test_group, sprintf_spec_e_20);
  tcase_add_test(test_group, sprintf_spec_e_21);
  tcase_add_test(test_group, sprintf_spec_e_22);
  tcase_add_test(test_group, sprintf_spec_e_23);
  tcase_add_test(test_group, sprintf_spec_e_24);
  tcase_add_test(test_group, sprintf_spec_e_25);
  tcase_add_test(test_group, sprintf_spec_e_26);

  return test_set;
}
