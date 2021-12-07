#include <stdio.h>
#include <stdlib.h>

/*
Дано целое число K, а также K наборов ненулевых целых чисел. Признаком за-
вершения каждого набора является число 0. Для каждого набора вывести коли-
чество его элементов. Вывести также общее количество элементов во всех набо-
рах. Наборы генерировать. Массивы не использовать.
*/

#define num_task 3
#define welcome_message "\
Сгенерировать K наборов случайных чисел, оканчивающихся 0.\n\
Вывести длину каждого и общую длину.\
"

void Task3()
{
    welcome(num_task, welcome_message);

    int K = scan_int("K: ", 0);
    
    int lens[K];
    randomize_array(lens, K, 3, 20);

    int* sequences[K];
    for(int i = 0; i < K; ++i)
    {
        sequences[i] = malloc(sizeof(int)*lens[i]);
        randomize_array(sequences[i], lens[i], 10, 29);
        sequences[i][lens[i]-1] = 0;
    }

    int sum_len = 0;
    int buff_len;
    for(int i = 0; i < K; i++)
    {
        printf("\nНабор #%d: ", i+1);
        print_array(sequences[i], lens[i]);

        buff_len = len_sequence(sequences[i]);
        sum_len += buff_len;

        printf("\nДлина: %d", buff_len);
        printf("\n");
    }
    printf("\nОбщая длина: %d", sum_len);

    for(int i = 0; i < K; ++i)
        free(sequences[i]);
}
