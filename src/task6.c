#include <stdio.h>

void buble_sort(int *array, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        if (array[i] >= array[i + 1])
            continue;
        swap(&array[i], &array[i + 1]);
        i -= 2 * (i != 0);
    }
}

void generate_sorted_array(int* array, int length)
{
    int num = 0;
    for(int i = 0; i < length; ++i)
    {
        num += random(1, 5);
        array[i] = num;
    }
}

/*
6. Дан массив размера N, все элементы которого, кроме одного, упорядочены по
убыванию. Сделать массив упорядоченным, переместив элемент, нарушающий
упорядоченность, на новую позицию. Вспомогательные массивы не использо-
вать.
*/

#define num_task 6
#define welcome_message "\
Сгенерировать случайный массив целых чисел длины N, упорядоченный за исключением одного элемента.\n\
Досортировать.\
"

void Task6()
{
    welcome(num_task, welcome_message);

    int N = scan_int("N: ", 2);

    int array[N];
    randomize_array(array, N, 10, 29);
    //generate_sorted_array(array, N);
    buble_sort(array, N);

    int i1 = random(0, N - 1);
    int i2 = random(0, N - 1);
    while (i1 == i2)
        i2 = random(0, N - 1);
    swap(&array[i1], &array[i2]);

    printf("\nСлучайный массив: ");
    print_array(array, N);

    buble_sort(array, N);

    printf("\nДосортированный массив: ");
    print_array(array, N);
}
