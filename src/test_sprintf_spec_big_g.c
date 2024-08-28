#include "s21_string_tests.h"

START_TEST(sprintf_spec_G_1) {
  char str[50], s21_str[50];
  char *format = "|%G|";
  float num = 10.76;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_G_2) {
  char str[50], s21_str[50];
  char *format = "|%7G|";
  float num = 54.898;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_G_3) {
  char str[50], s21_str[50];
  char *format = "|%6.3G|";
  float num = -45.648;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_G_4) {
  char str[50], s21_str[50];
  char *format = "|%1.7G|";
  float num = 98.534;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_G_5) {
  char str[50], s21_str[50];
  char *format = "|%-2.10G|";
  float num = 7.16;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_G_6) {
  char str[50], s21_str[50];
  char *format = "|%.10G|";
  float num = 7.62;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_G_7) {
  char str[50], s21_str[50];
  char *format = "|%.5G|";
  float num = -122.9;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_G_8) {
  char str[50], s21_str[50];
  char *format = "|% 7G|";
  float num = 256.01;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_G_9) {
  char str[50], s21_str[50];
  char *format = "|%+4G|";
  float num = 1.12;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_G_10) {
  char str[50], s21_str[50];
  char *format = "|%3G|";
  float num = 1245.001;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_G_11) {
  char str[50], s21_str[50];
  char *format = "|%11.11G|";
  float num = -1245.045645601;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_G_12) {
  char str[50], s21_str[50];
  char *format = "|%11.0G|";
  float num = 21.11;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_G_13) {
  char str[50], s21_str[50];
  char *format = "|%9.9G|";
  float num = 888.22;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_G_14) {
  char str[50], s21_str[50];
  char *format = "|%-8.8G|";
  float num = 4617.235;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_G_15) {
  char str[50], s21_str[50];
  char *format = "|%.0G|";
  float num = 77.99;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_G_16) {
  char str[50], s21_str[50];
  char *format = "|%-5.1G|";
  float num = 116.43;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_G_17) {
  char str[50], s21_str[50];
  char *format = "|%010G|";
  float num = -75.36;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_G_18) {
  char str[50], s21_str[50];
  char *format = "|%#G|";
  float num = 116.0;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_G_19) {
  char str[50], s21_str[50];
  char *format = "|%*G|";
  float x = 82.175;
  int star = 10;
  ck_assert_int_eq(sprintf(str, format, star, x),
                   s21_sprintf(s21_str, format, star, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_G_20) {
  char str[50], s21_str[50];
  char *format = "|%5.*G|";
  float x = -981.956;
  int star = 3;
  ck_assert_int_eq(sprintf(str, format, star, x),
                   s21_sprintf(s21_str, format, star, x));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_G_21) {
  char str[100], s21_str[100];
  char *format = "|%5.1G| |%3.8G| |%4G| |%-5G| |%08G| |% G|";
  float x1 = -981.05, x2 = 67.65, x3 = -56.3, x4 = 3.13, x5 = -167.01,
        x6 = 0.0001;
  ck_assert_int_eq(sprintf(str, format, x1, x2, x3, x4, x5, x6),
                   s21_sprintf(s21_str, format, x1, x2, x3, x4, x5, x6));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

Suite *test_sprintf_spec_G() {
  Suite *test_set = suite_create("s21_sprintf_spec_G");
  TCase *test_group = tcase_create("spec_G");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, sprintf_spec_G_1);
  tcase_add_test(test_group, sprintf_spec_G_2);
  tcase_add_test(test_group, sprintf_spec_G_3);
  tcase_add_test(test_group, sprintf_spec_G_4);
  tcase_add_test(test_group, sprintf_spec_G_5);
  tcase_add_test(test_group, sprintf_spec_G_6);
  tcase_add_test(test_group, sprintf_spec_G_7);
  tcase_add_test(test_group, sprintf_spec_G_8);
  tcase_add_test(test_group, sprintf_spec_G_9);
  tcase_add_test(test_group, sprintf_spec_G_10);
  tcase_add_test(test_group, sprintf_spec_G_11);
  tcase_add_test(test_group, sprintf_spec_G_12);
  tcase_add_test(test_group, sprintf_spec_G_13);
  tcase_add_test(test_group, sprintf_spec_G_14);
  tcase_add_test(test_group, sprintf_spec_G_15);
  tcase_add_test(test_group, sprintf_spec_G_16);
  tcase_add_test(test_group, sprintf_spec_G_17);
  tcase_add_test(test_group, sprintf_spec_G_18);
  tcase_add_test(test_group, sprintf_spec_G_19);
  tcase_add_test(test_group, sprintf_spec_G_20);
  tcase_add_test(test_group, sprintf_spec_G_21);

  return test_set;
}
