#include "s21_string_tests.h"

START_TEST(insert_1) {
  char s1[] = "crowd";
  char s2[] = "crowd";
  char *s3 = s21_insert(s1, s2, 5);
  ck_assert_pstr_eq(s3, "crowdcrowd");
  if (s3) free(s3);
}
END_TEST

START_TEST(insert_2) {
  char s1[] = "shop";
  char s2[] = "roof";
  char *s3 = s21_insert(s1, s2, 3);
  ck_assert_pstr_eq(s3, "shoroofp");
  if (s3) free(s3);
}
END_TEST

START_TEST(insert_3) {
  char s1[] = "She used her own hair to give it more flavor";
  char s2[] = "in the soup ";
  char *s3 = s21_insert(s1, s2, 22);
  ck_assert_pstr_eq(s3,
                    "She used her own hair in the soup to give it more flavor");
  if (s3) free(s3);
}
END_TEST

START_TEST(insert_4) {
  char s1[] = "The doll spun around ";
  char s2[] = "about being paranoid ";
  char *s3 = s21_insert(s1, s2, 14);
  ck_assert_pstr_eq(s3, "The doll spun about being paranoid around ");
  if (s3) free(s3);
}
END_TEST

START_TEST(insert_5) {
  char s1[] = "";
  char s2[] = "The Great Dane looked more like a horse than a dog.";
  char *s3 = s21_insert(s1, s2, 0);
  ck_assert_pstr_eq(s3, "The Great Dane looked more like a horse than a dog.");
  if (s3) free(s3);
}
END_TEST

START_TEST(insert_6) {
  char s1[] = "Dan took the deep dive down the rabbit hole.";
  char s2[] = "";
  char *s3 = s21_insert(s1, s2, 7);
  ck_assert_pstr_eq(s3, "Dan took the deep dive down the rabbit hole.");
  if (s3) free(s3);
}
END_TEST

START_TEST(insert_7) {
  char s1[] = "";
  char s2[] = "";
  char *s3 = s21_insert(s1, s2, 0);
  ck_assert_pstr_eq(s3, "");
  if (s3) free(s3);
}
END_TEST

START_TEST(insert_8) {
  char s1[] = "";
  char s2[] = "";
  char *s3 = s21_insert(s1, s2, 8);
  ck_assert_pstr_eq(s3, NULL);
  if (s3) free(s3);
}
END_TEST

START_TEST(insert_9) {
  char s1[] = "Pat ordered a ghost pepper pie.";
  char s2[] = "He appeared to be confusingly perplexed.";
  char *s3 = s21_insert(s1, s2, 4);
  ck_assert_pstr_eq(s3,
                    "Pat He appeared to be confusingly perplexed.ordered a "
                    "ghost pepper pie.");
  if (s3) free(s3);
}
END_TEST

START_TEST(insert_10) {
  char s1[] =
      "The sign said there was road work ahead so he decided to speed up.";
  char s2[] = "~!@#$^&*()_+:|<>?`-=[]{}',./";
  char *s3 = s21_insert(s1, s2, 15);
  ck_assert_pstr_eq(s3,
                    "The sign said t~!@#$^&*()_+:|<>?`-=[]{}',./here was road "
                    "work ahead so he decided to speed up.");
  if (s3) free(s3);
}
END_TEST

START_TEST(insert_11) {
  char *s1 = "Hello, ";
  char *s2 = "World!";
  char *s3 = s21_insert(s1, s2, (s21_size_t)0);
  ck_assert_pstr_eq(s3, "World!Hello, ");
  if (s3) free(s3);
}
END_TEST

START_TEST(insert_12) {
  char *s1 = "";
  char *s2 = "";
  char *s3 = s21_insert(s1, s2, (s21_size_t)100);
  ck_assert_pstr_eq(s3, NULL);
  if (s3) free(s3);
}
END_TEST

START_TEST(insert_13) {
  char *s1 = NULL;
  char *s2 = NULL;
  char *s3 = s21_insert(s1, s2, (s21_size_t)100);
  ck_assert_pstr_eq(s3, NULL);
  if (s3) free(s3);
}
END_TEST

START_TEST(insert_14) {
  char *s1 = "\0wd\0\0w\t\\twda\n";
  char *s2 = "\0\0\n\0";
  char *s3 = s21_insert(s1, s2, (s21_size_t)100);
  ck_assert_pstr_eq(s3, NULL);
  if (s3) free(s3);
}
END_TEST

START_TEST(insert_15) {
  char *s1 = NULL;
  char *s2 = "adw";
  char *s3 = s21_insert(s1, s2, 0);
  ck_assert_pstr_eq(s3, NULL);
  if (s3) free(s3);
}
END_TEST

START_TEST(insert_16) {
  char *s1 = "adw";
  char *s2 = NULL;
  char *s3 = s21_insert(s1, s2, 1);
  ck_assert_pstr_eq(s3, NULL);
  if (s3) free(s3);
}
END_TEST

START_TEST(insert_17) {
  char *s1 = "adw";
  char *s2 = "awd";
  char *s3 = s21_insert(s1, s2, -2);
  ck_assert_pstr_eq(s3, NULL);
  if (s3) free(s3);
}
END_TEST

Suite *test_insert() {
  Suite *test_set = suite_create("s21_insert");
  TCase *test_group = tcase_create("s21_insert_test_group");

  tcase_add_test(test_group, insert_1);
  tcase_add_test(test_group, insert_2);
  tcase_add_test(test_group, insert_3);
  tcase_add_test(test_group, insert_4);
  tcase_add_test(test_group, insert_5);
  tcase_add_test(test_group, insert_6);
  tcase_add_test(test_group, insert_7);
  tcase_add_test(test_group, insert_8);
  tcase_add_test(test_group, insert_9);
  tcase_add_test(test_group, insert_10);
  tcase_add_test(test_group, insert_11);
  tcase_add_test(test_group, insert_12);
  tcase_add_test(test_group, insert_13);
  tcase_add_test(test_group, insert_14);
  tcase_add_test(test_group, insert_15);
  tcase_add_test(test_group, insert_16);
  tcase_add_test(test_group, insert_17);

  suite_add_tcase(test_set, test_group);

  return test_set;
}
