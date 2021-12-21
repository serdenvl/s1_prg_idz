#include <stdio.h>

int IsPower5(int num)
{
    while (num > 5 && num % 5 == 0)
        num /= 5;
    return num == 5;
}

/*
Описать функцию IsPower5(K), возвращающую ненулевое значение, если целый
параметр K > 0 является степенью числа 5, и ноль в противном случае. С ее по-
мощью найти количество степеней числа 5 в наборе из N псевдослучайных це-
лых положительных чисел.
*/

#define num_task 1
#define welcome_message "\
Сгенерировать случайный набор целых чисел длины N.\n\
Вывести количество степеней числа 5.\
"

void Task1()
{
    welcome(num_task, welcome_message);

    int N = scan_int("N: ", 0);

    int array[N]; 
    randomize_array(array, N, 120, 129);
    printf("\nСлучайный набор: ");
    print_array(array, N);

    int count = 0;
    for (int i = 0; i < N; ++i)
        if(IsPower5(array[i]))
            ++count;
    printf("\nКоличество степей 5: %d", count);
}
