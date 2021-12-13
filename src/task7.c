#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void maxs_columns(int *matrix[], int M, int N, int buff[])
{
    for (int i = 0; i < N; ++i)
        buff[i] = matrix[0][i];

    for (int i = 1; i < M; ++i)
        for (int j = 0; j < N; ++j)
            buff[j] = max(buff[j], matrix[i][j]);
}

/*
7. Дана матрица размера M × N. В каждом столбце матрицы найти максимальный
элемент.
*/

#define num_task 7
#define welcome_message "\
Сгенерировать случайную матрицу размера M × N\n\
Вывести максимальный элемент для каждого столбца.\
"

void Task7()
{
    welcome(num_task, welcome_message);

    int M = scan_int("M: ", 1);
    int N = scan_int("N: ", 1);

    // [строка][столбец]
    int *matrix[M];
    for (int i = 0; i < M; ++i)
        matrix[i] = malloc(sizeof(int) * N);
    randomize_matrix(matrix, M, N, 10, 29);

    printf("\nСлучайная матрица:\n");
    for (int i = 0; i < M; ++i)
    {
        print_array(matrix[i], N);
        printf("\n");
    }

    int maxs[N];
    randomize_array(maxs, N, 0, 1);
    maxs_columns(matrix, M, N, maxs);

    printf("\nМаксиумы столбцов:\n");
    print_array(maxs, N);

    for (int i = 0; i < M; ++i)
        free(matrix[i]);
}