##
## EPITECH PROJECT, 2022
## BSQ
## File description:
## Makefile
##

.SILENT:

OUT = bsq
OUT_T = unit_tests
COVERAGE_DIR = coverage

SRC = bsq.c \
	process.c \
	read.c
TESTS = $(wildcard tests/*.c)
OBJ = $(SRC:.c=.o)

all: $(OUT)

%.o : %.c
	gcc -o $@ -c $< -I./includes -g

$(OUT): $(OBJ)
	gcc -o $(OUT) $(OBJ) -I./includes -g
	make clean

unit_tests: fclean $(OUT)
	./tests/tests_maps.sh bsq
	gcc -o $(OUT_T) $(TESTS) $(SRC:bsq.c=) --coverage -lcriterion

run_tests: unit_tests
	./$(OUT_T)

coverage: run_tests
	rm -rf $(COVERAGE_DIR)
	gcovr --branches --exclude tests
	mkdir $(COVERAGE_DIR)
	gcovr --branches --exclude tests --html-details -o \
	./$(COVERAGE_DIR)/index.html
	make fclean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OUT)
	rm -f *.g*
	rm -f $(OUT_T)

c_fclean : fclean
	rm -rf $(COVERAGE_DIR)

re : fclean $(OUT)
