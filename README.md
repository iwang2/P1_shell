# P1_shell
Shell-ing out commands.
Fall, 2017.

### Collaborators:
Penn Wu, Ida Wang

### Features
Pass a string of arguments (1 set of commands) to be executed.

### Failed Features
We have not yet attempted the semicolon thing, as well as `cd` and `exit`. Basically, we only have two functions so testing the executing of a command from a string only happens in the main file, not from terminal input.

### Bugs and Other Stuff
Nothing so far.

### Function Headers
- `char ** parse_args(char * s)`
- `void execute(char * s)`