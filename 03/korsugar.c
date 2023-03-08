#include <stdio.h>

const float PI = 3.14;

float terulet(int sugar) {
    return sugar * sugar * PI;
}

float kerulet(int sugar) {
    return 2 * sugar * PI;

}

int main() {
    int sugar;
    printf("Kerlek add meg a kor sugarat: \n");
    scanf("%d", &sugar);
    printf("Terulet: %f\n", terulet(sugar));
    printf("Kerulet: %f\n", kerulet(sugar));
    return 0;
}