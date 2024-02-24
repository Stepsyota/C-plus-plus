//Написать функции для заполнения массива случайными числами, ввода
//  с клавиатуры, вывода на экран.Выполнить задания 3.1 оформив их
//  через функции. Все необходимые данные для функций должны
//  передаваться в качестве параметров.
//
//Для тестирования программы предусмотреть возможность задавать элементы
//  массива различным образом : при определении с инициализацией, случайными
//  числами, вводом с клавиатуры. Выбор способа инициализации массива сделать
//  через меню с использованием перечисления(enum).
//Задана последовательность целых чисел. Вывести на экран все элементы, индексы которых
//  являются степенями пятёрки. Определить количество чисел, которые являются степенью пятёрки.

#include <iostream>
#include <math.h>

using namespace std;


void Output_index(int array[], const int N);
void Determ_number(int array[], int*, const int N);
void Fill_const(int array[], const int N);
void Fill_rand(int array[], const int N);
void Fill_user(int array[], const int N);

int main()
{
    const int N = 26;
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
    cout << "Your choice is " << ch << endl;

    switch ((enmArrayInit)ch)
    {
    case enmArrayInit::WithConst:
    {
        Fill_const(array, N);
        cout << endl;
        break;
    }
    case enmArrayInit::WithRand:
    {
        Fill_rand(array, N);
        cout << endl;
        break;
    }
    case enmArrayInit::ByUser:
    {
        Fill_user(array, N);
        cout << endl;
        break;
    }
    default:  cout << "The program is stopped" << endl;
        return 0;
    }
    Output_index(array, N);
    int l = 0;
    Determ_number(array, &l, N);
    cout << "Numbers of degree 5: " << l << endl;

    return 0;
}

void Output_index(int array[], const int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k <= i; k++)
        {
            if (i == pow(5, k))
            {
                cout << i << ". " << array[i] << endl;
            }
        }
    }
}

void Determ_number(int array[], int *l, const int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k <= i; k++)
        {
            if (array[i] == pow(5, k))
            {
                *l += 1;
            }
        }

    }
}

void Fill_const(int array[], const int N)
{
    for (int i = 0; i < N; ++i)
    {
        array[i] = i;
        cout << array[i] << " ";
    }

}

void Fill_rand(int array[], const int N)
{
    for (int i = 0; i < N; ++i)
    {
        array[i] = rand() % 50;
        cout << array[i] << " ";
    }

}

void Fill_user(int array[], const int N)
{
    cout << "Fill in the array using the keyboard" << endl;
    for (int i = 0; i < N; ++i)
    {
        cin >> array[i];
        cout << array[i] << " ";
    }

}