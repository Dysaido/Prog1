#include <stdio.h>

int main() {
    int num = 0;

    for (int i = 1; i < 1000; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            num += i;
        }
    }
    printf("Num: %d\n", num);
    return 0;
}