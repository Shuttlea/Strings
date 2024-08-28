#include "s21_string_tests.h"

START_TEST(scanf_spec_p_1) {
  char *str = "0x0060FEA8";
  char *format = "%p";
  long x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_int_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_p_2) {
  char *str = "0x0060FEA8";
  char *format = "%5p";
  long x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_int_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_p_3) {
  char *str = "0xB461AA";
  char *format = "%*p";
  ck_assert_int_eq(sscanf(str, format), s21_sscanf(str, format));
}
END_TEST

START_TEST(scanf_spec_p_4) {
  char *str = "0xA1A23711 0x58B77B85 0xFF43";
  char *format = "%p %6p %1p";
  long x1, x2, s21_x1, s21_x2;
  long x3, s21_x3;
  ck_assert_int_eq(sscanf(str, format, &x1, &x2, &x3),
                   s21_sscanf(str, format, &s21_x1, &s21_x2, &s21_x3));
  ck_assert_int_eq(x1, s21_x1);
  ck_assert_int_eq(x2, s21_x2);
  ck_assert_int_eq(x3, s21_x3);
}
END_TEST

Suite *test_scanf_spec_p() {
  Suite *test_set = suite_create("s21_scanf_spec_p");
  TCase *test_group = tcase_create("spec_p");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, scanf_spec_p_1);
  tcase_add_test(test_group, scanf_spec_p_2);
  tcase_add_test(test_group, scanf_spec_p_3);
  tcase_add_test(test_group, scanf_spec_p_4);

  return test_set;
}
