#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "penn_shell.h"

void exec_line(char *line) {
  char *mutable_line = (char *)calloc(1, sizeof(line));
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
				redirect_out(args, i);
				exit(0);
			}
			else if (!strcmp(args[i], "<")) {
				redirect_in(args, i);
				exit(0);
			}
			else if (!strcmp(args[i], "|")) {
				redirect(args, i);
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
		else if (!strcmp(args[0], "exit")) {
			exit(0);
		}
		int status;
		wait(&status);
		free(args);
	}
}

void redirect_out(char **args, int sign) {
	args[sign] = 0;
	int fd = open(args[sign + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	int out = dup(1);
	dup2(fd, 1);
	execvp(args[0], args);
	dup2(1, out);
	close(fd);
}

void redirect_in(char **args, int sign) {
	args[sign] = 0;
	int fd = open(args[sign + 1], O_RDONLY, 0644);
	int in = dup(0);
	dup2(fd, 0);
	execvp(args[0], args);
	dup2(0, in);
	close(fd);
}

void redirect(char **args, int sign) {
	char s1[256], s2[256], temp[8192];
	FILE *p1, *p2;
	int i;
	args[sign] = 0;
	for (i = 0; args[i]; i ++) {
		strcat(s1, args[i]);
		strcat(s1, " ");
	}
	*(s1 + strlen(s1) - 1) = 0;
	//printf("1st arg: %ld: %s\n", strlen(s1), s1);
	for (i = 1; args[sign + i]; i ++) {
		strcat(s2, args[sign + i]);
		strcat(s2, " ");
	}
	*(s2 + strlen(s2) - 1) = 0;
	//printf("2nd arg: %s\n", s2);
	p1 = popen(s1, "r");
	p2 = popen(s2, "w");
	while (fgets(temp, 8192, p1)) {
		fprintf(p2, "%s", temp);
	}
	pclose(p1);
	pclose(p2);
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
        char **args = (char **)calloc(sizeof(com));
	char *s = com;
	int i;
	for (i = 0; s; i ++) {
		args[i] = strsep(&s, delim);
		//printf("args[%d]: \"%s\"\n", i, args[i]);
	}
	return args;
}
