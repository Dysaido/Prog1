#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void my_strfry(char tomb[])
{
    int len = strlen(tomb);
    srand(time(NULL));
    for (int i = 0; i < len; ++i)
    {
        int j = rand() % len;
        printf("rand %d\n", j);
        char tmp = tomb[i];
        tomb[i] = tomb[j];
        tomb[j] = tmp; 
    }
}

int main()
{
    char text[] = "Ferenc";
    int len = strlen(text);
    printf("%s hossz %d\n", text, len);
    my_strfry(text);
    printf("%s hossz %d\n", text, len);
    return 0;
}