#include <stdio.h>
#include <string.h>
#include <ctype.h>

int strcmpi(const char* s1, const char* s2)
{
    int i;
    for (i = 0; s1[i] != '\0'; ++i)
    {
        if (tolower(s1[i]) != tolower(s2[i]))
        {
            break;
        }
    }
    if (tolower(s1[i]) == tolower(s2[i]))
    {
        return 0;
    }
    return -1;
}

int main()
{
    //int result = strcmp("Alma", "alma");  //s1 comes after s2   return < 0
    //int result = strcmp("alma", "Alma");  //s1 comes before s2  return > 0
    //int result = strcmp("Alma", "Alma");  //Equal               return = 0
    
    int result = strcmpi("Almwwww", "almww");
    if (result == 0)
    {
        printf("Equal\n");
    }
    else
    {
        printf("Not equal\n");
    }
    return 0;
}