#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char *fn = "/tmp/XYZ";
    char buffer[60];
    FILE *fp;
    uid_t ruid = getuid();
    uid_t euid = geteuid();

    scanf("%50s", buffer);

    seteuid(ruid);

    if (!access(fn, W_OK)) 
    {
	fp = fopen(fn, "a+");
        fwrite("\n", sizeof(char), 1, fp);
        fwrite(buffer, sizeof(char), strlen(buffer), fp);
        fclose(fp);
    }
    else
        printf("No permission \n");

    seteuid(euid);
    return 0;
}
