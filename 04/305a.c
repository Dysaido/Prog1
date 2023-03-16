#include <stdio.h>

// Ellenorzi hogy rendezett e a tomb, a tomb merete es maga a tomb a bemeneti ertek, igaz(1)-hamis(0) a visszateresi ertek
int is_shorted(int size, int array[]) {
    if (size == 0) return 1;
    int tmp_entry = array[0];
    for (int i = 1; i < size; i++) {
        if (tmp_entry > array[i]) return 0;
        tmp_entry = array[i];
    }
    return 1;
}

int main() {
    int array[10] = {23, 43, 6, 2, 78, 37, 94, 5, 0, 52};
    int array2[10] = {2, 4, 6, 22, 78, 97, 99, 125, 130, 152};
    int size = 10;
    
    if (is_shorted(size, array2)) {
        printf("Rendezett tomb\n");
    } else {
        printf("Nem rendezett tomb\n");

    }
    return 0;
}