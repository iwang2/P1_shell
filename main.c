#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>

#include "shell.h"

int main(){
  printf("START OF PROGRAM OUTPUT\n");
  execute("ls -a -l");
  execute("echo potato");
}
