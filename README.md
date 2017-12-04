# P1_shell
Shell-ing out commands.
Fall, 2017.

## Collaborators:
Penn Wu, Ida Wang

## Weird Stuff to Take Note of
There are two sets of files, the first that look normal-ish and the second starting with `penn_`. This is because we had originally started coding on the same files, but eventually it had seemed like redirection was not working, so Penn created a separate set of files to reformat everything from ground up to make our program cleaner. Eventually we figured out that our intial redirection function seemed like it was not working because we had been testing `cd` right before it, but by then Penn had already transferred most of the functions to his new files anyway. So our initial written functions are still the same--just moved over so that they're cleaner with some minor adjustments. See **Files and Functions** for further "detail".

## Working Features
- Fork and execute commands 
- Run multiple commands on a single line separated by `;` (there does not need to be a space between the commands and `;`)
- Simple redirection with `>`, `<`
- Simple pipes with `|`

## Nonexistent Features
- Redirecting/piping more than once per command (so you can't do something like `a | b | c | d` or `wc < a.txt > b.txt`)

## Bugs
- Memory allocation issues have mostly been fixed, but piping will only take up to 256 bytes from the first argument, and 256 bytes from the second.
- Putting an ampersand in a command will not run the command in the background. Calling `gedit & ; ls`, for example, will instead launch gedit and create a new file called "&".
- In order to interact with our program, you must edit penn_main.c (or another main C file) and call exec_line(). Reading commands from a text file, for example, has not been implemented.

## Files and Functions
### `makefile`
Compiles and runs all the `penn_*` files. 

### `penn_main.c`
Testing the more complicated functions. Some are commented out.

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

### `main.c`, `shell.c`, `shell.h` 
Essentially correlate with all of the `penn_*` files. `main.c` tests some of the simpler functions, like `clean()`, and has perhaps easier to read output. All the functions up to redirecting stdin and piping work. 
