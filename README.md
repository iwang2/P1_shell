# P1_shell
Shell-ing out commands.
Fall, 2017.

## Collaborators:
Penn Wu, Ida Wang

## Weird Stuff
We originally started working in

## Working Features
- Fork and execute commands 
- Run multiple commands on a single line separated by `;` (there does not need to be a space between the commands and `;`)
- Simple redirection with `>`, `<`
- Simple pipes with `|`

## Nonexistent Features
- redirecting/piping more than once per command (so you can't do something like `a | b | c | d`)
- There's not really much else that we tried to implement.

## Bugs
- The size of a line to be executed cannot be more than 1024 bytes long.
- I WILL FIX THIS!!!

## Files and Functions
### `penn_main.c`
Contains tests for the majority of functions in `penn_shell.h`

### `penn_shell.h`
Holds the file headers for `penn_shell.c`

### `penn_shell.c`
**`char * clean`**
- INPUT: `char * com`
- RETURNS: pointer to the (possibly) new start of `com` with leading and trailing whitespace removed
- adjusts pointer location as necessary to remove leading whitespace, and adds new terminating '\0' for trailing whitespace

**`char ** split`**
- INPUT: `char * com`, `char * delim`
- RETURNS: an array of strings where each entry is a token of `com` separated by `delim`

**`void redirect_out`**
- INPUT: `char ** args`, `int sign`
- RETURNS: void
- simple redirection of stdout; essentially `<COMMAND> > <FILE>`
- the given int `sign` marks the array slot where `>` would be located in `args`, the intiial array of commands
- runs the commands (`args` up until `>`) and redirects their output from stdout into the file (array `args` after `>`)

**`void redirect_in`**
- INPUT: `char ** args`, `int sign`
- RETURNS: void
- simple redirection of stdin (`<COMMAND> < <FILE>`)
- works the same way as `redirect_out`, except that stdin is redirected instead of stdout

**`void redirect`**
- INPUT: `char ** args`, `int sign`
- RETURNS: void
- simple piping; works similar to all the other redirect commands in that `sign` marks the location in `args` where the pipe character `|` is located
- redirects output from running `args` before `sign` into `args` after `sign`

**`void exec_line`**
- INPUT: `char * line`
- RETURNS: void
- will split `line` on potential semicolons, and run `exec_command` on each individual command

**`void exec_command`** 
- INPUT: `char * com`
- RETURNS: void
- forks and runs the single command `com` in the child and exits (except in the case of `cd` and `exit`, which are done by the parent)
