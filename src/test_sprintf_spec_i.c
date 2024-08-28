#include "s21_string_tests.h"

START_TEST(sprintf_spec_i_1) {
  char str[50], s21_str[50];
  char *format = "|%i|";
  int num = 0b1001;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_2) {
  char str[50], s21_str[50];
  char *format = "|%-i|";
  int num = 0xFFF;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_3) {
  char str[50], s21_str[50];
  char *format = "|%10.8i|";
  int num = 013;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_4) {
  char str[50], s21_str[50];
  char *format = "|%9.4i|";
  int num = -0b1111;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_5) {
  char str[50], s21_str[50];
  char *format = "|%010i|";
  int num = 010;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_6) {
  char str[50], s21_str[50];
  char *format = "|%8i|";
  int num = -45;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_7) {
  char str[50], s21_str[50];
  char *format = "|%-6i|";
  int num = 0b1011101;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_8) {
  char str[50], s21_str[50];
  char *format = "|%1.1i|";
  int num = -0365;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_9) {
  char str[50], s21_str[50];
  char *format = "|%.3i|";
  int num = 0xAA128;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_10) {
  char str[50], s21_str[50];
  char *format = "|%-.4i|";
  int num = -45;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_11) {
  char str[50], s21_str[50];
  char *format = "|%08i|";
  int num = 0b001111;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_12) {
  char str[50], s21_str[50];
  char *format = "|%-015i|";
  int num = 0112227;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_13) {
  char str[50], s21_str[50];
  char *format = "|%5.10i|";
  int num = 0xCABF;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_14) {
  char str[50], s21_str[50];
  char *format = "|%-7.13i|";
  int num = -586;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_15) {
  char str[50], s21_str[50];
  char *format = "|%i|";
  int num = -0b111001101;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_17) {
  char str[50], s21_str[50];
  char *format = "|%5.i|";
  int num = 78;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_18) {
  char str[50], s21_str[50];
  char *format = "|%-7.i|";
  int num = -164;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_19) {
  char str[50], s21_str[50];
  char *format = "|%.0i|";
  int num = -61;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_20) {
  char str[50], s21_str[50];
  char *format = "|%8.0i|";
  int num = 999;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_21) {
  char str[50], s21_str[50];
  char *format = "|%-7.0i|";
  int num = 546;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_22) {
  char str[50], s21_str[50];
  char *format = "|%+i|";
  int num = -1675;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_23) {
  char str[50], s21_str[50];
  char *format = "|%+7.13i|";
  int num = 678;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_24) {
  char str[50], s21_str[50];
  char *format = "|%+08i|";
  int num = -54678;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_25) {
  char str[50], s21_str[50];
  char *format = "|%+.0i|";
  int num = 54;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_26) {
  char str[50], s21_str[50];
  char *format = "|%+.i|";
  int num = 5176;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_27) {
  char str[50], s21_str[50];
  char *format = "|%li|";
  long num = -156;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_28) {
  char str[50], s21_str[50];
  char *format = "|%+li|";
  long num = 511677;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_29) {
  char str[50], s21_str[50];
  char *format = "|%+0li|";
  long num = -645;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_30) {
  char str[50], s21_str[50];
  char *format = "|%+0.3li|";
  long num = 687;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_31) {
  char str[50], s21_str[50];
  char *format = "|%+3.5li|";
  long num = 117;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_32) {
  char str[50], s21_str[50];
  char *format = "|%+13li|";
  long num = -978;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_33) {
  char str[50], s21_str[50];
  char *format = "|%+3.1li|";
  long num = -17;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_34) {
  char str[50], s21_str[50];
  char *format = "|%hi|";
  short num = 678;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_36) {
  char str[50], s21_str[50];
  char *format = "|%0hi|";
  short num = -4566;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_37) {
  char str[50], s21_str[50];
  char *format = "|%+hi|";
  short num = 48996;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_38) {
  char str[50], s21_str[50];
  char *format = "|%-hi|";
  short num = -78;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_39) {
  char str[50], s21_str[50];
  char *format = "|%-5.1hi|";
  short num = 166;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_40) {
  char str[50], s21_str[50];
  char *format = "|%-.8hi|";
  short num = 6615;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_41) {
  char str[50], s21_str[50];
  char *format = "|%0.8hi|";
  short num = -6;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_42) {
  char str[50], s21_str[50];
  char *format = "|% i|";
  int num = -64;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_43) {
  char str[50], s21_str[50];
  char *format = "|% i|";
  int num = 128;
  ck_assert_int_eq(sprintf(str, format, num),
                   s21_sprintf(s21_str, format, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_44) {
  char str[50], s21_str[50];
  char *format = "|%*i|";
  int num = 54;
  int star = 10;
  ck_assert_int_eq(sprintf(str, format, star, num),
                   s21_sprintf(s21_str, format, star, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_45) {
  char str[50], s21_str[50];
  char *format = "|%-*i|";
  int num = -465;
  int star = 7;
  ck_assert_int_eq(sprintf(str, format, star, num),
                   s21_sprintf(s21_str, format, star, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_46) {
  char str[50], s21_str[50];
  char *format = "|%0*i|";
  int num = 565;
  int star = 5;
  ck_assert_int_eq(sprintf(str, format, star, num),
                   s21_sprintf(s21_str, format, star, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_47) {
  char str[50], s21_str[50];
  char *format = "|%+*i|";
  int num = -164;
  int star = 8;
  ck_assert_int_eq(sprintf(str, format, star, num),
                   s21_sprintf(s21_str, format, star, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_48) {
  char str[50], s21_str[50];
  char *format = "|%*i|";
  int num = 389;
  int star = -8;
  ck_assert_int_eq(sprintf(str, format, star, num),
                   s21_sprintf(s21_str, format, star, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_49) {
  char str[50], s21_str[50];
  char *format = "|%.*i|";
  int num = 9634;
  int star = 8;
  ck_assert_int_eq(sprintf(str, format, star, num),
                   s21_sprintf(s21_str, format, star, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_50) {
  char str[50], s21_str[50];
  char *format = "|%.*i|";
  int num = -96;
  int star = -3;
  ck_assert_int_eq(sprintf(str, format, star, num),
                   s21_sprintf(s21_str, format, star, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_51) {
  char str[50], s21_str[50];
  char *format = "|%0.*i|";
  int num = 81;
  int star = 6;
  ck_assert_int_eq(sprintf(str, format, star, num),
                   s21_sprintf(s21_str, format, star, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_52) {
  char str[50], s21_str[50];
  char *format = "|%+5.*i|";
  int num = -16;
  int star = 4;
  ck_assert_int_eq(sprintf(str, format, star, num),
                   s21_sprintf(s21_str, format, star, num));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_53) {
  char str[50], s21_str[50];
  char *format = "|%i| |%-i| |%+i| |%0i| |%5.3i| |%-3.3i|";
  int x1 = -16, x2 = 14, x3 = -10, x4 = 0, x5 = 1908, x6 = -1412;
  ck_assert_int_eq(sprintf(str, format, x1, x2, x3, x4, x5, x6),
                   s21_sprintf(s21_str, format, x1, x2, x3, x4, x5, x6));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

Suite *test_sprintf_spec_i() {
  Suite *test_set = suite_create("s21_sprintf_spec_i");
  TCase *test_group = tcase_create("spec_i");
  suite_add_tcase(test_set, test_group);

  tcase_add_test(test_group, sprintf_spec_i_1);
  tcase_add_test(test_group, sprintf_spec_i_2);
  tcase_add_test(test_group, sprintf_spec_i_3);
  tcase_add_test(test_group, sprintf_spec_i_4);
  tcase_add_test(test_group, sprintf_spec_i_5);
  tcase_add_test(test_group, sprintf_spec_i_6);
  tcase_add_test(test_group, sprintf_spec_i_7);
  tcase_add_test(test_group, sprintf_spec_i_8);
  tcase_add_test(test_group, sprintf_spec_i_9);
  tcase_add_test(test_group, sprintf_spec_i_10);
  tcase_add_test(test_group, sprintf_spec_i_11);
  tcase_add_test(test_group, sprintf_spec_i_12);
  tcase_add_test(test_group, sprintf_spec_i_13);
  tcase_add_test(test_group, sprintf_spec_i_14);
  tcase_add_test(test_group, sprintf_spec_i_15);
  tcase_add_test(test_group, sprintf_spec_i_17);
  tcase_add_test(test_group, sprintf_spec_i_18);
  tcase_add_test(test_group, sprintf_spec_i_19);
  tcase_add_test(test_group, sprintf_spec_i_20);
  tcase_add_test(test_group, sprintf_spec_i_21);
  tcase_add_test(test_group, sprintf_spec_i_22);
  tcase_add_test(test_group, sprintf_spec_i_23);
  tcase_add_test(test_group, sprintf_spec_i_24);
  tcase_add_test(test_group, sprintf_spec_i_25);
  tcase_add_test(test_group, sprintf_spec_i_26);
  tcase_add_test(test_group, sprintf_spec_i_27);
  tcase_add_test(test_group, sprintf_spec_i_28);
  tcase_add_test(test_group, sprintf_spec_i_29);
  tcase_add_test(test_group, sprintf_spec_i_30);
  tcase_add_test(test_group, sprintf_spec_i_31);
  tcase_add_test(test_group, sprintf_spec_i_32);
  tcase_add_test(test_group, sprintf_spec_i_33);
  tcase_add_test(test_group, sprintf_spec_i_34);
  tcase_add_test(test_group, sprintf_spec_i_36);
  tcase_add_test(test_group, sprintf_spec_i_37);
  tcase_add_test(test_group, sprintf_spec_i_38);
  tcase_add_test(test_group, sprintf_spec_i_39);
  tcase_add_test(test_group, sprintf_spec_i_40);
  tcase_add_test(test_group, sprintf_spec_i_41);
  tcase_add_test(test_group, sprintf_spec_i_42);
  tcase_add_test(test_group, sprintf_spec_i_43);
  tcase_add_test(test_group, sprintf_spec_i_44);
  tcase_add_test(test_group, sprintf_spec_i_45);
  tcase_add_test(test_group, sprintf_spec_i_46);
  tcase_add_test(test_group, sprintf_spec_i_47);
  tcase_add_test(test_group, sprintf_spec_i_48);
  tcase_add_test(test_group, sprintf_spec_i_49);
  tcase_add_test(test_group, sprintf_spec_i_50);
  tcase_add_test(test_group, sprintf_spec_i_51);
  tcase_add_test(test_group, sprintf_spec_i_52);
  tcase_add_test(test_group, sprintf_spec_i_53);

  return test_set;
}
