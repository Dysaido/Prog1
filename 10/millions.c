#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUF_SIZE 200
#define INITIAL 2
#define MULTIPLIER 2

void mem_error_exit()
{
    fprintf(stderr, "MemError: cannot allocate memory\n");
    exit(1);
}

void io_error_exit()
{
    fprintf(stderr, "IOError: cannot handle this file\n");
    exit(1);
}

typedef struct {
    int *elements;
    int lenght;
    int capacity;
} DyArray;

DyArray* create_dyarr()
{
    DyArray* arr = malloc(sizeof(DyArray));
    if (arr == NULL)
        mem_error_exit();
    arr->elements = malloc(INITIAL * sizeof(int));
    if (arr->elements == NULL)
        mem_error_exit();
    arr->lenght = 0;
    arr->capacity = INITIAL;
}

void* destroy_dyarr(DyArray *arr)
{
    free(arr->elements);
    free(arr);
    return NULL;
}

void add_element(DyArray* arr, int element)
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
    arr->elements[arr->lenght] = element;
    arr->lenght++;
}

void da_clear(DyArray *self)
{
    int lenght = self->lenght;
    if (lenght > 0)
    {
        for (int i = 0; i < lenght; ++i)
        {
            self->elements[i] = 0;
        }
        self->lenght = 0;
    }
}

void elements_from(const char* name, DyArray *arr)
{
    FILE *fp = fopen(name, "r");
    if (fp == NULL)
    {
        io_error_exit();
    }
    char row[BUF_SIZE];
    while (fgets(row, sizeof(row), fp) != NULL)
    {
        int tmp = atoi(row);
        add_element(arr, tmp);
    }
    fclose(fp);
}

void write_arr_to(const char* name, const DyArray *arr)
{
    FILE *fp = fopen(name, "w");
    if (fp == NULL)
    {
        io_error_exit();
    }

    for (int i = 0; i < arr->lenght; ++i)
    {
        fprintf(fp, "%d\n", arr->elements[i]);
    }
    fclose(fp);
}

void arrsort(const DyArray* arr)
{
    for (int i = 0; i < arr->lenght - 1; ++i)
    {
        for (int j = i + 1; j < arr->lenght; j++)
        {
            if (arr->elements[j] < arr->elements[i])
            {
                int tmp = arr->elements[i];
                arr->elements[i] = arr->elements[j];
                arr->elements[j] = tmp;
            }
        }
    }
}
void quicksort(DyArray *arr, int bal, int jobb)
{
    int x, temp;
    int i, j;

    i = bal;
    j = jobb;
    x = arr->elements[(bal + jobb) / 2];
    while (i <= j)
    {
        while (arr->elements[i] < x) ++i;
        while (arr->elements[j] > x) --j;
        if (i <= j)
        {
            temp = arr->elements[i];
            arr->elements[i] = arr->elements[j];
            arr->elements[j] = temp;
            /* */
            ++i;
            --j;
        }
    }

    if (bal < j)  quicksort(arr, bal, j);
    if (i < jobb) quicksort(arr, i, jobb);
}

void print_array(int lenght, int array[])
{
    printf("A tömb elemei: ");
    int count = 0;
    for (int i = 0; i < lenght; ++i) 
    {
        printf("%d ", array[i]);
        if (count == 100) break;
        count++;
    }
    puts("");
}

int main(int argc, char** argv)
{
    if (argc != 2) 
    {
        io_error_exit();
    }
    const char* name = argv[1];
    DyArray *arr = create_dyarr();
    
    printf("Befor clear \n");
    elements_from(name, arr);
    print_array(arr->lenght, arr->elements);
    da_clear(arr);
    
    printf("After clear \n");
    print_array(arr->lenght, arr->elements);

    
    printf("Read again \n");
    elements_from(name, arr);
    
    quicksort(arr, 0, arr->lenght - 1);

    print_array(arr->lenght, arr->elements);

    write_arr_to(name, arr);

    arr = destroy_dyarr(arr);
    return 0;
}