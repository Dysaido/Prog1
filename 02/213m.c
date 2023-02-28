#include <stdio.h>

int main() {

    int count = 0;
    int temp_num;
    while (1) {
        printf("Adj meg egy egesz szamot (vege: 0): \n");
        scanf("%d", &temp_num);
        if (temp_num == 0) {
            break;
        }
        if (temp_num > 0) {
            count++;
        }
    }
    printf("Pozitiv szamok: %d\n", count);

    return 0;
}