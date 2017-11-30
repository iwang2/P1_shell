#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "penn_shell.h"

int main() {
	exec_line("ls -a -l ; echo potato");
}
