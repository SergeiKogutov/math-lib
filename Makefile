SOURCES = s21_math_test.c
OBJECTS = $(SOURCES:.c=.o)
PROJECT_NAME	=s21_math
UNAME_S 		:= $(shell uname -s)
TEST_NAME		= ${PROJECT_NAME}_test
TEST_SRC		= $(TEST_NAME).c
Flags 			= -Werror -Wall -Wextra -std=c11
gcc 			= gcc $(Flags)
LIB_SOURCES		= $(shell find $(LIB_SRC_DIR) -name '*.c')
INC				:= $(shell find . -name '*.h')
OBJ 			= $(patsubst %.c,$(ODIR)/%.o, $(LIB_SOURCES))


ifeq ($(UNAME_S),Linux)
	TEST_CHECK_F= -lcheck
	OPEN_CMD = xdg-open
	ADD_LIB = -lm -lrt -lpthread
endif

ifeq ($(UNAME_S),Darwin)
	TEST_CHECK_F= $(shell pkg-config --cflags --libs check)
	OPEN_CMD = open
	ADD_LIB =
endif

all: s21_math.a gcov_report clean

s21_math.a: s21_math.o
	ar rcs s21_math.a *.o
	
s21_math.o:
	$(gcc) -c ./func/*.c

gcov_report: $(TEST_SRC) ./func/*.c
	$(gcc) -fprofile-arcs -ftest-coverage -g $^ -o $(TEST_NAME)_gcov_report $(TEST_CHECK_F) $(ADD_LIB)
	./$(TEST_NAME)_gcov_report
	lcov -t "report_gcov" -o report_gcov.info -c -d ./
	genhtml -o report report_gcov.info



test: $(TEST_SRC) $(PROJECT_NAME).a
	$(gcc) $^ -o $(TEST_NAME) $(TEST_CHECK_F) $(ADD_LIB)
	./$(TEST_NAME)

clean:
	rm -rf *.o
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf $(PROJECT_NAME).a
	rm -rf $(TEST_NAME)

rebuild: clean all