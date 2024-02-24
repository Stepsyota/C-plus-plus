//Написать функции для заполнения матрицы случайными числами, ввода с клавиатуры, вывода на экран.
// Выполнить задания 3.2, оформив их через функции. Все необходимые данные для функций должны
//  передаваться в качестве параметров.

//﻿Задана целочисленная матрица порядка n * n. Для тестирования программы предусмотреть возможность
//  задавать элементы массива различным образом : при определении с инициализацией, случайными числами,
//  вводом с клавиатуры. Выбор способа инициализации массива сделать через меню с использованием перечисления(enum).
// 
//Определить, является ли матрица симметричной (относительно главной диагонали).Найти максимальный элемент среди стоящих на
//главной и побочной диагонали и поменять его местами с элементом, стоящим на пересечении этих диагоналей.

#include <iostream>
using namespace std;

void Output_array(int*, const int);
void Fill_const(int *, const int);
void Fill_rand(int *, const int);
void Fill_user(int *, const int);
int Replace_diag_element(int *, const int, int*, int*);
void Find_max(int*, const int, int*, int*);
void Check_simm(int*, const int, int*);

int main()
{
    const int N = 5;
    int Sum = 0;
    int array[N][N];

    int choise;
    cout << "Choose the type of initialization: \n1.Const \n2. Random \n3. Manually" << endl;
    cin >> choise;
    switch (choise)
    {
        case 1:
        {
            Fill_const((int*)array, N);
            Output_array((int*)array, N);
            break;
        }

        case 2:
        {
            Fill_rand((int*)array, N);
            Output_array((int*)array, N);
            break;
        }

        case 3:
        {
            Fill_user((int*)array, N);
            Output_array((int*)array, N);
            break;
        }

        default:
        {
            cout << "The program is stopped" << endl;
            return 0;
        }
    }
    cout << endl;
    int simm = 1;
    Check_simm((int*)array, N, &simm);

    int max = 0, index_max = 0;
    Find_max((int*)array, N, &max, &index_max);
    cout << endl << "Maximum element = " << max << endl << endl;
     
    if (Replace_diag_element((int*)array, N, &max, &index_max) == 1)
    {
        return 0;
    }

    cout << "The matrix after the change:" << endl;
    Output_array((int*)array, N);

    return 0;
 }



void Check_simm(int* array2, const int N, int *simm)
{
    for (int i = 0; i <= (N * N - 1) / 2; ++i)
    {
        if (array2[i] == array2[(N*N - 1) - i])
        {
        }
        else
        {
            *simm = 0;
            cout << "The matrix is not symmetric" << endl;
            break;
        }
    }
    if (*simm == 1)
    {
        cout << "The matrix is symmetric" << endl;
    }
}

void Find_max(int* array2, const int N, int *max, int *index_max)
{
    *max = array2[0];
    for (int i = 0; i < N * N; ++i)
    {
        if (i % (N+1) == 0 || i % (N-1) == 0)
        {
            if (*max < array2[i])
            {
                *max = array2[i];
                *index_max = i;
            }     
        }
    }
}

int Replace_diag_element(int* array2, const int N, int *max, int *index_max)
{
    if (N % 2 == 0)
    {
        cout << "The matrix does not have an intersection element of the main and side diagonal";
        return 1;
    }
    else
    {
        int index_change = ((N * N - 1) / 2);
        if (index_change == *index_max)
        {
            cout << "The maximum element stands at the intersection of the diagonals" << endl;
            return 2;
        }
        else
        {
            int tempzamena;
            tempzamena = array2[index_change];
            array2[index_change] = *max;
            array2[*index_max] = tempzamena;
        }
    }
    return 0;
}

void Fill_const(int* array2, const int N)
{
    for (int i = 0; i < N * N; i++)
    {
        array2[i] = i;
    }
}

void Fill_rand(int* array2, const int N)
{
    for (int i = 0; i < N * N; i++)
    {
        array2[i] = rand() % 200;
    }
}

void Fill_user(int* array2, const int N)
{
    cout << "Fill in the array using the keyboard" << endl;
    for (int i = 0; i < N * N; i++)
    {
        cin >> array2[i];
    }
}

void Output_array(int* array2, const int N)
{
    for (int i = 0; i < N * N; ++i)
    {
        cout << array2[i] << "\t";
        if ((i + 1) % N == 0 && i != 0 && i < N*N)
        {
            cout << endl;
        }
    }
}