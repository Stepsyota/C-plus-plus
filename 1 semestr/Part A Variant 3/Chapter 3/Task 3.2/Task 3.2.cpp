//Задана целочисленная матрица порядка n * n. Для тестирования программы предусмотреть возможность
//  задавать элементы массива различным образом : при определении с инициализацией, случайными числами,
//  вводом с клавиатуры. Выбор способа инициализации массива сделать через меню с использованием перечисления(enum).
// 
//Определить, является ли матрица симметричной (относительно главной диагонали).Найти максимальный элемент среди стоящих на
//главной и побочной диагонали и поменять его местами с элементом, стоящим на пересечении этих диагоналей.

#include <iostream>
using namespace std;

int main()
{
    const int N = 5;
    int Sum = 0;
    int array[N][N];

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
    {   for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            array[i][j] = i;
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    break;
    }
    case enmArrayInit::WithRand:
    {   for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            array[i][j] = rand() % 200;
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    break;
    }
    case enmArrayInit::ByUser:
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> array[i][j];
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
        break;
    }
    default:  cout << "The program is stopped" << endl;
        return 0;
    }

    //Проверка на симметричность матрицы
    int simm = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (array[i][j] == array[j][i])
            {

            }
            else
            {
                simm = 0;
            }
        }
    }
    if (simm == 1)
    {
        cout << "The matrix is symmetric" << endl;
    }
    else
    {
        cout << "The matrix is not symmetric" << endl;
    }
    //

    //Нахождение максимального элемента матрицы
    int max = array[0][0];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                if (max <= array[i][j])
                {
                    max = 0;
                    max += array[i][j];
                }
                if (max <= array[i][N - j - 1])
                {
                    max = 0;
                    max += array[i][N - j - 1];
                }
            }

        }
    }
    cout << "Maximum element = " << max << endl;
    //

    //Вывод и нахождение местоположения максимального элемента матрицы
    int imax, jmax, ichange, jchange;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                if (max == array[i][j])
                {
                    imax = i;
                    jmax = j;
                    cout << "The maximum element is in " << imax << " the row and " << jmax << " column" << endl;
                }
                if (max == array[i][N - j - 1])
                {
                    imax = i;
                    jmax = N - j - 1;
                    cout << "The maximum element is in " << imax << " the row and " << jmax << " column" << endl;
                }

            }

        }
    }
    //

    // Проверка на существование элемента пересечения диагоналей и последующая замена элементов
    if (N % 2 == 0)
    {
        cout << "The matrix does not have an intersection element of the main and side diagonal";
        return 0;
    }
    else
    {
        int tempzamena;
        ichange = (N - 1) / 2;
        jchange = (N - 1) / 2;
        tempzamena = array[ichange][jchange];
        array[ichange][jchange] = max;
        array[imax][jmax] = tempzamena;

    }
    //

    // Вывод матрицы
    cout << "The matrix after the change:" << endl;
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            cout << array[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}
//0 1 2 3 4 1 2 3 4 0 2 3 4 0 1 3 4 0 1 2 4 0 1 2 3 - симметричная матрица