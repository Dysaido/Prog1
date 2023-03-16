#include <stdio.h>
#define ABS(N) ((N < 0) ? (-N) : (N))

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

/**
 * Írjon eljárást, ami kap egy egészeket tartalmazó tömböt. Az eljárás cserélje ki a tömbben lévő negatív számokat az abszolútértékükre! 
 * Az eljárás a tömböt helyben módosítja.
 * A main() fv.-ben írassa ki a tömböt kétszer (a fenti eljárás meghívása előtt, majd után).
*/
void foreach_abs(int size, int array[]) {
    for (int i = 0; i < size; i++) {
        int entry = array[i];
        if (entry < 0) array[i] = ABS(entry);
    }
}

void test(int size, int array[]) {
    printf("Alap: ");
    print_array(size, array);
    foreach_abs(size, array);
    printf("Eljaras utan: ");
    print_array(size, array);
}

int main() {
    int array[10] = {-23, 43, -6, 2, -78, 37, 94, -5, 0, 52};
    int array2[10] = {2, -4, 6, 22, -78, -97, -99, 125, 130, -152};
    int size = 10;
    printf("Elso tomb\n");
    test(size, array);
    printf("Masodik tomb\n");
    test(size, array2);
    return 0;
}