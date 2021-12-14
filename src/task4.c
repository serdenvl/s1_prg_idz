#include <stdio.h>

int max_neighs(int* array, int length)
{
    int ix = 0;
    for(int i = 1; i < length-1; ++i)
        ix = ((array[ix]+array[ix+1]) < (array[i]+array[i+1])) ? i : ix;
    return ix;
}

/*
Дан массив размера N. Найти два соседних элемента, сумма которых максималь-
на, и вывести эти элементы в порядке возрастания их индексов.
*/

#define num_task 4
#define welcome_message "\
Сгенерировать случайный массив целых чисел длины N.\n\
Вывести два соседних элемента с наибольшей суммой.\
"

void Task4()
{
    welcome(num_task, welcome_message);

    int N = scan_int("N: ", 2);

    int array[N];
    randomize_array(array, N, 10, 29);
    printf("\nСлучайный массив: ");
    print_array(array, N);

    int answer = max_neighs(array, N);
    printf("\nОтвет: %d, %d", array[answer], array[answer+1]);
}
