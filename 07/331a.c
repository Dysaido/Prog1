#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int *return_array(int array[])
{
    return array;
}

int randint(int bottom, int top)
{
    int interval = top - bottom + 1;
    int random = rand();
    random = random % interval;
    random = random + bottom;
    return random;
}

void print_array(int array[])
{
    printf("A tömb elemei: ");
    for (int i = 0; i < MAX; ++i) 
    {
        printf("%d ", array[i]);
    }
    puts("");
}

int get_lowest(int *array)
{
    int tmp = array[0];
    for (int i = 1; i < MAX; ++i)
    {
        if (tmp > array[i]) tmp = array[i];
    }
    return tmp;
}

int get_highest(int *array)
{
    int tmp = array[0];
    for (int i = 1; i < MAX; ++i)
    {
        if (tmp < array[i]) tmp = array[i];
    }
    return tmp;
}

float get_avarange(int *array)
{
    int sum = 0;
    for (int i = 0; i < MAX; ++i)
    {
        sum += array[i];
    }
    return sum / (float)MAX;
}

int main()
{
    int array[MAX];
    for (int i = 0; i < MAX; ++i)
    {
        array[i] = randint(10, 99);
    }
    print_array(return_array(array));

    printf("Legkisebb elem: %d\n", get_lowest(array));
    printf("Legnagyobb elem: %d\n", get_highest(array));
    printf("Az elemek átlaga: %.2f\n", get_avarange(array));

    return 0;
}