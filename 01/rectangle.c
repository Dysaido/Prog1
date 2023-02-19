#include <stdio.h>

int main() {    
    int a,b;
    printf("Add meg a teglalap \"a\" oldalat(egesz szam):\n");
    scanf("%d", &a);
    printf("Add meg a teglalap \"b\" oldalat(egesz szam):\n");
    scanf("%d", &b);
    printf("Terulet: %d\n", a * b);
    printf("Kerulet: %d\n", 2 * (a + b));
    return 0;
}
