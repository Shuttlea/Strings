#include "s21_string_tests.h"

int main(void) {
  int fail = 0;
  Suite *s21_string_test[] = {
      test_strlen(),         test_strncmp(),
      test_strncpy(),        test_strncat(),
      test_strchr(),         test_strrchr(),
      test_strstr(),         test_strcspn(),
      test_strpbrk(),        test_strtok(),
      test_strerror(),       test_memchr(),
      test_memcmp(),         test_memcpy(),
      test_memset(),         test_to_lower(),
      test_to_upper(),       test_insert(),
      test_trim(),           test_sprintf_spec_d(),
      test_sprintf_spec_s(), test_sprintf_spec_f(),
      test_sprintf_spec_c(), test_sprintf_spec_u(),
      test_sprintf_spec_i(), test_sprintf_spec_e(),
      test_sprintf_spec_E(), test_sprintf_spec_g(),
      test_sprintf_spec_G(), test_sprintf_spec_o(),
      test_sprintf_spec_x(), test_sprintf_spec_X(),
      test_sprintf_spec_p(), test_sprintf_spec_other(),
      test_scanf_spec_d(),   test_scanf_spec_c(),
      test_scanf_spec_i(),   test_scanf_spec_e(),
      test_scanf_spec_E(),   test_scanf_spec_g(),
      test_scanf_spec_G(),   test_scanf_spec_o(),
      test_scanf_spec_s(),   test_scanf_spec_u(),
      test_scanf_spec_x(),   test_scanf_spec_X(),
      test_scanf_spec_p(),   test_scanf_spec_other(),
  };

  for (int i = 0; i < SUITE_COUNT; i++) {
    SRunner *test_set_runner = srunner_create(s21_string_test[i]);
    srunner_set_fork_status(test_set_runner, CK_NOFORK);
    srunner_run_all(test_set_runner, CK_NORMAL);  // спасает от утечек
    fail += srunner_ntests_failed(test_set_runner);
    srunner_free(test_set_runner);
  }

  return fail == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
