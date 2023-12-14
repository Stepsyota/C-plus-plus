//Написать функции для заполнения массива случайными числами, ввода
//  с клавиатуры, вывода на экран.Выполнить задания 3.1 оформив их
//  через функции. Все необходимые данные для функций должны
//  передаваться в качестве параметров.
//Определите сумму элементов массива, расположенных между минимальным и максимальным значениями не включая их.

#include <iostream>

using namespace std;


void searchMAX(int array[], int*, int*, const int);
void searchMIN(int array[], int*, int*, const int);
void searchSUM(int array[], int*, int*, int*, const int);
void Fill_const(int array[], const int N);
void Fill_rand(int array[], const int N);
void Fill_user(int array[], const int N);

int main()
{
    const int N = 5;
    int array[N] = {0};
    int choise;
    cout << "Choose a way to fill the array:\n 1. Constants \n 2. Random \n 3. By keyboard \n" ;
    cin >> choise;
    switch (choise)
    {
        case 1 :
        {
            Fill_const(array, N);
            cout << endl;
            break;
        }
        case 2:
        {
            Fill_rand(array, N);
            cout << endl;
            break;
        }
        case 3:
        {
            Fill_user(array, N);
            cout << endl;
            break;
        }
        default : 
        {
            cout << "Your choise is incorrect. The program is stopped";
            return 0;
        }
    }

    int max, min = array[0];
    int n_max, n_min, Sum = 0;
    searchMAX(array, &max, &n_max, N);
    searchMIN(array, &min, &n_min, N);
    searchSUM(array, &n_min, &n_max, &Sum, N);
    cout << "Max element = " << max << ". His number - " << n_max << endl
        << "Min element = " << min << ". His number - " << n_min << endl
        << "Sum = " << Sum  << endl;

    return 0;
}

void searchMAX(int array[], int* max, int* n_max, const int N)
{
    for (int i = 0; i < N; i++)
    {
        if (*max < array[i])
        {
            *max = array[i];
            *n_max = i;
        }
    }
}

void searchMIN(int array[], int* min, int* n_min, const int N)
{
    for (int i = 0; i < N; i++)
    {
        if (array[i] <= *min)
        {
            *min = array[i];
            *n_min = i;
        }
    }
}

void searchSUM(int array[], int *n_min, int *n_max, int *Sum, const int N)
{
    int n0, n1;
    n0 = *n_min;
    n1 = *n_max;
    if (n0 > n1)
    {
        ++n1;
        for (n1; n1 < n0; n1++)
        {
            *Sum += array[n1];
        }
    }
    else if (n1 > n0)
    {
        ++n0;
        for (n0; n0 < n1; n0++)
        {
            *Sum += array[n0];
        }
    }
    else *Sum = 0;
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