#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Pont;

double distance(Pont p1, Pont p2)
{
    int a = abs(p1.x - p2.x);
    int b = abs(p1.y - p2.y);
    return sqrt(a * a + b * b);
}

int main()
{
    Pont a = { 1, 2 };
    Pont b = { 6, 5 };

    printf("A két pont közti távolság: %lf\n", distance(a, b));

    return 0;
}