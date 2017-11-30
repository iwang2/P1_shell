#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include "shell.h"

/*
General Stuff:
1. Read a line at a time, parse to separate command from its arguments. Fork then exec the command; parent should wait until exec'd program exits to run the next command.

2. Read and separate multiple commands on one line with ";". 

3. simple redirection: > (stdout) and < (stdin)

4. simple pipes: ls | wc would run ls and use that output for wc input

Specific Requirements:
1. Every function you write must have a function header describing the arguments, return value, and what the function does (use modular design liberally).
2. README
3. Use separate C files as necessary.
4. makefile!!
*/

char ** parse_args(char * s){
  char * line = (char *)calloc(256, sizeof(char));
  strcpy(line, s);
  printf("%s\n", line);
  char ** args = (char **)calloc(6, sizeof(char *));
  char * s1 = line;
  int i;
  for (i = 0; s1; i ++) {
    args[i] = strsep(&s1, " ");
  }
  return args;
}

void execute(char * s){
  char * line = (char *)calloc(256, sizeof(char));
  strcpy(line, s);
  //printf("%s\n", line);
  char ** commands = (char **)calloc(6, sizeof(char *));
  char * s1 = line;
  int i;
  for(i = 0; s1; i++){
    commands[i] = clean(strsep(&s1, ";"));
    //printf("commands[%d]: \"%s\"\n", i, commands[i]);
  }

  for(i = 0; commands[i]; i++){
    execute_args(commands[i]);
  }
}

char * clean (char * s){
  //trim head whitespace
  int i = 0;
  while(s[i] == ' '){
    i++;
  }
  s += i;

  //trim ending whitespace
  char * end = s + strlen(s)-1;
  while(end > s && end[0] == ' '){
    end--;
  }
  *(end+1) = 0;
  
  return s;
}

void execute_args(char * s){
  char ** args = parse_args(s);
  int f = fork();
  if(!f){
    execvp(args[0], args);
    free(args);
    exit(0);
  }
  else{
    int status;
    wait(&status);
    
    if (strcmp(args[0], "cd") == 0) {
      //printf("%s\n", args[1]);
      cd(args[1]);
    }
    
    if (strcmp(args[0], "exit") == 0) {
      printf("Parent dipping\n");
      exit(0);
      printf("Potato\n");
    }
    
    int i = 0;
    while (args[i]) {
      i ++;
    }
    
    free(args);
  }
}

void cd(char * s){
  chdir(s);
  char dir[256];
  printf("current directory: %s\n", getcwd(dir, sizeof(dir)));
}

void greater(char * command, char * file){
  printf("Creating %s\n", file);
  // execute(command) goes somewhere here...
  int a = dup(1);
  int fd = open(file, O_CREAT | O_WRONLY, 0644);
  write(fd, command, sizeof(command));
  dup2(fd, 1);
  execute_args(command);
  dup2(a, 1);
  close(fd);
}
