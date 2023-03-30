#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024 //2 << 9;


typedef char* string;

string get_str(const string str)
{
    printf("%s", str);

    char buf[BUF_SIZE];
    fgets(buf, BUF_SIZE, stdin);
    buf[strlen(buf) - 1] = '\0';

    return strdup(buf);
}

int main()
{
    printf("Adj meg szavakat '*' végjelig!\n");
    string tmp;
    int count = 0;
    int longest = 0;
    while (1) 
    {
        tmp = get_str("Szó: ");
        if ((tmp[0] == '*') && (tmp[1] == '\0')) 
        {
            break;
        }
        count++;
        int len = strlen(tmp);
        if (longest < len) 
        {
            longest = len;
        }
    }

    puts("");
    printf("%d db szót adtál meg. A leghosszabb szó %d karakterből áll.\n", count, longest);
    return 0;
}