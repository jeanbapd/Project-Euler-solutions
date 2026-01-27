
CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c11 -lm

.PHONY: update clean

#Update README
update:
	mkdir -p bin
	@$(CC) $(CFLAGS) utils/update_readme.c -o bin/update_readme
	./bin/update_readme

# Compile a problem
problem_%:
	mkdir -p bin
	$(CC) $(CFLAGS) problems/*/$@.c -o bin/$@ -lm
	./bin/$@

clean:
	rm -rf bin/