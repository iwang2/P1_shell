#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "penn_shell.h"

int main() {
  //exec_line("ls -a -l ; exit ; echo potato ; cat penn_main.c");
	//exec_line("pwd ; ls ; cd .. ; pwd ; cd P1_shell; echo Alexander Hamilton > b.txt ; wc b.txt ; wc < b.txt ; wc > c.txt < b.txt");
	//exec_line("ls -al | wc");
	/*printf("...\n");
	FILE *p = popen("ls | wc > b.txt", "r");
	char s[256];
	fgets(s, sizeof(s), p);
	printf("%s\n", s);*/
  exec_line("ls -a -l");
}
