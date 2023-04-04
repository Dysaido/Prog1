#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF_LENGHT 2 << 9

typedef char* string;

string get_string(const string str)
{
    printf("%s", str);

    char tmp[BUF_LENGHT];
    fgets(tmp, BUF_LENGHT, stdin);
    tmp[strlen(tmp) - 1] = '\0';

    return strdup(tmp);
}
/*
    Bemeneti string, \0 vegjelig olvassa ki egyesevel a karaktereket
    Feltetel, karakter ASCII kodjat varja, igaz-hamis visszateresi ertekel
    Visszater igazal/hamisal felteteltol fuggoen
*/
int all_match(string str, int (*predicate)(int input))
{
    int ret = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        char c = str[i];
        if (predicate(c))
        {
            ret = 1;
        }
    }

    return ret;
}

// Teszteset, tesztelni kivant string
// Visszater igaz ill. hamis ertekkel
int test(string str)
{
    int len = strlen(str) - 1;
    int ret = 0;
    if (len >= 8)                               // Legalabb 8 karaktert tartalmaz
    {
        if (all_match(str, &isdigit)            // Van-e benne szam 
                && all_match(str, &islower)     // Van-e benne kisbetu
                && all_match(str, &isupper))    // Van-e benne nagybetu
        {        
            ret = 1;   
        }
        
    }
    return ret;
}

int main()
{
    printf("Adj meg jelszavakat '*' végjelig!\n");

    while(1)
    {
        string str = get_string("jelszó: ");
        if (strcmp("*", str) == 0) 
        {
            break;
        } 
        else if (test(str) == 0) {
            puts("gyenge jelszó");
        }
    }

    return 0;
}