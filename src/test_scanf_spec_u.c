#include "s21_string_tests.h"

START_TEST(scanf_spec_u_1) {
  char *str = "123";
  char *format = "%u";
  unsigned x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_int_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_u_2) {
  char *str = "13";
  char *format = "%5u";
  unsigned x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_int_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_u_3) {
  char *str = "461";
  char *format = "%*u";
  ck_assert_int_eq(sscanf(str, format), s21_sscanf(str, format));
}
END_TEST

START_TEST(scanf_spec_u_4) {
  char *str = "-17";
  char *format = "%hu";
  unsigned short x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_int_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_u_5) {
  char *str = "101023711";
  char *format = "%lu";
  unsigned long x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_int_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_u_6) {
  char *str = "101023711 587785 43";
  char *format = "%u %6u %hu";
  unsigned x1, x2, s21_x1, s21_x2;
  unsigned short x3, s21_x3;
  ck_assert_int_eq(sscanf(str, format, &x1, &x2, &x3),
                   s21_sscanf(str, format, &s21_x1, &s21_x2, &s21_x3));
  ck_assert_int_eq(x1, s21_x1);
  ck_assert_int_eq(x2, s21_x2);
  ck_assert_int_eq(x3, s21_x3);
}
END_TEST

Suite *test_scanf_spec_u() {
  Suite *test_set = suite_create("s21_scanf_spec_u");
  TCase *test_group = tcase_create("spec_u");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, scanf_spec_u_1);
  tcase_add_test(test_group, scanf_spec_u_2);
  tcase_add_test(test_group, scanf_spec_u_3);
  tcase_add_test(test_group, scanf_spec_u_4);
  tcase_add_test(test_group, scanf_spec_u_5);
  tcase_add_test(test_group, scanf_spec_u_6);

  return test_set;
}
