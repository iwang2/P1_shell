all: main.c shell.c
	gcc main.c shell.c

clean:
	rm a.out

run: all
	./a.out
