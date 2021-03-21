/* vulp.c */
#include <string.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
char * fn = "/tmp/XYZ";
char buffer[60];
FILE *fp;
uid_t uid = getuid();
uid_t euid = geteuid();
/* get user input */
scanf("%50s", buffer );
seteuid(uid);
if(fopen(fn,"a+")){
	fwrite("\n", sizeof(char), 1, fp);
	fwrite(buffer, sizeof(char), strlen(buffer), fp);
	fclose(fp);
}
else printf("No permission \n");

seteuid(euid);
}
