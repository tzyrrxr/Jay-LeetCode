CC := gcc
CFLAGS := -g -Wall -Werror
TARGET := main.c

.PHONY: all clean

#all: clean build

build:
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(TARGET) || { echo "Compile Failure"; exit 1; }
	@echo "Done >"

clean:
	@echo "CLEAR"
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
