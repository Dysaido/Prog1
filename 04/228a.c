#include <stdio.h>

int valid_triange(int a, int b, int c);

int main() {
    int a,b,c;
    printf("Add meg a haromszog \'a\' oldalat: ");
    scanf("%d", &a);    
    printf("Add meg a haromszog \'b\' oldalat: ");
    scanf("%d", &b);
    printf("Add meg a haromszog \'c\' oldalat: ");
    scanf("%d", &c);

    if (valid_triange(a, b, c)) {
        printf("Szerkesztheto haromszog\n");
    } else {
        printf("Nem szerkesztheto haromszog\n");
    }

    return 0;
}

// 0/1
int valid_triange(int a, int b, int c) {
    int ret = 0;
    if ((a + b > c) | (a + c > b) | (b + c > a)) {
        ret = 1;
    }
    return ret;
};