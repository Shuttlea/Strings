#include "s21_string_tests.h"

START_TEST(sprintf_spec_f_1) {
  char str[50], s21_str[50];
  char *format = "|%f|";
  float num = 10.76;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_f_2) {
  char str[50], s21_str[50];
  char *format = "|%7f|";
  float num = 54.898;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_f_3) {
  char str[50], s21_str[50];
  char *format = "|%6.3f|";
  float num = -45.648;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_f_4) {
  char str[50], s21_str[50];
  char *format = "|%1.7f|";
  float num = 98.534;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_f_5) {
  char str[50], s21_str[50];
  char *format = "|%-2.10f|";
  float num = 7.16;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_f_6) {
  char str[50], s21_str[50];
  char *format = "|%.10f|";
  float num = 7.62;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_f_7) {
  char str[50], s21_str[50];
  char *format = "|%.5f|";
  float num = -122.9;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_f_8) {
  char str[50], s21_str[50];
  char *format = "|% 7f|";
  float num = 256.01;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_f_9) {
  char str[50], s21_str[50];
  char *format = "|%+4f|";
  float num = 1.12;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_f_10) {
  char str[50], s21_str[50];
  char *format = "|%3f|";
  float num = 1245.001;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_f_11) {
  char str[50], s21_str[50];
  char *format = "|%11.11f|";
  float num = -1245.045645601;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_f_12) {
  char str[50], s21_str[50];
  char *format = "|%11.0f|";
  float num = 21.11;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_f_13) {
  char str[50], s21_str[50];
  char *format = "|%9.9f|";
  float num = 888.22;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_f_14) {
  char str[50], s21_str[50];
  char *format = "|%-8.8f|";
  float num = 4617.235;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_f_15) {
  char str[50], s21_str[50];
  char *format = "|%.0f|";
  float num = 77.99;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_f_16) {
  char str[50], s21_str[50];
  char *format = "|%-5.1f|";
  float num = 116.43;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_f_17) {
  char str[50], s21_str[50];
  char *format = "|%010f|";
  float num = -75.36;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_f_18) {
  char str[50], s21_str[50];
  char *format = "|%#f|";
  float num = 116.0;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_f_19) {
  char str[50], s21_str[50];
  char *format = "|%*f|";
  float x = 82.175;
  int star = 10;
  ck_assert_int_eq(sprintf(str, format, star, x),
                   s21_sprintf(s21_str, format, star, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_f_20) {
  char str[50], s21_str[50];
  char *format = "|%5.*f|";
  float x = -981.956;
  int star = 3;
  ck_assert_int_eq(sprintf(str, format, star, x),
                   s21_sprintf(s21_str, format, star, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_f_21) {
  char str[100], s21_str[100];
  char *format = "|%5.1f| |%3.8f| |%4f| |%-5f| |%08f| |% f| |%0.0f|";
  float x1 = -981.05, x2 = 67.65, x3 = -56.3, x4 = 3.13, x5 = -167.01,
        x6 = 0.0001, x7 = 0.0;
  ck_assert_int_eq(sprintf(str, format, x1, x2, x3, x4, x5, x6, x7),
                   s21_sprintf(s21_str, format, x1, x2, x3, x4, x5, x6, x7));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_f_22) {
  char str[50], s21_str[50];
  char *format = "|%10Lf|";
  long double num = 89.987;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_f_23) {
  char str[50], s21_str[50];
  char *format = "|%-0.0f|";
  float num = 73.612;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

Suite *test_sprintf_spec_f() {
  Suite *test_set = suite_create("s21_sprintf_spec_f");
  TCase *test_group = tcase_create("spec_f");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, sprintf_spec_f_1);
  tcase_add_test(test_group, sprintf_spec_f_2);
  tcase_add_test(test_group, sprintf_spec_f_3);
  tcase_add_test(test_group, sprintf_spec_f_4);
  tcase_add_test(test_group, sprintf_spec_f_5);
  tcase_add_test(test_group, sprintf_spec_f_6);
  tcase_add_test(test_group, sprintf_spec_f_7);
  tcase_add_test(test_group, sprintf_spec_f_8);
  tcase_add_test(test_group, sprintf_spec_f_9);
  tcase_add_test(test_group, sprintf_spec_f_10);
  tcase_add_test(test_group, sprintf_spec_f_11);
  tcase_add_test(test_group, sprintf_spec_f_12);
  tcase_add_test(test_group, sprintf_spec_f_13);
  tcase_add_test(test_group, sprintf_spec_f_14);
  tcase_add_test(test_group, sprintf_spec_f_15);
  tcase_add_test(test_group, sprintf_spec_f_16);
  tcase_add_test(test_group, sprintf_spec_f_17);
  tcase_add_test(test_group, sprintf_spec_f_18);
  tcase_add_test(test_group, sprintf_spec_f_19);
  tcase_add_test(test_group, sprintf_spec_f_20);
  tcase_add_test(test_group, sprintf_spec_f_21);
  tcase_add_test(test_group, sprintf_spec_f_22);
  tcase_add_test(test_group, sprintf_spec_f_23);

  return test_set;
}
