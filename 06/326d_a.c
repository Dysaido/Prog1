#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Hány db random számot kérsz?
    5
    Alsó határ: 1
    Felső határ (zárt intervallum): 90

    A generált számok: 7 23 88 45 65
*/
int randint(int bottom, int top)
{
    int random = rand();
    int interval = top - bottom + 1;
    random = random % interval;
    random = bottom + random;
    return random;
}

int main()
{
    int num, bottom, top;
    printf("Hány db random számot kérsz?\n");
    scanf("%d", &num);
    
    printf("Alsó határ: ");
    scanf("%d", &bottom);

    printf("Felső határ (zárt intervallum): ");
    scanf("%d", &top);

    int nums[num];
    srand(time(NULL));
    printf("A generált számok: ");
    for (int i = 0; i < num; i++) 
    {
        int tmp = randint(bottom, top);
        nums[i] = tmp;
        printf("%d ", tmp);
    }

    puts("");
    return 0;
}