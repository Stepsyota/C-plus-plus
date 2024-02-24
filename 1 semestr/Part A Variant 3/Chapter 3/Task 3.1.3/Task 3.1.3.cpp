//Для тестирования программы предусмотреть возможность задавать элементы
//  массива различным образом : при определении с инициализацией, случайными
//  числами, вводом с клавиатуры. Выбор способа инициализации массива сделать
//  через меню с использованием перечисления(enum).
// 
//Найти наибольшее среди чисел последовательности, встречающихся в
//последовательности ровно один раз.

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    const int N = 5;
    int amount = 0;
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
    cout << "Your choice is " << ch << endl;

    switch ((enmArrayInit)ch)
    {
    case enmArrayInit::WithConst:
    {
        for (int i = 0; i < N; i++)
        {
            array[i] = i;
            cout << array[i] << " ";
        }
        cout << endl;
        break;
    }
    case enmArrayInit::WithRand:
    {
        for (int i = 0; i < N; i++)
        {
            array[i] = rand() % 200;
            cout << array[i] << " ";
        }
        cout << endl;
        break;
    }
    case enmArrayInit::ByUser:
    {
        for (int i = 0; i < N; i++)
        {
            cin >> array[i];
            cout << array[i] << " ";
        }
        cout << endl;
        break;
    }
    default:  cout << "The program is stopped" << endl;
        return 0;
    }

    //Сортировка вставкой
    for (int i = 1; i < N; i++)
    {
        int x = array[i];
        int j = i - 1;
        while (x < array[j])
        {
            array[j + 1] = array[j];
            j--;
            if (j < 0)
                break;
        }
        array[j + 1] = x;
    }
    //
    cout << "Array after sorting: " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;


    int n_max = N - 1;
    for (int k = 1; k < N; k++)
    {
        if (n_max == N - 1)
        {
            if (array[n_max] == array[(n_max - 1)])
            {
                n_max = n_max - 2;

            }
        }
        else if (array[n_max] == array[n_max - 1] || array[n_max] == array[n_max + 1])
        {
            n_max = n_max - 1;
        }
        if (n_max < 0)
        {
            cout << "There are no single elements in the sequence";
            return 0;
        }
    }
    int max;
    max = array[n_max];
    cout << "max = " << max;
    return 0;
}