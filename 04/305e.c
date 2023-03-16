#include <stdio.h>

// Paros? bemenet egesz szam, visszater igazzal ill. hamissal
int is_even(int n) {
    return n % 2 == 0;
}

// Paratlan? bemenet egesz szam, visszater igazzal ill. hamissal
int is_odd(int n) {
    return n % 2 != 0;
}

int main() {
    int num;
    printf("Adj meg egy termeszetes szamot: ");
    scanf("%d", &num);
    printf("Paros: %d\n", is_even(num));
    printf("Paratlan: %d\n", is_odd(num));
    return 0;
}