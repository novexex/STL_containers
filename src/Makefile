CC = g++
CPPFLAGS = -lgtest
WWWFLAGS = -Wall -Werror -Wextra -std=c++17 -g

all: build

build:

gcov_report: test.cc s21_matrix_oop.cc
	@$(CC) --coverage -lcheck ${CPPFLAGS} ${CHECKFLAGS}
	@./a.out
	@lcov -t a.out -o rep.info --no-external -c -d .
	@genhtml -o report rep.info
	@open report/index.html

cppcheck:
	@cppcheck --enable=all --suppress=missingIncludeSystem . *.cc
	
linter:
	@cp ../materials/linters/CPPLINT.cfg .
	@python3 ../materials/linters/cpplint.py --extensions=cc *.cc *.h
	@rm -rf CPPLINT.cfg

leaks:
	@CK_FORK=no leaks --atExit -- ./a.out

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov

install_valgrind:
	brew install --HEAD LouisBrunner/valgrind/valgrind

install_cpch:
	brew install cppcheck

git: clean
	git add .
	git commit -m 'a'
	git push origin develop

clean: 
	@rm -rf *.gcda *.gcno *.info *.dSYM *.a *.o a.out test report
