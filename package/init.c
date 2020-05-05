#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>

char **programs;
int files;

void freeMemory()
{
    int i;
    for (int i = 0; i < files; i++)
        free(programs[i]);
}

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
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

int main()
{
    getFileContents();
    return 0;
}