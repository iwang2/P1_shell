#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "penn_shell.h"

int main() {
	//exec_line("ls -a -l ; exit ; echo potato ; cat penn_main.c");
	exec_line("pwd ; ls ; cd .. ; pwd ; cd P1_shell; ls -a -l > a.txt");
}
