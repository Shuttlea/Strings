#include "s21_string_tests.h"

START_TEST(sprintf_spec_d_1) {
  char str[50], s21_str[50];
  char *format = "|%0.0d|";
  int num = 23894298;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_2) {
  char str[50], s21_str[50];
  char *format = "|%-d|";
  int num = 1021;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_3) {
  char str[50], s21_str[50];
  char *format = "|%10.8d|";
  int num = 716;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_4) {
  char str[50], s21_str[50];
  char *format = "|%9.4d|";
  int num = -564;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_5) {
  char str[50], s21_str[50];
  char *format = "|%010d|";
  int num = 1234;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_6) {
  char str[50], s21_str[50];
  char *format = "|%8d|";
  int num = -45;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_7) {
  char str[50], s21_str[50];
  char *format = "|%-6d|";
  int num = 78945;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_8) {
  char str[50], s21_str[50];
  char *format = "|%1.1d|";
  int num = 1768;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_9) {
  char str[50], s21_str[50];
  char *format = "|%.3d|";
  int num = 418;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_10) {
  char str[50], s21_str[50];
  char *format = "|%-.4d|";
  int num = -45;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_11) {
  char str[50], s21_str[50];
  char *format = "|%08d|";
  int num = 12;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_12) {
  char str[50], s21_str[50];
  char *format = "|%-015d|";
  int num = 68;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_13) {
  char str[50], s21_str[50];
  char *format = "|%5.10d|";
  int num = 13582;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_14) {
  char str[50], s21_str[50];
  char *format = "|%-7.13d|";
  int num = -586;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_15) {
  char str[50], s21_str[50];
  char *format = "|%d|";
  int num = -586;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_17) {
  char str[50], s21_str[50];
  char *format = "|%5.d|";
  int num = 78;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_18) {
  char str[50], s21_str[50];
  char *format = "|%-7.d|";
  int num = -164;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_19) {
  char str[50], s21_str[50];
  char *format = "|%.0d|";
  int num = -61;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_20) {
  char str[50], s21_str[50];
  char *format = "|%8.0d|";
  int num = 999;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_21) {
  char str[50], s21_str[50];
  char *format = "|%-7.0d|";
  int num = 546;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_22) {
  char str[50], s21_str[50];
  char *format = "|%+d|";
  int num = -1675;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_23) {
  char str[50], s21_str[50];
  char *format = "|%+7.13d|";
  int num = 678;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_24) {
  char str[50], s21_str[50];
  char *format = "|%+08d|";
  int num = -54678;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_25) {
  char str[50], s21_str[50];
  char *format = "|%+.0d|";
  int num = 54;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_26) {
  char str[50], s21_str[50];
  char *format = "|%+.d|";
  int num = 5176;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_27) {
  char str[50], s21_str[50];
  char *format = "|%ld|";
  long num = -156;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_28) {
  char str[50], s21_str[50];
  char *format = "|%+ld|";
  long num = 511677;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_29) {
  char str[50], s21_str[50];
  char *format = "|%+0ld|";
  long num = -645;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_30) {
  char str[50], s21_str[50];
  char *format = "|%+0.3ld|";
  long num = 687;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_31) {
  char str[50], s21_str[50];
  char *format = "|%+3.5ld|";
  long num = 117;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_32) {
  char str[50], s21_str[50];
  char *format = "|%+13ld|";
  long num = -978;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_33) {
  char str[50], s21_str[50];
  char *format = "|%+3.1ld|";
  long num = -17;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_34) {
  char str[50], s21_str[50];
  char *format = "|%hd|";
  short num = 678;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_36) {
  char str[50], s21_str[50];
  char *format = "|%0hd|";
  short num = -4566;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_37) {
  char str[50], s21_str[50];
  char *format = "|%+hd|";
  short num = 48996;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_38) {
  char str[50], s21_str[50];
  char *format = "|%-hd|";
  short num = -78;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_39) {
  char str[50], s21_str[50];
  char *format = "|%-5.1hd|";
  short num = 166;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_40) {
  char str[50], s21_str[50];
  char *format = "|%-.8hd|";
  short num = 6615;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_41) {
  char str[50], s21_str[50];
  char *format = "|%0.8hd|";
  short num = -6;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_42) {
  char str[50], s21_str[50];
  char *format = "|% d|";
  short num = -64;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_43) {
  char str[50], s21_str[50];
  char *format = "|% d|";
  int num = 128;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_44) {
  char str[50], s21_str[50];
  char *format = "|%*d|";
  int num = 54;
  int star = 10;
  ck_assert_int_eq(sprintf(str, format, star, num),
                   s21_sprintf(s21_str, format, star, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_45) {
  char str[50], s21_str[50];
  char *format = "|%-*d|";
  int num = -465;
  int star = 7;
  ck_assert_int_eq(sprintf(str, format, star, num),
                   s21_sprintf(s21_str, format, star, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_46) {
  char str[50], s21_str[50];
  char *format = "|%0*d|";
  int num = 565;
  int star = 5;
  ck_assert_int_eq(sprintf(str, format, star, num),
                   s21_sprintf(s21_str, format, star, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_47) {
  char str[50], s21_str[50];
  char *format = "|%+*d|";
  int num = -164;
  int star = 8;
  ck_assert_int_eq(sprintf(str, format, star, num),
                   s21_sprintf(s21_str, format, star, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_48) {
  char str[50], s21_str[50];
  char *format = "|%*d|";
  int num = 389;
  int star = -8;
  ck_assert_int_eq(sprintf(str, format, star, num),
                   s21_sprintf(s21_str, format, star, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_49) {
  char str[50], s21_str[50];
  char *format = "|%.*d|";
  int num = 9634;
  int star = 8;
  ck_assert_int_eq(sprintf(str, format, star, num),
                   s21_sprintf(s21_str, format, star, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_50) {
  char str[50], s21_str[50];
  char *format = "|%.*d|";
  int num = -96;
  int star = -3;
  ck_assert_int_eq(sprintf(str, format, star, num),
                   s21_sprintf(s21_str, format, star, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_51) {
  char str[50], s21_str[50];
  char *format = "|%0.*d|";
  int num = 81;
  int star = 6;
  ck_assert_int_eq(sprintf(str, format, star, num),
                   s21_sprintf(s21_str, format, star, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_52) {
  char str[50], s21_str[50];
  char *format = "|%+5.*d|";
  int num = -16;
  int star = 4;
  ck_assert_int_eq(sprintf(str, format, star, num),
                   s21_sprintf(s21_str, format, star, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_53) {
  char str[50], s21_str[50];
  char *format = "|%d| |%-d| |%+d| |%0d| |%5.3d| |%-3.3d| |%0.0d|";
  int x1 = -16, x2 = 14, x3 = -10, x4 = 0, x5 = 1908, x6 = -1412, x7 = 0;
  ck_assert_int_eq(sprintf(str, format, x1, x2, x3, x4, x5, x6, x7),
                   s21_sprintf(s21_str, format, x1, x2, x3, x4, x5, x6, x7));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_54) {
  char str[50], s21_str[50];
  char *format = "|%-0.0d|";
  int num = 11564;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

Suite *test_sprintf_spec_d() {
  Suite *test_set = suite_create("s21_sprintf_spec_d");
  TCase *test_group_spec_d = tcase_create("spec_d");
  suite_add_tcase(test_set, test_group_spec_d);

  tcase_add_test(test_group_spec_d, sprintf_spec_d_1);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_2);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_3);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_4);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_5);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_6);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_7);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_8);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_9);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_10);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_11);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_12);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_13);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_14);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_15);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_17);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_18);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_19);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_20);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_21);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_22);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_23);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_24);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_25);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_26);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_27);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_28);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_29);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_30);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_31);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_32);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_33);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_34);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_36);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_37);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_38);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_39);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_40);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_41);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_42);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_43);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_44);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_45);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_46);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_47);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_48);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_49);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_50);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_51);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_52);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_53);
  tcase_add_test(test_group_spec_d, sprintf_spec_d_54);

  return test_set;
}
