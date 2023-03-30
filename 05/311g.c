#include <stdio.h>
#include "prog1.h"

// Az s alapsztringben keressük a c karakter utolsó előfordulásának a helyét.
// Visszatérési érték: a c utolsó előfordulásának az indexe az s-ben.
// Ha nincs benne: -1 a visszatérési érték.
int rfind_char(string s, char c);

int main()
{
    printf("rfind_char(\"Abba\", \'b\') -> %d\n", rfind_char("Abba", 'b'));
    printf("rfind_char(\"Abba\", \'a\') -> %d\n", rfind_char("Abba", 'a'));
    printf("rfind_char(\"Abba\", \'x\') -> %d\n", rfind_char("Abba", 'x'));
    printf("rfind_char(\"Aladar\", \'b\') -> %d\n", rfind_char("Aladar", 'a'));
    return 0;
}

int rfind_char(string s, char c)
{
    int len = my_lenght(s);
    int ret = -1;
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == c) {
            ret = i;
        }
    }
    return ret;
}