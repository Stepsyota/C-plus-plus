//Для тестирования программы предусмотреть возможность задавать элементы
//  массива различным образом : при определении с инициализацией, случайными
//  числами, вводом с клавиатуры. Выбор способа инициализации массива сделать
//  через меню с использованием перечисления(enum).
//Задана последовательность целых чисел. Вывести на экран все элементы, индексы которых
//  являются степенями пятёрки. Определить количество чисел, которые являются степенью пятёрки.

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    const int N = 5;
    int Sum = 0;
    int array[N];

    enum class enmArrayInit
    {
        Uninited = 0, WithConst, WithRand, ByUser,
    };
    cout << "Choose the type of initialization: \n"
        << (int)enmArrayInit::WithConst << ". constants\n"
        << (int)enmArrayInit::WithRand << ". random\n"
        << (int)enmArrayInit::ByUser << ". manually\n";
    int ch = 0;
    cin >> ch;
    cout << "Yout choice is " << ch << endl;

    switch ((enmArrayInit)ch)
    {
    case enmArrayInit::WithConst:
    {
        for (int i = 0; i < N; i++)
        {
            array[i] = i;
            cout << array[i] << endl;
        }
        break;
    }
    case enmArrayInit::WithRand:
    {
        for (int i = 0; i < N; i++)
        {
            array[i] = rand() % 200;
            cout << array[i] << endl;
        }
        break;
    }
    case enmArrayInit::ByUser:
    {
        for (int i = 0; i < N; i++)
        {
            cin >> array[i];
            cout << array[i] << endl;
        }
        break;
    }
    default:  cout << "The program is stopped" << endl;
        return 0;
    }

    //Index - degree 5
    for (int i = 0; i < N; i++)
    {
        if (i == 0 || i == 1)
        {
            cout << i << ". " << array[i] << endl;
        }
        for (int k = 1; k <= i; k++)
        {
            if (i == pow(5, k))
            {
                cout << i << ". " << array[i] << endl;
            }
        }
    }
    // Index - degree 5

    int l = 0;
    for (int i = 0; i < N; i++)
    {
        if (array[i] == 0 || array[i] == 1)
        {
            l += 1;
        }
        for (int k = 1; k <= i; k++)
        {
            if (array[i] == pow(5, k))
            {
                l += 1;
            }
        }

    }
    cout << "Numbers of degree 5: " << l << endl;
    return 0;
}