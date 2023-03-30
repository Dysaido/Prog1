#include "prog1.h"
#include <stdio.h>
#include <string.h>

/*

Bemenet: sztringeket tartalmazó tömb. Számoljuk meg, hogy a bemenetben
hány olyan sztring van, melynek a hossza legalább 2 s az
első karaktere egyezik az utolsó karakterével. A visszatérési
érték ezen feltételeket kielégítő sztringek száma legyen.

Példák (Python kóddal, majd át kell írni C-be):

match_ends(["aba", "xyz", "aa", "x", "bbb"])    ->  3
match_ends(["", "x", "xy", "xyx", "xx"])        ->  2
match_ends(["aaa", "be", "abc", "hello"])       ->  1

*/

int match_ends(int n, string words[]);

int main()
{
    string szavak1[] = { "aba", "xyz", "aa", "x", "bbb" };
    int szavak1_meret = 5;

    // match_ends() meghívása itt...
    int res = match_ends(szavak1_meret, szavak1);
    printf("match_ends ertek: %d\n", res);
    for (int i = 0; i < szavak1_meret; ++i)
    {
        puts(szavak1[i]);
    }

    return 0;
}

int match_ends(int n, string words[])
{
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        string word = words[i];
        int len = my_lenght(word);
        if (len < 2) continue;
        if (word[0] == word[len - 1]) {
            cnt++;
        }
    }
    return cnt;
}