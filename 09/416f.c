#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10


int choice(const int n, const int tomb[])
{
    int index = rand() % n;
    return tomb[index];
}

int main()
{
    srand(time(NULL));
    int tomb[MAX] = {23, 34, 76, 19, 73, 97, 27, 93, 13, 88};
    
    printf("%d ", choice(MAX, tomb));
    return 0;
}