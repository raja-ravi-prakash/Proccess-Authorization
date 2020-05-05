#include <stdio.h>
#include <stdlib.h>

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
    fputs("sys.bat", file);
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