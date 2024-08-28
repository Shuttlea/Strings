#include "s21_string_tests.h"

START_TEST(sprintf_spec_s_1) {
  char str[50], s21_str[50];
  char *format = "|%s|";
  char s[] = "water";
  ck_assert_int_eq(sprintf(str, format, s), s21_sprintf(s21_str, format, s));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_s_2) {
  char str[50], s21_str[50];
  char *format = "|%12s|";
  char s[] = "market";
  ck_assert_int_eq(sprintf(str, format, s), s21_sprintf(s21_str, format, s));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_s_3) {
  char str[50], s21_str[50];
  char *format = "|%-10s|";
  char s[] = "tendency";
  ck_assert_int_eq(sprintf(str, format, s), s21_sprintf(s21_str, format, s));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_s_4) {
  char str[50], s21_str[50];
  char *format = "|%.3s|";
  char s[] = "charm";
  ck_assert_int_eq(sprintf(str, format, s), s21_sprintf(s21_str, format, s));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_s_5) {
  char str[50], s21_str[50];
  char *format = "|%7.3s|";
  char s[] = "mathematics";
  ck_assert_int_eq(sprintf(str, format, s), s21_sprintf(s21_str, format, s));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_s_6) {
  char str[50], s21_str[50];
  char *format = "|%-5.2s|";
  char s[] = "withdraw";
  ck_assert_int_eq(sprintf(str, format, s), s21_sprintf(s21_str, format, s));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_s_7) {
  char str[50], s21_str[50];
  char *format = "|%-5.2s|";
  char s[] = "progress";
  ck_assert_int_eq(sprintf(str, format, s), s21_sprintf(s21_str, format, s));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_s_8) {
  char str[50], s21_str[50];
  char *format = "|%0.5s|";
  char s[] = "sculpture";
  ck_assert_int_eq(sprintf(str, format, s), s21_sprintf(s21_str, format, s));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_s_9) {
  char str[50], s21_str[50];
  char *format = "|%0.4s| |%8s|";
  char s1[] = "sculpture";
  char s2[] = "referral";
  ck_assert_int_eq(sprintf(str, format, s1, s2),
                   s21_sprintf(s21_str, format, s1, s2));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_s_10) {
  char str[50], s21_str[50];
  char *format = "|%15s|";
  char s[] = "waterfall";
  ck_assert_int_eq(sprintf(str, format, s), s21_sprintf(s21_str, format, s));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_s_11) {
  char str[50], s21_str[50];
  char *format = "|%-s|";
  char s[] = "predator";
  ck_assert_int_eq(sprintf(str, format, s), s21_sprintf(s21_str, format, s));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_s_12) {
  char str[50], s21_str[50];
  char *format = "|%.0s|";
  char s[] = "formulate";
  ck_assert_int_eq(sprintf(str, format, s), s21_sprintf(s21_str, format, s));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_s_13) {
  char str[50], s21_str[50];
  char *format = "|%0s|";
  char s[] = "appearance";
  ck_assert_int_eq(sprintf(str, format, s), s21_sprintf(s21_str, format, s));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_s_14) {
  char str[50], s21_str[50];
  char *format = "|%-.8s|";
  char s[] = "acquaintance";
  ck_assert_int_eq(sprintf(str, format, s), s21_sprintf(s21_str, format, s));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_s_15) {
  char str[50], s21_str[50];
  char *format = "|%2.5s|";
  char s[] = "deviation";
  ck_assert_int_eq(sprintf(str, format, s), s21_sprintf(s21_str, format, s));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_s_16) {
  char str[50], s21_str[50];
  char *format = "|%-4.8s|";
  char s[] = "delivery";
  ck_assert_int_eq(sprintf(str, format, s), s21_sprintf(s21_str, format, s));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_s_17) {
  char str[50], s21_str[50];
  char *format = "|%-1.0s|";
  char s[] = "designer";
  ck_assert_int_eq(sprintf(str, format, s), s21_sprintf(s21_str, format, s));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_s_18) {
  char str[50], s21_str[50];
  char *format = "|%.1s|";
  char s[] = "prefer";
  ck_assert_int_eq(sprintf(str, format, s), s21_sprintf(s21_str, format, s));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_s_19) {
  char str[50], s21_str[50];
  char *format = "|%.s|";
  char s[] = "prison";
  ck_assert_int_eq(sprintf(str, format, s), s21_sprintf(s21_str, format, s));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_s_21) {
  char str[50], s21_str[50];
  char *format = "|%s| |%-s| |%0s|";
  char s1[] = "strange";
  char s2[] = "mosaic";
  char s3[] = "color";
  ck_assert_int_eq(sprintf(str, format, s1, s2, s3),
                   s21_sprintf(s21_str, format, s1, s2, s3));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

Suite *test_sprintf_spec_s() {
  Suite *test_set = suite_create("s21_sprintf_spec_s");
  TCase *test_group_spec_s = tcase_create("spec_s");
  suite_add_tcase(test_set, test_group_spec_s);

  tcase_add_test(test_group_spec_s, sprintf_spec_s_1);
  tcase_add_test(test_group_spec_s, sprintf_spec_s_2);
  tcase_add_test(test_group_spec_s, sprintf_spec_s_3);
  tcase_add_test(test_group_spec_s, sprintf_spec_s_4);
  tcase_add_test(test_group_spec_s, sprintf_spec_s_5);
  tcase_add_test(test_group_spec_s, sprintf_spec_s_6);
  tcase_add_test(test_group_spec_s, sprintf_spec_s_7);
  tcase_add_test(test_group_spec_s, sprintf_spec_s_8);
  tcase_add_test(test_group_spec_s, sprintf_spec_s_9);
  tcase_add_test(test_group_spec_s, sprintf_spec_s_10);
  tcase_add_test(test_group_spec_s, sprintf_spec_s_11);
  tcase_add_test(test_group_spec_s, sprintf_spec_s_12);
  tcase_add_test(test_group_spec_s, sprintf_spec_s_13);
  tcase_add_test(test_group_spec_s, sprintf_spec_s_14);
  tcase_add_test(test_group_spec_s, sprintf_spec_s_15);
  tcase_add_test(test_group_spec_s, sprintf_spec_s_16);
  tcase_add_test(test_group_spec_s, sprintf_spec_s_17);
  tcase_add_test(test_group_spec_s, sprintf_spec_s_18);
  tcase_add_test(test_group_spec_s, sprintf_spec_s_19);
  tcase_add_test(test_group_spec_s, sprintf_spec_s_21);

  return test_set;
}
