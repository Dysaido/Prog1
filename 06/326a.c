#include <stdio.h>
#include <stdlib.h>

/**
 * Hány db számot szeretnél bevinni?
    5
    1. szám: -2
    2. szám: 3
    3. szám: -7
    4. szám: 9
    5. szám: 2

    A bevitt számok abszolútértékei: 2, 3, 7, 9, 2
    A megadott számok: -2, 3, -7, 9, 2
*/
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

int main ()
{
    int array_size;
    puts("Hány db számot szeretnél bevinni?");
    scanf("%d", &array_size);

    int array[array_size];
    int abs_array[array_size];

    int temp_entry;
    for (int i = 1; i <= array_size; ++i)
    {
        printf("%d. szam: ", i);
        scanf("%d", &temp_entry);
        array[i - 1] = temp_entry;
    }

    for (int i = 0; i < array_size; ++i)
    {
        abs_array[i] = abs(array[i]);
    }
    printf("A bevitt számok abszolútértékei");
    print_array(array_size, abs_array);
    printf("A megadott számok");
    print_array(array_size, array);
    
    
    return 0;
}