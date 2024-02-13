all: gcov_report
clean:
	rm -rf test test_sharp test_sscanf test_sprintf *.o *.a *.gcno *.html *.gcda
	rm -rf lcov_report lcov_report.info
clang_test:
	clang-format -n -style=Google *.c *.h */*.c

s21_string.o:
	gcc -c -Wall -Wextra -Werror -std=c11 s21_string/*.c s21_sprintf/s21_sprintf.c s21_sscanf/s21_sscanf.c

s21_string.a: s21_string.o
	ar rc s21_string.a *.o
	ranlib s21_string.a

test:
	gcc -Wall -Wextra -Werror -o test s21_string_test.c s21_string/*.c --coverage -lcheck -lm -lpthread -lsubunit 
	 ./test

test_sharp: 
	gcc -Wall -Wextra -Werror -o test_sharp s21_sharp_tests.c s21_string/*.c --coverage -lcheck -lm -lpthread -lsubunit 
	./test_sharp
test_sprintf:
	gcc -Wall -Wextra -Werror -o test_sprintf s21_sprintf/s21_sprintf_test.c s21_sprintf/s21_sprintf.c s21_string/*.c --coverage -lcheck -lm -lpthread -lsubunit 
	 ./test_sprintf

test_sscanf:
	gcc -Wall -Wextra -Werror s21_sscanf/s21_sscanf_test.c s21_sscanf/s21_sscanf.c s21_string/*.c -o test_sscanf --coverage -lcheck -lm -lpthread -lsubunit
	./test_sscanf 

gcov_report: test test_sharp test_sscanf test_sprintf
	gcovr --html >> report.html

lcov_report:test test_sharp test_sprintf test_sscanf 
	lcov -t "lcov_report" -o lcov_report.info -c -d . 
	genhtml -o lcov_report lcov_report.info
