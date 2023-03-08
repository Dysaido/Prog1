#include <stdio.h>

int kerulet(int a, int b) {
    return (a + b) * 2;
}

int terulet(int a, int b) {
    return a * b;
}

int main() {
    int a, b;
    printf("Kerlek add meg a teglalap \'a\' oldalat: \n");
    scanf("%d", &a);
    printf("Kerlek add meg a teglalap \'b\' oldalat: \n");
    scanf("%d", &b);
    printf("Terulet: %d\n", terulet(a, b));
    printf("Kerulet: %d\n", kerulet(a, b));
    return 0;
}