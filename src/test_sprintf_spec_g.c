#include "s21_string_tests.h"

START_TEST(sprintf_spec_g_1) {
  char str[50], s21_str[50];
  char *format = "|%g|";
  float num = 10.76;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_2) {
  char str[50], s21_str[50];
  char *format = "|%7g|";
  float num = 54.898;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_3) {
  char str[50], s21_str[50];
  char *format = "|%6.3g|";
  float num = -45.648;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_4) {
  char str[50], s21_str[50];
  char *format = "|%1.7g|";
  float num = 98.534;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_5) {
  char str[50], s21_str[50];
  char *format = "|%-2.10g|";
  float num = 7.16;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_6) {
  char str[50], s21_str[50];
  char *format = "|%.10g|";
  float num = 7.62;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_7) {
  char str[50], s21_str[50];
  char *format = "|%.5g|";
  float num = -122.9;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_8) {
  char str[50], s21_str[50];
  char *format = "|% 7g|";
  float num = 256.01;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_9) {
  char str[50], s21_str[50];
  char *format = "|%+4g|";
  float num = 1.12;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_10) {
  char str[50], s21_str[50];
  char *format = "|%3g|";
  float num = 1245.001;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_11) {
  char str[50], s21_str[50];
  char *format = "|%11.11g|";
  float num = -1245.045645601;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_12) {
  char str[50], s21_str[50];
  char *format = "|%11.0g|";
  float num = 21.11;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_13) {
  char str[50], s21_str[50];
  char *format = "|%9.9g|";
  float num = 888.22;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_14) {
  char str[50], s21_str[50];
  char *format = "|%-8.8g|";
  float num = 4617.235;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_15) {
  char str[50], s21_str[50];
  char *format = "|%.0g|";
  float num = 77.99;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_16) {
  char str[50], s21_str[50];
  char *format = "|%-5.1g|";
  float num = 116.43;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_17) {
  char str[50], s21_str[50];
  char *format = "|%010g|";
  float num = -75.36;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_18) {
  char str[50], s21_str[50];
  char *format = "|%#g|";
  float num = 116.0;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_19) {
  char str[50], s21_str[50];
  char *format = "|%*g|";
  float x = 82.175;
  int star = 10;
  ck_assert_int_eq(sprintf(str, format, star, x),
                   s21_sprintf(s21_str, format, star, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_20) {
  char str[50], s21_str[50];
  char *format = "|%5.*g|";
  float x = -981.956;
  int star = 3;
  ck_assert_int_eq(sprintf(str, format, star, x),
                   s21_sprintf(s21_str, format, star, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_21) {
  char str[100], s21_str[100];
  char *format = "|%5.1g| |%3.8g| |%4g| |%-5g| |%08g| |% g|";
  float x1 = -981.05, x2 = 67.65, x3 = -56.3, x4 = 3.13, x5 = -167.01,
        x6 = 0.0001;
  ck_assert_int_eq(sprintf(str, format, x1, x2, x3, x4, x5, x6),
                   s21_sprintf(s21_str, format, x1, x2, x3, x4, x5, x6));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_22) {
  char str[50], s21_str[50];
  char *format = "|%0g|";
  float num = 0.0;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_23) {
  char str[50], s21_str[50];
  char *format = "|%0.0g|";
  float num = 0.072;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_24) {
  char str[50], s21_str[50];
  char *format = "|%-g|";
  float num = 0.072;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_25) {
  char str[50], s21_str[50];
  char *format = "|%g|";
  float num = 0.00000000072;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_26) {
  char str[50], s21_str[50];
  char *format = "|%0g|";
  float num = 0.00000000072;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_27) {
  char str[50], s21_str[50];
  char *format = "|%-0.0g|";
  float num = 123.323;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

Suite *test_sprintf_spec_g() {
  Suite *test_set = suite_create("s21_sprintf_spec_g");
  TCase *test_group = tcase_create("spec_g");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, sprintf_spec_g_1);
  tcase_add_test(test_group, sprintf_spec_g_2);
  tcase_add_test(test_group, sprintf_spec_g_3);
  tcase_add_test(test_group, sprintf_spec_g_4);
  tcase_add_test(test_group, sprintf_spec_g_5);
  tcase_add_test(test_group, sprintf_spec_g_6);
  tcase_add_test(test_group, sprintf_spec_g_7);
  tcase_add_test(test_group, sprintf_spec_g_8);
  tcase_add_test(test_group, sprintf_spec_g_9);
  tcase_add_test(test_group, sprintf_spec_g_10);
  tcase_add_test(test_group, sprintf_spec_g_11);
  tcase_add_test(test_group, sprintf_spec_g_12);
  tcase_add_test(test_group, sprintf_spec_g_13);
  tcase_add_test(test_group, sprintf_spec_g_14);
  tcase_add_test(test_group, sprintf_spec_g_15);
  tcase_add_test(test_group, sprintf_spec_g_16);
  tcase_add_test(test_group, sprintf_spec_g_17);
  tcase_add_test(test_group, sprintf_spec_g_18);
  tcase_add_test(test_group, sprintf_spec_g_19);
  tcase_add_test(test_group, sprintf_spec_g_20);
  tcase_add_test(test_group, sprintf_spec_g_21);
  tcase_add_test(test_group, sprintf_spec_g_22);
  tcase_add_test(test_group, sprintf_spec_g_23);
  tcase_add_test(test_group, sprintf_spec_g_24);
  tcase_add_test(test_group, sprintf_spec_g_25);
  tcase_add_test(test_group, sprintf_spec_g_26);
  tcase_add_test(test_group, sprintf_spec_g_27);

  return test_set;
}
