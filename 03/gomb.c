#include <stdio.h>

const float PI = 3.14;

double negyzet(int n) {
    return n * n;
}

double kob(int n) {
    return n * n * n;
}

double felszin(int sugar) {
    return 4 * negyzet(sugar) * PI;
}

double terfogat(int sugar) {
    return (4 * kob(sugar) * PI) / 3;
}

double get_double() {
    double sugar;
    printf("Kerlek add meg a gomb sugarat: \n");
    scanf("%lf", &sugar);
    return sugar;
}

int main() {
    int sugar = get_double();
    printf("Felszin: %lf\n", felszin(sugar));
    printf("Terfogat: %lf\n", terfogat(sugar));
    return 0;
}