#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 2 << 9

typedef char* string;
// 13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084096
string get_string(const string str) 
{
    printf("%s", str);
    
    char buf[BUF_SIZE];
    fgets(buf, BUF_SIZE, stdin);
    buf[strlen(buf) - 1] = '\0';
    
    return strdup(buf);
}

int main()
{
    string str = get_string("Szám: ");
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        char tmp[] = {str[i], '\0'};
        sum += atoi(tmp);
    }
    printf("A számjegyek összege: %d\n", sum);
    return 0;
}