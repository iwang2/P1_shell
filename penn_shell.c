#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "penn_shell.h"

void exec_line(char *line) {
	char *mutable_line = (char *)calloc(256, sizeof(char));
	strcpy(mutable_line, line);
	
	char **commands = split_commands(mutable_line);
	int i;
	for (i = 0; commands[i]; i ++) {
		printf("commands[%d]: \"%s\"\n", i, commands[i]);
		exec_command(commands[i]);
	}
	
	free(mutable_line);
	free(commands);
}

char **split_commands(char *line) {
	char **commands = (char **)calloc(10, sizeof(char *));
	char *s = line;
	int i;
	for (i = 0; s; i ++) {
		commands[i] = strsep(&s, ";");
	}
	return commands;
}

void exec_command(char *com) {
	com = clean(com);
	char **args = split_args(com);
	if (!fork()) {
		execvp(args[0], args);
		exit(0);
	}
	else {
		free(args);
	}
}

char *clean (char *com) {
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

char **split_args(char *com) {
	char **args = (char **)calloc(10, sizeof(char *));
	char *s = com;
	int i;
	for (i = 0; s; i ++) {
		args[i] = strsep(&s, " ");
		printf("args[%d]: \"%s\"\n", i, args[i]);
	}
	return args;
}
