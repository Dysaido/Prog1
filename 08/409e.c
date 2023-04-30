#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

void proccess_to_file(FILE *in)
{
    puts("0,5-nél nagyobb számok szűrése...");
    FILE *out = fopen("out.txt", "w");
    if (out == NULL)
    {
        fprintf(stderr, "Hiba! out.txt file letrehozasa sikertelen!");
        exit(1);
    } 
    
    char inRow[MAX];
    int wrote = 0;
    while (fgets(inRow, MAX, in) != NULL)
    {
        inRow[strlen(inRow) - 1] = '\0';
        double tmp = atof(inRow);
        if (tmp > 0.5)
        {
            wrote++;
            fprintf(out, "%s\n", inRow);
        }
    }
    puts("szűrés vége");

    fclose(out);

    puts("out.txt bezárva");
    printf("out.txt-be kiírt számok mennyisége: %d db", wrote);
}

int main()
{
    FILE *fp = fopen("in.txt", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Hiba! in.txt file megnyitasa sikertelen!");
        exit(1);
    }
    puts("in.txt sikeresen megnyitva");
    proccess_to_file(fp);

    fclose(fp);
    return 0;
}