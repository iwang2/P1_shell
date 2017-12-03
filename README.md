# P1_shell
Shell-ing out commands.
Fall, 2017.

## Collaborators:
Penn Wu, Ida Wang

## Weird Stuff

## Working Features
Pass one or more commands in a single line to be executed.

## Failed Features
We have not yet attempted the semicolon thing, as well as `cd` and `exit`. Basically, we only have two functions so testing the executing of a command from a string only happens in the main file, not from terminal input.

## Nonexistent Features

## Bugs

## Files and Functions

### `penn_shell.c`
**`char * clean`**
- INPUT: `char * com`
- RETURNS: pointer to the start of com with leading and trailing whitespace removed

**`char ** split`**
- INPUT: `char * com`, `char * delim`
- RETURNS: an array of strings where each entry is a token of `com` separated by `delim`

**`void redirect_out`**
- INPUT: `char ** args`, `int sign`
- simple redirection of stdout; essentially `<COMMAND> > <FILE>`
- the given int `sign` marks the place where `>` would be located in the initial command
- runs the commands (array `args` up until `>`) and redirects their output from stdout into the file (array `args` after `>`)

`void redirect_in (char ** args, int sign)`
- simple redirection of stdin (`<COMMAND> < <FILE>`)
- works the same way as `redirect_out`, except that stdin is redirected instead of stdout

`void redirect (char ** args, int sign)`
- simple piping

`void exec_line (char * line)`

`void exec_command (char * com)`