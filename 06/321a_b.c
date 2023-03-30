#include <stdio.h>
#define MAX 27

void feltolt(int meret, char tomb[])
{
    // first_pos = 97
    // last_pos = 97 + 26 - 1
    for (int i = 0; i < meret - 1; i++)
    {
        tomb[i] = 'a' + i;
    }
    tomb[meret] = '\0';
}

int main()
{
    char betuk[MAX];
    int meret = MAX;
    feltolt(meret, betuk);
    
    /*for (int i = 0; i < meret; i++)
    {
        printf("%c", betuk[i]);
    } */
    printf("%s", betuk);
    puts("");
    return 0;
}