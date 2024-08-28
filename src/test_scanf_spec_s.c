#include "s21_string_tests.h"

START_TEST(scanf_spec_s_1) {
  char *str = "one";
  char *format = "%s";
  char x[50], s21_x[50];
  ck_assert_int_eq(sscanf(str, format, x), s21_sscanf(str, format, s21_x));
  ck_assert_str_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_s_2) {
  char *str = "two";
  char *format = "%5s";
  char x[50], s21_x[50];
  ck_assert_int_eq(sscanf(str, format, x), s21_sscanf(str, format, s21_x));
  ck_assert_str_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_s_3) {
  char *str = "three";
  char *format = "%*s";
  ck_assert_int_eq(sscanf(str, format), s21_sscanf(str, format));
}
END_TEST

START_TEST(scanf_spec_s_4) {
  char *str = "four";
  char *format = "%hs";
  char x[50], s21_x[50];
  ck_assert_int_eq(sscanf(str, format, x), s21_sscanf(str, format, s21_x));
  ck_assert_str_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_s_5) {
  char *str = "f i v e";
  char *format = "%ls";
  char x[50], s21_x[50];
  ck_assert_int_eq(sscanf(str, format, x), s21_sscanf(str, format, s21_x));
  ck_assert_str_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_s_6) {
  char *str = "six seven eight";
  char *format = "%s %6s %hs";
  char x1[50], x2[50], s21_x1[50], s21_x2[50], x3[50], s21_x3[50];
  // sscanf(str, format, &x1, &x2, &x3); s21_sscanf(str, format, &s21_x1,
  // &s21_x2, &s21_x3);
  ck_assert_int_eq(sscanf(str, format, x1, x2, x3),
                   s21_sscanf(str, format, s21_x1, s21_x2, s21_x3));
  ck_assert_str_eq(x1, s21_x1);
  ck_assert_str_eq(x2, s21_x2);
  ck_assert_str_eq(x3, s21_x3);
}
END_TEST

Suite *test_scanf_spec_s() {
  Suite *test_set = suite_create("s21_scanf_spec_s");
  TCase *test_group = tcase_create("spec_s");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, scanf_spec_s_1);
  tcase_add_test(test_group, scanf_spec_s_2);
  tcase_add_test(test_group, scanf_spec_s_3);
  tcase_add_test(test_group, scanf_spec_s_4);
  tcase_add_test(test_group, scanf_spec_s_5);
  tcase_add_test(test_group, scanf_spec_s_6);

  return test_set;
}
