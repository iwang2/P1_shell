#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#include <sys/stat.h>
#include <sys/types.h>

#include "shell.h"

int main(){
  printf("\nSTART OF PROGRAM OUTPUT\n");
  
  printf("\ntesting clean:\n");
  char s[256] = "   hi how are you  ";
  printf("\toriginal string: \"%s\"\n", s);
  strcpy(s, clean(s));
  printf("\tcleaned string: \"%s\"\n", s);

  printf("testing clean with cleaned string:\n");
  printf("\toriginal string: \"%s\"\n", s);
  strcpy(s, clean(s));
  printf("\tcleaned string: \"%s\"\n", s);
  
  printf("\ntesting execute for multiple commands on one line:\n");
  execute("ls -a -l ; echo potato; echo 3");

  printf("\ntesting execute for only one command:\n");
  execute("cd ..");
  
  //greater("echo potato", "bob.txt");
  
  int fd = open("array.txt", O_CREAT | O_WRONLY, 0644);
  write(fd, "hello", sizeof("hello"));
  close(fd);
  
  printf("%s\n", strerror(errno));
  
  return 0;
}
