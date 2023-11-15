//Для тестирования программы предусмотреть возможность задавать элементы массива различным
// образом : при определении с инициализацией, случайными числами, вводом с клавиатуры.
// Определите сумму элементов массива, расположенных между минимальным и максимальным значениями не включая их.

#include <iostream>
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



    //seatch of max
    int n_max = 0;
    int max = array[0];
    for (int i = 0; i < N; i++)
        if (max < array[i])
        {
            max = array[i];
            n_max = i;
        }
    cout << "max = " << max << endl;
    //max

    //search of min
    int n_min = 0;
    int min = array[0];
    for (int i = 0; i < N; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
            n_min = i;
        }
    }
    cout << "min = " << min << endl;
    //min

  //Sum 
    if (n_min > n_max)
    {
        int n0 = 0, n1 = 0;
        n0 = n_min - 1;
        n1 = n_max + 1;
        for (n1; n1 <= n0; n1++)
        {
            Sum += array[n1];
        }
    }
    if (n_max > n_min)
    {
        int n0 = 0, n1 = 0;
        n0 = n_min + 1;
        n1 = n_max - 1;
        for (n0; n0 <= n1; n0++)
        {
            Sum += array[n0];
        }
    }
    cout << "Sum = " << Sum << endl;
    return 0;
}