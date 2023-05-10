#include <stdio.h>
#include <stdlib.h>

#define OSSZEG 90
#define SZORZAT 996300

void keres(int index, int intervalsize, int interval[], int tipp[], int aktualis_osz, int aktualis_szor)
{
    if (index == 6)
    {
        if ((SZORZAT == aktualis_szor) && (OSSZEG == aktualis_osz))
        {
            printf("6db szam: ");
            for (int i = 0; i < index; ++i)
            {
                printf("%d ", tipp[i]);
            }
            puts("");
            exit(0);
        }
        return;
    }
    for (int i = 0; i < intervalsize; ++i)
    {
        tipp[index] = interval[i];
        keres(index + 1, intervalsize, interval, tipp, aktualis_osz + interval[i], aktualis_szor * interval[i]);
    }
}

int main()
{
    int interval[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45};
    int interalsize = sizeof(interval) / sizeof(interval[0]);
    int tipp[6];
    keres(0, interalsize, interval, tipp, 0, 1);
    /*for (int i = 1; i < 46; ++i)
    {
        printf("%d, ", i);
    }
    puts("");*/
    return 0;
}