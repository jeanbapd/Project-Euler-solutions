
CC = gcc
CFLAGS = -Wall -Wextra -O3 -std=gnu2x -lm
SRCS = $(wildcard problems/*.c)
OBJ = $(SRCS:%.c=%.o)

.PHONY: update clean

#Update README
all: $(OBJ)

update:
	mkdir -p bin
	@$(CC) $(CFLAGS) utils/update_readme.c -o bin/update_readme
	./bin/update_readme

# Compile a problem
problem_%.out: $(OBJ)
	mkdir -p bin
	@$(CC) $(CFLAGS) problems/$(subst .out,.o,$@) -o bin/$@

clean:
	rm -f problems/*.o
	rm -rf bin/