#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 512

double get_sum_from_file(FILE *fp)
{
    char row[MAX];
    double ret = 0.00;

    while (fgets(row, MAX, fp) != NULL)
    {
        row[strlen(row) - 1] = '\0';
        row[1] = '.';
        //printf("%s\n", row);
        ret += atof(row);
    }
    return ret;
}

int main()
{
    FILE *fp = fopen("valos_szamok.txt", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "HIBA! Nem sikerult a filejt megnyitni.");
        exit(1);
    }
    printf("Osszeg: %.20lf\n", get_sum_from_file(fp));
    fclose(fp);
    return 0;
}