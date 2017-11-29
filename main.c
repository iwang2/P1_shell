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
  greater("ls", "array.txt");
  
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

  /*
  int fd = open("array.txt", O_CREAT | O_WRONLY, 0644);
  char thing[sizeof("hello")] = "hello";
  write(fd, thing, sizeof(thing));
  printf("%s\n", strerror(errno));
  close(fd);

  struct stat st;
  stat("array.txt", &st);
  printf("file size: %d\n", (int)st.st_size);
  printf("permissions: %o\n", st.st_mode);
  */
  
  return 0;
}
