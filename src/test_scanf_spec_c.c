#include "s21_string_tests.h"

START_TEST(scanf_spec_c_1) {
  char *str = "a";
  char *format = "%c";
  char x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_int_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_c_2) {
  char *str = "b";
  char *format = "%5c";
  char x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_int_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_c_3) {
  char *str = "c";
  char *format = "%*c";
  ck_assert_int_eq(sscanf(str, format), s21_sscanf(str, format));
}
END_TEST

START_TEST(scanf_spec_c_4) {
  char *str = "e";
  char *format = "%lc";
  char x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_int_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_c_5) {
  char *str = "f g h";
  char *format = "%c %c %c";
  char x1, x2, s21_x1, s21_x2, x3, s21_x3;
  ck_assert_int_eq(sscanf(str, format, &x1, &x2, &x3),
                   s21_sscanf(str, format, &s21_x1, &s21_x2, &s21_x3));
  ck_assert_int_eq(x1, s21_x1);
  ck_assert_int_eq(x2, s21_x2);
  ck_assert_int_eq(x3, s21_x3);
}
END_TEST

Suite *test_scanf_spec_c() {
  Suite *test_set = suite_create("s21_scanf_spec_c");
  TCase *test_group = tcase_create("spec_c");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, scanf_spec_c_1);
  tcase_add_test(test_group, scanf_spec_c_2);
  tcase_add_test(test_group, scanf_spec_c_3);
  tcase_add_test(test_group, scanf_spec_c_4);
  tcase_add_test(test_group, scanf_spec_c_5);

  return test_set;
}
