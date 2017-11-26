#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>

#include "shell.h"

int main(){
  printf("\nSTART OF PROGRAM OUTPUT\n");
  
  printf("\ntesting clean:\n");
  char s[256] = "   hi how are you  ";
  printf("original string: \"%s\"\n", s);
  strcpy(s, clean(s));
  printf("cleaned string: \"%s\"\n", s);
  
  printf("\ntesting execute for multiple commands on one line:\n");
  execute("ls -a -l ; echo potato");

  printf("\ntesting execute for only one command:\n");
  execute("echo I hope this works");
  
  return 0;
}
