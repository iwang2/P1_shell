#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "penn_shell.h"

void exec_line(char *line) {
	char *mutable_line = (char *)calloc(256, sizeof(char));
	strcpy(mutable_line, line);
	
	char **commands = split(mutable_line, ";");
	int i;
	for (i = 0; commands[i]; i ++) {
		commands[i] = clean(commands[i]);
		printf("commands[%d]: \"%s\"\n", i, commands[i]);
		exec_command(commands[i]);
	}
	
	free(mutable_line);
	free(commands);
}


void exec_command(char *com) {
	com = clean(com);
	char **args = split(com, " ");
	int i;
	if (!fork()) {
		for (i = 0; args[i]; i ++) {
			if (!strcmp(args[i], ">")) {
				greater(args, i);
				exit(0);
			}
			else if (!strcmp(args[i], "<")) {
				printf("Has a lesser sign\n");
				exit(0);
			}
			else if (!strcmp(args[i], "|")) {
				printf("Has a pipe\n");
				exit(0);
			}
		}
		execvp(args[0], args);
		exit(0);
	}
	else {
		if (!strcmp(args[0], "cd")) {
			chdir(args[1]);
		}
		if (!strcmp(args[0], "exit")) {
			exit(0);
		}
		int status;
		wait(&status);
		free(args);
	}
}

void greater(char **args, int sign) {
	printf("Running greater\n=====\n");
	int i;
	for (i = 0; args[i]; i ++) {
		//printf("args[%d]: \"%s\"\n", i, args[i]);
	}
	args[sign] = 0;
	for (i = 0; args[i]; i ++) {
		//printf("args[%d]: \"%s\"\n", i, args[i]);
	}
	int fd = open(args[sign + 1], O_CREAT | O_WRONLY, 0644);
	int out = dup(1);
	dup2(fd, 1);
	execvp(args[0], args);
	dup2(1, out);
	close(fd);
}

char *clean(char *com) {
	while (com[0] == ' ') {
		com ++;
	}
	
	char *end = com + strlen(com) - 1;
	while (end > com && end[0] == ' ') {
		end --;
	}
	*(end + 1) = 0;
	return com;
}

char **split(char *com, char *delim) {
	char **args = (char **)calloc(10, sizeof(char *));
	char *s = com;
	int i;
	for (i = 0; s; i ++) {
		args[i] = strsep(&s, delim);
		//printf("args[%d]: \"%s\"\n", i, args[i]);
	}
	return args;
}
