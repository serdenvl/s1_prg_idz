#include <stdio.h>

void Task1();
void Task2();
void Task3();
void Task4();
void Task5();
void Task6();
void Task7();

#define num_tasks ( sizeof(tasks)/sizeof(void(*)()) )
int main()
{
    void (*tasks[])() = {Task1, Task2, Task3, Task4, Task5, Task6, Task7};

    char command;

    while(1)
    {
        printf("1-7 - перейти к заданию\nq - выход\n");
        command = getchar();

        if('1' <= command && command <= '0'+num_tasks)
        {
            tasks[command-'1']();

            printf("\n\nпродолжить...");
            while (getchar() != '\n');
            getchar();
        }
        else if(command == 'q')
        {
            break;
        }
        system("clear");
    }
}
