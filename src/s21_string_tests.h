#ifndef S21_STRING_TESTS_H
#define S21_STRING_TESTS_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_scanf.h"
#include "s21_sprintf.h"
#include "s21_string.h"

#define SUITE_COUNT 48

Suite *test_strlen();
Suite *test_strncat();
Suite *test_strchr();
Suite *test_strerror();
Suite *test_strncmp();
Suite *test_strncpy();
Suite *test_strcspn();
Suite *test_strpbrk();
Suite *test_strrchr();
Suite *test_strstr();
Suite *test_strtok();

Suite *test_memchr();
Suite *test_memcmp();
Suite *test_memcpy();
Suite *test_memset();

Suite *test_to_lower();
Suite *test_to_upper();
Suite *test_insert();
Suite *test_trim();

Suite *test_sprintf_spec_s();
Suite *test_sprintf_spec_d();
Suite *test_sprintf_spec_f();
Suite *test_sprintf_spec_c();
Suite *test_sprintf_spec_u();
Suite *test_sprintf_spec_i();
Suite *test_sprintf_spec_e();
Suite *test_sprintf_spec_E();
Suite *test_sprintf_spec_g();
Suite *test_sprintf_spec_G();
Suite *test_sprintf_spec_o();
Suite *test_sprintf_spec_x();
Suite *test_sprintf_spec_X();
Suite *test_sprintf_spec_p();
Suite *test_sprintf_spec_other();

Suite *test_scanf_spec_d();
Suite *test_scanf_spec_c();
Suite *test_scanf_spec_i();
Suite *test_scanf_spec_e();
Suite *test_scanf_spec_E();
Suite *test_scanf_spec_g();
Suite *test_scanf_spec_G();
Suite *test_scanf_spec_o();
Suite *test_scanf_spec_s();
Suite *test_scanf_spec_u();
Suite *test_scanf_spec_x();
Suite *test_scanf_spec_X();
Suite *test_scanf_spec_p();
Suite *test_scanf_spec_other();

#endif