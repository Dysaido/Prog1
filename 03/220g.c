#include <stdio.h>

void put_patrick_star(int n) {
    for (int k = 1; k <= n; k++) {
        printf("#");
    }
}

int main() {
    int magassag;
    printf("Magassag: ");
    scanf("%d", &magassag);

    for (int i = 1; i <= magassag; i++) {
        int space = magassag - i;
        for (int j = 1; j <= space; j++) {
            printf(" ");
        }
        put_patrick_star(i);
        printf("  ");
        put_patrick_star(i);
        printf("\n");
    }
    return 0;
}