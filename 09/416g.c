#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a=*b;
    *b = tmp;
}

void shuffle(int n, int tomb[])
{
    srand(time(NULL));
    for (int i = 1; i <= n - 1; ++i)
    {
        int j = rand() % (i + 1);

        swap(&tomb[i], &tomb[j]);
    }
}

void print_array(int lenght, int array[])
{
    printf("A tömb elemei: ");
    for (int i = 0; i < lenght; ++i) 
    {
        printf("%d ", array[i]);
    }
    puts("");
}

int main()
{
    int arr[] = {11, 13, 17, 23, 28, 31, 32, 33};
    int len = sizeof(arr) / sizeof(arr[0]);
    print_array(len, arr);
    shuffle(len, arr);
    print_array(len, arr);
    return 0;
}