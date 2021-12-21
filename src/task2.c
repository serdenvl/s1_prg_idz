#include <stdio.h>

int len_sequence(int* seq)
{
    int count = 0;

    while(seq[count] != 0)
        ++count;
    return count;
}

/*
Дан набор ненулевых целых чисел; признак его завершения — число 0. Вывести
количество чисел в наборе. Набор генерировать. Массивы не использовать.
*/

#define num_task 2
#define welcome_message "\
Сгенерировать случайный набор целых ненулевых чисел, оканчивающийся 0.\n\
Вывести его длину.\
"

void Task2()
{
    welcome(num_task, welcome_message);

    int N = scan_int("\nДлина набора: ", 0);
    
    int sequence[N+1];
    randomize_array(sequence, N, -5, 5);
    sequence[N] = 0;

    printf("\nСлучайный набор: ");
    print_array(sequence, N+1);

    printf("\nДлина набора: %d", len_sequence(sequence));
}
