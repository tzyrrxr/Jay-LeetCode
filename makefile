all:
	@gcc -Wall main.c -o a.exe
	@./a.exe

clean:
	rm -rf *.o *.exe *.*~ *.*un~ *un~ *~
