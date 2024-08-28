#include "s21_string_tests.h"

START_TEST(scanf_spec_o_1) {
  char *str = "0123";
  char *format = "%o";
  unsigned x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_int_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_o_2) {
  char *str = "013";
  char *format = "%5o";
  unsigned x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_int_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_o_3) {
  char *str = "0461";
  char *format = "%*o";
  ck_assert_int_eq(sscanf(str, format), s21_sscanf(str, format));
}
END_TEST

START_TEST(scanf_spec_o_4) {
  char *str = "017";
  char *format = "%ho";
  unsigned short x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_int_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_o_5) {
  char *str = "101023711";
  char *format = "%lo";
  unsigned long x, s21_x;
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &s21_x));
  ck_assert_int_eq(x, s21_x);
}
END_TEST

START_TEST(scanf_spec_o_6) {
  char *str = "023711 07785 043";
  char *format = "%o %6o %ho";
  unsigned x1, x2, s21_x1, s21_x2;
  unsigned short x3, s21_x3;
  ck_assert_int_eq(sscanf(str, format, &x1, &x2, &x3),
                   s21_sscanf(str, format, &s21_x1, &s21_x2, &s21_x3));
  ck_assert_int_eq(x1, s21_x1);
  ck_assert_int_eq(x2, s21_x2);
  ck_assert_int_eq(x3, s21_x3);
}
END_TEST

Suite *test_scanf_spec_o() {
  Suite *test_set = suite_create("s21_scanf_spec_o");
  TCase *test_group = tcase_create("spec_o");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, scanf_spec_o_1);
  tcase_add_test(test_group, scanf_spec_o_2);
  tcase_add_test(test_group, scanf_spec_o_3);
  tcase_add_test(test_group, scanf_spec_o_4);
  tcase_add_test(test_group, scanf_spec_o_5);
  tcase_add_test(test_group, scanf_spec_o_6);

  return test_set;
}
