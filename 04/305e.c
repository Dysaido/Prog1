#include <stdio.h>

int is_even(int n) {
    return n % 2 == 0;
}

int is_odd(int n) {
    return n % 2 != 0;
}

int main() {
    int num;
    printf("Adj meg egy termeszetes szamot: ");
    scanf("%d", &num);
    printf("isEven: %d", is_even(num));
    printf("isOdd: %d", is_odd(num));
    return 0;
}