#include <stdio.h>

// Megadja a tomb legkisebb elemet, a tomb merete es maga a tomb a bemeneti ertek, visszater a legkisebb tombelemmel
int get_min_element(int size, int array[]) {
    int tmp_entry = array[0];
    for (int i = 1; i < size; i++) {
        if (tmp_entry < array[i]) continue;
        tmp_entry = array[i];
    }
    return tmp_entry;
}

// Megadja a tomb legnagyobb elemet, a tomb merete es maga a tomb a bemeneti ertek, visszater a legnagyobb tombelemmel
int get_max_element(int size, int array[]) {
    int tmp_entry = array[0];
    for (int i = 1; i < size; i++) {
        if (tmp_entry > array[i]) continue;
        tmp_entry = array[i];
    }
    return tmp_entry;
}

int main() {
    int array[10] = {23, 43, 6, 2, 78, 37, 94, 5, 3, 52};
    int size = 10;
    
    printf("Min: %d\n", get_min_element(size, array));
    printf("Max: %d\n", get_max_element(size, array));

    return 0;
}