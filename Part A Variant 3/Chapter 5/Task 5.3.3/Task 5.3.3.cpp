//Написать функции для заполнения массива случайными числами, ввода
//  с клавиатуры, вывода на экран.Выполнить задания 3.1 оформив их
//  через функции. Все необходимые данные для функций должны
//  передаваться в качестве параметров.
//
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

void Searching_max(int array[], int*, int*, const int);
void Sorting(int array[], const int);
void Output_array(int array[], const int);
void Fill_const(int array[], const int);
void Fill_rand(int array[], const int);
void Fill_user(int array[], const int);

int main()
{
    const int N = 5;
    int amount = 0;
    int array[N];
    int checker = 0;
    enum enmArrayInit
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
        Output_array(array, N);
        break;
    }
    case enmArrayInit::WithRand:
    {
        Fill_rand(array, N);
        Output_array(array, N);
        break;
    }
    case enmArrayInit::ByUser:
    {
        Fill_user(array, N);
        Output_array(array, N);
        break;
    }
    default:  cout << "The program is stopped" << endl;
        return 0;
    }

    Sorting(array, N);
    Output_array(array, N);
    int n_max = N - 1;
    int max;
    Searching_max(array, &n_max, &checker, N);
    if (checker == 1)
    {
        return 0;
    }
    else
    {
        max = array[n_max];
        cout << "The maximum element that occurs only once = " << max;
    }
    return 0;
}

void Searching_max(int array[], int* n_max, int *checker, const int N)
{
    for (int k = 1; k < N; k++)
    {
        if (*n_max == N - 1)
        {
            if (array[*n_max] == array[(*n_max - 1)])
            {
                *n_max = *n_max - 2;

            }
        }
        else if (array[*n_max] == array[*n_max - 1] || array[*n_max] == array[*n_max + 1])
        {
            *n_max = *n_max - 1;
        }
        if (*n_max < 0)
        {
            cout << "There are no single elements in the sequence";
            *checker = *checker + 1;
        }
    }
}

void Sorting(int array[], const int N)
{
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
    cout << "Array after sorting: " << endl;
}

void Output_array(int array[], const int N)
{
    for (int i = 0; i < N; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void Fill_const(int array[], const int N)
{
    for (int i = 0; i < N; ++i)
    {
        array[i] = i;
    }
}

void Fill_rand(int array[], const int N)
{
    for (int i = 0; i < N; ++i)
    {
        array[i] = rand() % 50;
    }
}

void Fill_user(int array[], const int N)
{
    cout << "Fill in the array using the keyboard" << endl;
    for (int i = 0; i < N; ++i)
    {
        cin >> array[i];
    }
}