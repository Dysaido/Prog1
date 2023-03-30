#include "prog1.h"

//////////////////////////////////////////////////////////////////////////////
//
//   Implementation
//

#include <stdio.h>
#include <string.h>

#define BUFSIZE 1024

/**
 * Ez egy dinamikusan lefoglalt sztringet ad vissza,
 * amit a hívó oldalon majd valamikor fel kell szabadítani.
 */
string get_string(const char* prompt)
{
    char buf[BUFSIZE];

    printf("%s", prompt);
    fgets(buf, sizeof(buf), stdin);
    buf[strlen(buf) - 1] = '\0';

    return strdup(buf);
}

int my_lenght(const string str) 
{
    int cnt = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        ++cnt;
    }
    return cnt;
}