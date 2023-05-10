#include <stdio.h>
#include <stdbool.h>

#define OSSZEG 90
#define SZORZAT 996300
#define MERET 45
#define ARRAY_SIZE 6

void keres(int count, int index, int numbers[], int sum, int multiply)
{
    if (count == 6)
    {
        if ((SZORZAT == multiply) && (OSSZEG == sum))
        {
            printf("6db szam: ");
            for (int i = 0; i < ARRAY_SIZE; ++i)
            {
                printf("%d ", numbers[i]);
            }
            puts("");
        }
        return;
    }
    
    for (int i = index + 1; i <= MERET - (ARRAY_SIZE - count); ++i)
    {
        numbers[count] = i;
        keres(count + 1, i, numbers, sum + i, multiply * i);
    }
}

int main()
{
    int numbers[6];
    keres(0, 0, numbers, 0, 1);

    return 0;
}