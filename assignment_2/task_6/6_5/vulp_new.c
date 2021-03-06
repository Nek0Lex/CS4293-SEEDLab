#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char *fn = "/tmp/XYZ";
    char buffer[60];
    FILE *fp;
    uid_t real_uid = getuid();
    uid_t eff_uid = geteuid();

    scanf("%50s", buffer);

    seteuid(real_uid);

    fp = fopen(fn, "a+");
    if (fp) // Instead of checking by access(), directly check if open() returns proper pointer. **Note that it should not be compared with -1 as the textbook suggests.**
    {
        fwrite("\n", sizeof(char), 1, fp);
        fwrite(buffer, sizeof(char), strlen(buffer), fp);
        fclose(fp);
    }
    else
        printf("No permission \n");

    seteuid(eff_uid);
}
