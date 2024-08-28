#include "s21_string_tests.h"

START_TEST(scanf_spec_X_1) {
  char *str = "0x123BC";
  char *format = "%X";
  unsigned x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_int_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_X_2) {
  char *str = "0x13FA";
  char *format = "%5X";
  unsigned x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_int_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_X_3) {
  char *str = "0xB461AA";
  char *format = "%*X";
  ck_assert_int_eq(sscanf(str, format), s21_sscanf(str, format));
}
END_TEST

START_TEST(scanf_spec_X_4) {
  char *str = "-0xB17CF";
  char *format = "%hX";
  unsigned short x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_int_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_X_5) {
  char *str = "0x1A1D23711";
  char *format = "%lX";
  unsigned long x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_int_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_X_6) {
  char *str = "0xA1A23711 0x58B77B85 0xFF43";
  char *format = "%X %6X %hX";
  unsigned x1, x2, s21_x1, s21_x2;
  unsigned short x3, s21_x3;
  ck_assert_int_eq(sscanf(str, format, &x1, &x2, &x3),
                   s21_sscanf(str, format, &s21_x1, &s21_x2, &s21_x3));
  ck_assert_int_eq(x1, s21_x1);
  ck_assert_int_eq(x2, s21_x2);
  ck_assert_int_eq(x3, s21_x3);
}
END_TEST

Suite *test_scanf_spec_X() {
  Suite *test_set = suite_create("s21_scanf_spec_X");
  TCase *test_group = tcase_create("spec_X");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, scanf_spec_X_1);
  tcase_add_test(test_group, scanf_spec_X_2);
  tcase_add_test(test_group, scanf_spec_X_3);
  tcase_add_test(test_group, scanf_spec_X_4);
  tcase_add_test(test_group, scanf_spec_X_5);
  tcase_add_test(test_group, scanf_spec_X_6);

  return test_set;
}
