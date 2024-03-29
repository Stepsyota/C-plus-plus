// Реализовать задания 2.1, 2.2 «Учебной вычислительной практики», используя
//  объявление и методы параметризированного класса vector из стандартной
//  библиотеки шаблонов STL.

#include "Task 5.2.h"

int main()
{
    bool replay = 1;
    do
    {
        int choice = 0;
        do
        {
            cout << "Choice some task to do:\n1.Task 2.1\n2. Task 2.2(first way)\n3. Task 2.2(second way)\n";
            cin >> choice;
        } while (choice < 1 || choice > 3);

        switch (choice)
        {
        case 1:
        {
            make_task_2_1();
            break;
        }
        case 2:
        {
            make_task_2_2_1();
            break;
        }
        case 3:
        {
            make_task_2_2_2();
            break;
        }
        default:
        {
            cout << "Error";
            exit(1);
        }
        }
        bool temp = 0;
        do
        {
            cout << "Do you want to make one more task?\n0.Yes\n1. No\n";
            cin >> temp;
        } while (temp < 0 || temp > 1);
        if (temp)
        {
            replay = 0;
        }
        else
        {
            replay = 1;
        }
    } while (replay);
    return 0;
}