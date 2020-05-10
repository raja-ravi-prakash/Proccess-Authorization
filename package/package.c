#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>

char **programs;
int files;

void freeMemory()
{
    int i;
    for (int i = 0; i < files; i++)
        free(programs[i]);
}

void allocateMemory()
{
    programs = (char **)malloc(files * sizeof(char *));
    int i;
    for (i = 0; i < files; i++)
        programs[i] = (char *)malloc(100 * sizeof(char));
}

void removeSpaces(char *str)
{
    int count = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i];
}

void runTheThing()
{
    system("type NUL > sys.bat");
    int i;
    char line[50];
    system("echo @echo off>>sys.bat");
    system("echo :loop>>sys.bat");
    for (i = 0; i < files; i++)
    {
        strcpy(line, "echo ");
        strcat(line, programs[i]);
        strcat(line, " /f>>sys.bat");
        system(line);
    }
    system("echo timeout /t 10>>sys.bat");
    system("echo goto loop>>sys.bat");
    freeMemory();
}

void getFileContents()
{
    FILE *file;
    int i;
    file = fopen("programs.name", "r");
    char line[20];
    fgets(line, 20, file);
    files = atoi(line);
    allocateMemory();
    for (i = 0; i < files; i++)
    {
        fgets(line, 20, file);
        removeSpaces(line);
        strcpy(programs[i], "taskkill /IM ");
        strcat(programs[i], line);
        int len = strlen(programs[i]);
        programs[i][len - 1] = ' ';
    }
    fclose(file);
    runTheThing();
}

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
    getFileContents();
    return 0;
}