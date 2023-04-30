#include <stdio.h>
#include <stdlib.h>


// interval [bottom, top]
int randint(int bottom, int top)
{
    int interval = top - bottom + 1;

    int random = rand();
    random = random % interval;
    
    return bottom + random;
}

void write_to_file(FILE *fp)
{
    for (int i = 0; i < 100; ++i)
    {
        int random = randint(10, 100);
        fprintf(fp, "%d\n", random);
    }
}

int main()
{
    char* name = "numbers.txt";
    FILE *fp = fopen(name, "w");
    if (fp == NULL)
    {
        printf("Hiba! %s file létrehozása sikertelen!\n", name);
        exit(1);
    }
    write_to_file(fp);
    fclose(fp);
    return 0;
}