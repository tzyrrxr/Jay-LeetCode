CC = gcc
CFLAGS = -g -Wall -Werror
TARGET = main.c

all: clean
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(TARGET) || { echo "Compile Failure"; exit 1; }
	@echo "Done."
	@echo ">"
	@./a.out

clean:
	@rm -rf *.*~ \
		*.*.swo \
		*~ \
		*un~ \
		*.*.un \
		*.*.*.un~ \
		*.*.un~ \
		.*.un~ \
		.*.*.un~ \
		a.exe \
		a.out
