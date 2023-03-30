#include <stdio.h>

void line(char c, int length);

int main()
{
    printf("hello\n");
    line('-', 40);
    printf("world\n");
    return 0;
}

void line(char c, int length)
{
    for (int i = 0; i < length; ++i) 
    {
        printf("%c", c);
    }
    puts("");
}