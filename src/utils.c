#include <stdio.h>

void welcome(int task_num, char *description)
{
    printf("\nTask #%d", task_num);
    printf("\nЗадание: ");
    printf(description);
    printf("\n");
}

int question(char *message)
{
    while (1)
    {
        if (message[0] != '\n')
            printf("\n");
        printf(message);
        printf(" (Y/N):");

        switch (getchar())
        {
        case 'n':
        case 'N':
            return 0;
        case 'y':
        case 'Y':
            return 1;
        default:
            while (getchar() != '\n')
                ;
            printf("Wrong answer");
        }
    }
}

int scan_int(char *message, int min)
{
    int buff;
    do
    {
        if (message != "")
        {
            if (message[0] != '\n')
                printf("\n");
            printf(message);
        }
        scanf("%d", &buff);

        if (buff < min)
            printf("\nЗначение должно быть не меньше %d", min);
    } while (buff < min);

    return buff;
}

void print_array(int *array, int length)
{
    printf("| ");
    for (int i = 0; i < length; ++i)
        printf("%d ", array[i]);
    printf("|");
}

void randomize_array(int *array, int length, int min, int max)
{
    for (int i = 0; i < length; ++i)
        array[i] = random(min, max);
}

void randomize_matrix(int M, int N, int matrix[M][N], int min, int max)
{
    for (int i = 0; i < M; ++i)
        randomize_array(matrix[i], N, min, max);
}

int random(int min, int max)
{
    return (rand() % (max + 1 - min)) + min;
}

void swap(int *a, int *b)
{
    int a2 = *a;
    *a = *b;
    *b = a2;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}