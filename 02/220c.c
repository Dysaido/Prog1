#include <stdio.h>

int main() {

    int n1, n2;
    printf("Adj meg egy pozitiv egesz szamot: \nszam: ");
    scanf("%d", &n1);
    printf("Adj meg egy pozitiv egesz szamot: \nszam: ");
    scanf("%d", &n2);
    if (n1 > n2) {
        printf(">\n");
    } else if (n1 < n2) {

        printf("<\n");
    } else {

        printf("=\n");
    }
    return 0;
}