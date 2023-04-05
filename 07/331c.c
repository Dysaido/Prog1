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
int any_match(string str, int (*predicate)(int))
{
    for (int i = 0; str[i] != '\0'; ++i)
    {
        char c = str[i];
        if (predicate(c))
        {
            return 1;
        }
    }

    return 0;
}

// Teszteset, tesztelni kivant string
// Visszater igaz ill. hamis ertekkel
int isvalidpsw(string str)
{
    int len = strlen(str) - 1;
    int ret = 0;
    if (len >= 8)                               // Legalabb 8 karaktert tartalmaz
    {
        if (any_match(str, isdigit)            // Van-e benne szam 
                && any_match(str, islower)     // Van-e benne kisbetu
                && any_match(str, isupper))    // Van-e benne nagybetu
        {        
            ret = 1;   
        }
        
    }
    return ret;
}

int main()
{
    printf("Adj meg jelszavakat '*' végjelig!\n");

    string str = get_string("jelszó: ");
    do {
        if (isvalidpsw(str) == 0) {
            puts("gyenge jelszó");
        }
        str = get_string("jelszó: ");
    } while (strcmp("*", str) != 0);
    
    return 0;
}