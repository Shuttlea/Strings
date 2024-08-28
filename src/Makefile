CC = gcc -Wall -Werror -Wextra -std=c11
# CHECK_FLAGS = $(shell pkg-config --cflags --libs check)
CHECK_FLAGS = -I$(shell brew --prefix check)/include -L$(shell brew --prefix check)/lib
COVERAGE=-fprofile-arcs -ftest-coverage

all: clean s21_string.a test gcov_report

s21_string.a: s21_string.c s21_string.h s21_sprintf.c s21_sprintf.h s21_scanf.c s21_scanf.h
	$(CC) -c s21_string.c s21_sprintf.c s21_scanf.c
	ar rcs s21_string.a s21_string.o s21_sprintf.o s21_scanf.o
	ranlib s21_string.a
	rm -rf *.o

test: s21_string.a s21_string_tests.c s21_string_tests.h test_*.c
	$(CC) $(COVERAGE) $(CHECK_FLAGS) -c *.c -g
	ar rcs s21_string.a s21_string.o s21_sprintf.o s21_scanf.o
	ranlib s21_string.a
#	$(CC) $(COVERAGE) -o s21_string_tests s21_string_tests.o test_*.o s21_string.a $(CHECK_FLAGS) -lm
	$(CC) $(CHECK_FLAGS) $(COVERAGE) -o s21_string_tests s21_string_tests.o test_*.o s21_string.a -lm
	rm -rf *.o
	./s21_string_tests; sleep 1

gcov_report: test
	gcov s21_string_tests.gcda
	gcovr --html-details -o report.html
	rm -rf *.gcno *.gcov *.gcda

clean:
	rm -rf *.o *.a *.html *.css *.gcno *.gcov *.gcda *.log
	rm -rf s21_string_tests

format:
	clang-format -i *.c *.h

check:
	clang-format -n --style=Google *.c *.h
	cppcheck --enable=all --force *.h *.c

memory:
	if [[ `uname` == "Darwin" ]]; then leaks --atExit -- ./s21_string_tests; fi
	if [[ `uname` == "Linux" ]]; then valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log ./s21_string_tests; sleep 1; fi

s21_sprintf: s21_sprintf.c s21_string.c
	$(CC) -lm s21_sprintf.c s21_string.c -o s21_sprintf
	rm -rf *.o

rebuild: clean all
