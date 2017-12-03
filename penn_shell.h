void exec_line(char *line);
void exec_command(char *com);
void redirect_out(char **args, int sign);
void redirect_in(char **args, int sign);
void redirect(char **args, int sign);
char *clean(char *com);
char **split(char *com, char *delim);
