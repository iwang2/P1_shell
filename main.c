#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>

#include "shell.h"

int main(){
  execute("ls -l -a");

  /*
  strcpy(args, "echo potato");
  execute(parse_args(args));
  */
}
