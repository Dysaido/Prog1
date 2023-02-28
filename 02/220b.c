#include <stdio.h>

int main() {
    int n;
    printf("Adj meg egy pozitiv egesz szamot: \nszam: ");
    scanf("%d", &n);
    for (; n >= 1; --n) {
        if (n % 2 != 0) {
            printf("%d\n", n);
        }
    }
    return 0;
}