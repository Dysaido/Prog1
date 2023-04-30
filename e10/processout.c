#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_MAX 16
#define INIT_CAP 2
#define MULTIPLIER 2

typedef struct {
    int *elements;  // Dinamikus tomb
    int lenght;     // Elemek szama
    int capacity;   // Maximalis hely, ami rendelkezesre all
} DynArray;

void mem_error_exit()
{
    fprintf(stderr, "Error: cannot allocate memory\n");
    exit(1);
}

DynArray * da_create()
{
    DynArray *ret = malloc(sizeof(DynArray));
    if (ret == NULL)
        mem_error_exit();
    
    ret->elements = malloc(INIT_CAP * sizeof(int));
    
    if (ret->elements == NULL)
        mem_error_exit();
    
    ret->lenght = 0;
    ret->capacity = INIT_CAP;

    return ret;
}

int da_sum(const DynArray *self)
{
    int ret = 0;
    for (int i = 0; i < self->lenght; ++i)
    {
        ret += self->elements[i];
    }

    return ret;
}

double da_average(const DynArray *self)
{
    int sum = da_sum(self);
    return sum / (double) self->lenght;
}

void da_append(DynArray *arr, int elem)
{
    if (arr->lenght == arr->capacity)
    {
        int new_cap = MULTIPLIER * arr->capacity;
        arr->elements = realloc(arr->elements, new_cap * sizeof(int));
        if (arr->elements == NULL)
        {
            mem_error_exit();
        }
        arr->capacity = new_cap;
    }
    arr->elements[arr->lenght] = elem;
    arr->lenght++;
}

void * da_destroy(DynArray *arr)
{
    free(arr->elements);
    free(arr);
    return NULL;
}

void put_to_array_from(FILE *fp, DynArray *arr)
{
    char row[BUF_MAX];
    while (fgets(row, sizeof(row), fp) != NULL)
    {
        int tmp = atoi(row);
        da_append(arr, tmp);
    }
}

int main()
{
    char* name = "numbers.txt";
    FILE *fp = fopen(name, "r");
    if (fp == NULL)
    {
        printf("Hiba! %s file megnyitása sikertelen!\n", name);
        exit(1);
    }
    DynArray *array = da_create();

    put_to_array_from(fp, array);
    
    fclose(fp);

    printf("Averange: %.2lf\n", da_average(array));

    array = da_destroy(array);

    return 0;
}