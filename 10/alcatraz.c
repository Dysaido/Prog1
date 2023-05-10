#include <stdio.h>

#define AJTO_SZAM 600

int main() {
    int ajtok[AJTO_SZAM] = {0}; // 0-val inicializaljuk a tombot

    for (int step = 1; step <= AJTO_SZAM; step++) {
        for (int i = step - 1; i < AJTO_SZAM; i += step) {
            ajtok[i] = !ajtok[i];
        }
    }

    printf("Szabadon engedettek szama:\n");
    for (int i = 0; i < AJTO_SZAM; i++) {
        if (ajtok[i] == 1) {
            printf("%d ", i + 1);
        }
    }
    puts("");

    return 0;
}