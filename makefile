all: penn_main.c penn_shell.c
	gcc penn_main.c penn_shell.c

clean:
	rm a.out
	rm *.txt

run: all
	./a.out
