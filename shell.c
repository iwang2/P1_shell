#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include "shell.h"

/*
General Stuff:
1. Read a line at a time, parse to separate command from its arguments. Fork then exec the command; parent should wait until exec'd program exits to run the next command.

2. Read and separate multiple commands on one line with ";". 

3. TBC
4. TBC

Specific Requirements:
1. Every function you write must have a function header describing the arguments, return value, and what the function does (use modular design liberally).
2. README
3. Use separate C files as necessary.
4. makefile!!
*/

char ** parse_args(char * s){
  char line[256];
  strcpy(line, s);
  printf("parse args: %s\n", line);
  
  char ** thing = calloc(sizeof(char *), 6);
  char * s1 = line;
  int i = 0;
  while(s1){
    thing[i] = strsep(&s1, " ");
    //printf("things[%d]: %s\n", i, thing[i]);
    i++;
  }
  for(int i = 0; thing[i]; i++){
    printf("things[%d]: %s\n", i, thing[i]);
  }
  return thing;
}

void execute(char * thing){
  printf("%s\n", thing);
  char ** args = parse_args(thing);
 
  for(int i = 0; args[i]; i++){
    printf("args[%d]: %s\n", i, args[i]);
  }
  
  int f = fork();
  int status;
  if(!f){
    execvp(args[0], args);
  }
  else{
    wait(&status);
  }
}
