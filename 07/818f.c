#include <stdio.h>
#include <stdlib.h>

int negyzetosszeg(int szam)
{
    int sum = 0;
    for (int i = 1; i <= szam; ++i)
    {
        sum += i*i;
    }
    return sum;
}

int osszegnegyzet(int szam)
{
    int sum = 0;
    for (int i = 1; i <= szam; ++i)
    {
        sum += i;
    }
    return sum * sum;
}

int main()
{
    int _negyzetosszeg = negyzetosszeg(100);
    int _osszegnegyzet = osszegnegyzet(100);
    printf("Kulonbseg %d\n", _osszegnegyzet - _negyzetosszeg);
    return 0;
}