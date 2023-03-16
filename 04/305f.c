#include <stdio.h>

// Ellenorzi hogy rendezett e a tomb, a tomb merete es maga a tomb a bemeneti ertek, igaz(1)-hamis(0) a visszateresi ertek
void print_array(int size, int array[]) {
    if (size == 0) return;
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            printf("%d\n", array[i]);
            break;
        }
        printf("%d, ", array[i]);
    }
}

int main() {
    int array[10] = {23, 43, 6, 2, 78, 37, 94, 5, 0, 52};
    int array2[10] = {2, 4, 6, 22, 78, 97, 99, 125, 130, 152};
    int size = 10;
    
    print_array(size, array);
    print_array(size, array2);
    return 0;
}