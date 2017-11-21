#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

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
