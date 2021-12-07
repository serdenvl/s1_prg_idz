#include <stdio.h>

void strange_increment(int* array, int length)
{
    int last_odd = 0;
    for(int i = length-1; i >= 0; --i)
    {
        if(array[i] % 2 == 0)
            continue;
        last_odd = (last_odd == 0) ? array[i] : last_odd;
        array[i] += last_odd;
    }
}

/*
5. Дан целочисленный массив размера N. Увеличить все нечетные числа, содержа-
щиеся в массиве, на исходное значение последнего нечетного числа. Если нечет-
ные числа в массиве отсутствуют, то оставить массив без изменений.
*/

#define num_task 5
#define welcome_message "\
Сгенерировать случайный массив целых чисел длины N.\n\
Увеличить все нечетные элементы на значение последнего нечетного.\
"

void Task5()
{
    welcome(num_task, welcome_message);

    int N = scan_int("N: ", 0);

    int array[N];
    randomize_array(array, N, 10, 29);
    printf("\nСлучайный массив: ");
    print_array(array, N);

    strange_increment(array, N);

    printf("\nИзмененный массив: ");
    print_array(array, N);
}
