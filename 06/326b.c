#include <stdio.h>

void print_array(int size, int array[])
{
    for(int i = 0; i < size; ++i) 
    {
        printf(" %d", array[i]);
        if (i + 1 != size)
        {
            printf(",");
        }
    }
    puts("");
}

int main()
{
    printf("Adj meg 0 végjelig egész számokat az [1, 99] intervallumból!\n");

    int n;
    int numbers[100] = {0};
    int count = 0;
    do {

        scanf("%d", &n);
        if (n >= 1 && n <= 99)
        {   
            if (!numbers[n])
            {
                numbers[n] = 1;
                count++;
            }
        } 
        else if (n != 0)
        {
            printf("Ez a szám kívül esik az elfogadható intervallumon!\n");
        }
    } while(n != 0);

    printf("%d db különböző szám lett megadva.\n", count);

    for (int i = 1; i <=99; ++i) 
    {

        if (numbers[i])
        {
            printf("%d ", i);
        }
    }
    puts("");

    return 0;
}