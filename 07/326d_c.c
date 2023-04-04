#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>

#define MAX 100

int randint(int bottom, int top)
{
    int interval = top - bottom + 1;
    int random = rand();
    random = random % interval;
    random = random + bottom;
    return random;
}

void print_array(int size, int array[])
{
    printf("A tömb elemei: ");
    for (int i = 0; i < size; ++i) 
    {
        printf("%d ", array[i]);
    }
    puts("");
}

void array_short(int size, int array[])
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j =  i + 1; j < size; ++j)
        {
            if (array[j] < array[i])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    int size, bottom, top;
    printf("Hány db random számot kérsz? ");
    scanf("%d", &size);

    printf("Alsó határ: ");
    scanf("%d", &bottom);
    printf("Felső határ (zárt intervallum): ");
    scanf("%d", &top);
    int nums[MAX];
    
    for (int i =0; i < size; ++i) 
    {
        nums[i] = randint(bottom, top);
        Sleep(100);
    }
    // print_array(size, nums);
    
    array_short(size, nums);
    print_array(size, nums);


    return 0;
}