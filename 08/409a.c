#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

typedef struct {
    int lenght;
    string text;
} Pair;

int main(int argc, char ** argv)
{
    if (argc < 2) 
    {
        fprintf(stderr, "Nem adtál meg egyetlen szót sem!");
        exit(1);
    }
    
    int pairslen = argc - 1;
    Pair pairs[pairslen];
    int lowest = strlen(argv[1]);
    for (int i = 1; i < argc; ++i)
    {
        char* argument = argv[i];
        int len = strlen(argument);
        Pair pair = {len, argument};
        pairs[i - 1] = pair;
        if (len < lowest) lowest = len;
    }

    for (int i = 0; i < pairslen; ++i)
    {
        Pair pair = pairs[i];
        if (pair.lenght == lowest)
        {
            printf("%s\n", pair.text);
        }
    }

    return 0;
}