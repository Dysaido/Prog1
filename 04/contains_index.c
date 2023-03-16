#include <stdio.h>

// Ellenorzi hogy a tomb tartalmazza-e a megadott elemet, a tomb merete, maga a tomb es a keresett elem a bemeneti ertek, 
// igaz(1)-hamis(0) a visszateresi ertek
int contains(int size, int array[], int entry) {
    for (int i = 0; i < size; i++) {
        if (entry == array[i]) return 1;
    }
    return 0;
}
// Ellenorzi a megadott elemet helyzetet a tombben, a tomb merete, maga a tomb es a keresett elem a bemeneti ertek, 
// a tomb helyzete a visszateresi ertek, ha nem talalta meg -1-el ter vissza
int own_index(int size, int array[], int entry) {
    for (int i = 0; i < size; i++) {
        if (entry == array[i]) return i;
    }
    return -1;
}

int main() {
    int array[10] = {23, 43, 6, 2, 78, 37, 94, 5, 3, 52};
    int size = 10;
    
    if (contains(size, array, 3)) {
        printf("Contains\n");
    } else {
        printf("Not contains\n");
    }
    int entry = 0;
    printf("Adj meg egy termeszetes szamot, es ellenorizzuk hogy hol taroljuk: ");
    scanf("%d", &entry);
    printf("Helyzet: %d\n", own_index(size, array, entry));
    return 0;
}