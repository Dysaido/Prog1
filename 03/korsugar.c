#include <stdio.h>

const int PI = 3.14;

float terulet(int sugar) {
    return sugar * sugar * PI;
}

float kerulet(int sugar) {
    return 2 * sugar * PI;

}

int main() {
    int sugar;
    printf("Kerlek add meg a kor sugarat: \n");
    scanf("&d", &sugar);
    printf("Terulet: %d\n", terulet(sugar));
    printf("Kerulet: %d\n", kerulet(sugar));
    return 0;
}