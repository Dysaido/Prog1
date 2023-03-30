#include <stdio.h>
#include "prog1.h"

// Az s sztringben a c karakter hányszor fordul elő?
int char_count(string s, char c);

int main()
{
    printf("char_count(\"Abba\", \'b\') -> %d\n", char_count("Abba", 'b'));
    printf("char_count(\"Abba\", \'a\') -> %d\n", char_count("Abba", 'a'));
    printf("char_count(\"Abba\", \'x\') -> %d\n", char_count("Abba", 'x'));
    return 0;
}

int char_count(string s, char c)
{
    int len = my_lenght(s);
    int ret = 0;
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == c) {
            ret++;
        }
    }
    return ret;
}