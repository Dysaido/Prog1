#include<stdio.h>
int main() {
    int magassag, space;
    printf("Magassag: ");
    scanf("%d",&magassag);
    for (int i = 0; i <= magassag; i++) {
        for(space = magassag; space > i; space--) {
            printf(" ");
        }
        for(int j=0; j<i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    for (int i = 1; i < magassag; i++) {
        for(space = 0; space < i; space++) {
            printf(" ");
        }
        for(int j = magassag; j > i; j--) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}