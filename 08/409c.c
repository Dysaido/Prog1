#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 512

int get_number_of_lines(const char* name)
{
    FILE *fp = fopen(name, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Hiba! A %s nevű file-t nem sikerült megnyitni!\n", name);
        exit(1);
    }
    int count = 0;
    char row[MAX];
    while (fgets(row, MAX, fp) != NULL)
    {
        count++;
    }

    fclose(fp);
    return count;
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Hiba! Adja meg egy szöveges állomány nevét!\n");
        exit(1);
    }

    printf("%d\n", get_number_of_lines(argv[1]));
    return 0;
}