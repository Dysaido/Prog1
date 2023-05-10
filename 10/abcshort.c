#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUF 100
#define MAX_HALLGATO 100
// Írjunk programot, ami beolvassa ezt a fájlt, majd kiírja az stdout-ra a PTI-s hallgatók nevét ábécésorrendben, nagy kezdőbetűkkel ellátva. Példa:

typedef char* string;

typedef struct {
    char nev[MAX_BUF];
    char szak[MAX_BUF];
    int kor;
} Hallgato;

Hallgato* beolvas(string name, int *hallgatokszama)
{
    FILE *in = fopen(name, "r");
    if (in == NULL)
    {
        fprintf(stderr, "Sikertelen fajlbeolvasas (%s)!", name);
        return NULL;
    }

    Hallgato* hallgatok = malloc(MAX_HALLGATO * sizeof(Hallgato));
    if (hallgatok == NULL)
    {
        fprintf(stderr, "Sikertelen memoria foglalas!");
        fclose(in);
        return NULL;
    }
    int i;
    char row[MAX_BUF];
    for (i = 0; fgets(row, sizeof(row), in) != NULL; ++i)
    {
        string token = strtok(row, ",");
        strncpy(hallgatok[i].nev, token, sizeof(hallgatok[i].nev) - 1);
        token = strtok(NULL, ",");
        hallgatok[i].kor = atoi(token);
        token = strtok(NULL, ",");
        strncpy(hallgatok[i].szak, token, sizeof(hallgatok[i].szak) - 1);

    }
    *hallgatokszama = i;

    fclose(in);
    return hallgatok;
}

void swap(Hallgato* a, Hallgato* b)
{
    Hallgato tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubrendez(int n, Hallgato* hallgato)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (strcmp(hallgato[j].nev, hallgato[j + 1].nev) > 0)
            {
                swap(&hallgato[j], &hallgato[j + 1]);
            }
        }
    }
}

int main()
{
    string name = "nevek.csv";
    int hallgatokszama = 0;
    Hallgato* hallgatok =  beolvas(name, &hallgatokszama);
    if (hallgatok == NULL)
    {
        fprintf(stderr, "Program kilepes");
        exit(1);
    }
    for (int i = 0; i < hallgatokszama; ++i)
    {
        string nev = hallgatok[i].nev;
        char upp = nev[0] ^ 32;
        if (i == hallgatokszama - 1)
        {
            printf("%c%s", upp, ++nev);
            --nev;
            break;
        }
        printf("%c%s, ", upp, ++nev);
        --nev;
    }
    puts("");
    free(hallgatok);
    return 0;
}