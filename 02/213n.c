#include <stdio.h>

int main() {

    int temp_num;
    int temp_posnum = 0;
    int temp_negnum = 0;
    while (1) {
        printf("Adj meg egy egesz szamot (vege: 0): \n");
        scanf("%d", &temp_num);
        if (temp_num == 0) {
            break;
        }
        if (temp_num > 0) {
            temp_posnum++;
        }
        if (temp_num < 0) {
            temp_negnum++;
        }
    }
    printf("Pozitiv szamok: %d\n", temp_posnum);
    printf("Negativg szamok: %d\n", temp_negnum);

    return 0;
}