#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1024

typedef char* string;

string get_string(string text)
{  
    char raw[SIZE];
    printf("%s", text);
    fgets(raw, sizeof raw, stdin);
    raw[strlen(raw) - 1] = '\0';
    return strdup(raw);
}

int is_punct_str(string text, char except)
{
    for (int i = 0; text[i] != '\0'; ++i)
    {
        char c = text[i];
        if (ispunct(c) && c != except)
        {
            return 1;
        }
    }
    return 0;
}

int is_valid_c_identifier(const char* input)
{
    int len = strlen(input);
    char firstChar = input[0];
    char except = '_';
    if (isdigit(firstChar))
    {
        return 0;
    }
    if (!isalpha(firstChar) && firstChar != except)
    {
        return 0;
    }

    return !is_punct_str(input, except);
}

int main()
{
    while (1)
    {
        string temp = get_string("Adj meg sztringeket '*' végjelig!\n");
        if (strcmp(temp, "*") == 0)
        {  
            free(temp);
            break;
        }
        if (is_valid_c_identifier(temp))
        {
            printf("YES\n");
        }
        else 
        {
            printf("NO\n");
        }
        free(temp);
    }
    return 0;
}