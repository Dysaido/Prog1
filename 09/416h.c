#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUF_SIZE 2000

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

int * get_arr_from(const char* name, int *lenght)
{
    FILE *fp = fopen(name, "r");
    if (fp == NULL)
    {
        io_error_exit();
    }
    char row[BUF_SIZE];
    *lenght = BUF_SIZE * sizeof(int);
    int *arr = malloc(*lenght);
    int pos = 0;
    while (fgets(row, sizeof(row), fp) != NULL)
    {
        int tmp = atoi(row);
        arr[pos] = tmp;
        pos++;
    }
    fclose(fp);
    *lenght = pos;
    arr = realloc(arr, (pos + 1) * sizeof(int));
    if (arr == NULL)
    {
        mem_error_exit();
    }
    return arr;
}

void write_arr_to(const char* name, int lenght, int *arr)
{
    FILE *fp = fopen(name, "w");
    if (fp == NULL)
    {
        io_error_exit();
    }

    for (int i = 0; i < lenght; ++i)
    {
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);
}

void arrsort(int lenght, int *arr)
{
    for (int i = 0; i < lenght - 1; ++i)
    {
        for (int j = i + 1; j < lenght; j++)
        {
            if (arr[j] < arr[i])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void print_array(int lenght, int array[])
{
    printf("A tömb elemei: ");
    for (int i = 0; i < lenght; ++i) 
    {
        printf("%d ", array[i]);
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
    int *lenght;
    int *arr = get_arr_from(name, lenght);
    // print_array(*lenght, arr);
    arrsort(*lenght, arr);
    write_arr_to(name, *lenght, arr);
    free(arr);
    arr = NULL;
    return 0;
}