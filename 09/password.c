#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

typedef char* string;

int randint(int bottom, int top)
{
    int interval = top - bottom + 1;
    int random = rand();
    random = random % interval;
    random = random + bottom;
    return random;
}

void genpsw(int lenght)
{

    string abc = "abcdefghijklmnopqrstuvwxyz";
    string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string nums = " 0123456789";
    string chars = ".,;'";
    srand(time(NULL));
    char password[lenght];
    int status = 0;

    for (int i = 0; i < lenght; ++i)
    {
        switch (status)
        {
        case 1:
            password[i] = abc[rand() % 26];
            status = rand() % 4;
            printf("%c", password[i]);
            break;
        
        case 2:
            password[i] = ABC[rand() % 26];
            status = rand() % 4;
            printf("%c", password[i]);
            break;
        case 3:
            password[i] = nums[rand() % 10];
            status = rand() % 4;
            printf("%c", password[i]);
            break;
        default:
            password[i] = chars[rand() % 4];
            status = rand() % 4;
            printf("%c", password[i]);
            break;
        }
    }
    puts("");
}

int main()
{
    int len = randint(8, 12);

    genpsw(len);
    return 0;
}