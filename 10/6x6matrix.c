#include <stdio.h>

void kiir(int rows, int columns, int matrix[rows][columns])
{
    for (int row = 0; row < rows; ++row)
    {
        for (int column = 0; column < columns; ++column)
        {
            printf("%d\t", matrix[row][column]);
        }
        puts("");
    }
}

void kiir_foatlo(int n, int matrix[n][n])
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d\t", matrix[i][i]);
    }
    puts("");
}

void kiir_mellekatlo(int n, int matrix[n][n])
{
    for (int i = n - 1; i >= 0; --i)
    {
        printf("%d\t", matrix[i][i]);
    }
    puts("");
}

int main()
{
    int rows = 6;
    int columns = 6;
    int matrix[6][6] = {
        {5, 2, 7, 8, 2, 4},
        {3, 2, 8, 4, 3, 9},
        {1, 4, 2, 8, 7, 3},
        {5, 9, 2, 7, 4, 1},
        {1, 3, 5, 8, 2, 6},
        {7, 1, 7, 2, 6, 4}
    };
    kiir_foatlo(rows, matrix);
    kiir_mellekatlo(rows, matrix);
    return 0;
}