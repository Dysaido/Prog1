#include <stdio.h>

int main() {
    int num = 0;

    for (int i = 1; i <= 100; ++i) {
        num += i;
    }
    printf("Number: %d\n", num);
    return 0;
}