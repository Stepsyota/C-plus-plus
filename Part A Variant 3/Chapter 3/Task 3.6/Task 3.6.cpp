//	Для тестирования программы предусмотреть возможность задавать
//  элементы массива различным образом : при описании с инициализацией,
//  присвоением значений (в том числе случайных), или вводом необходимых
//  значений. 
// 
//	Получить квадратную матрицу порядка n, элементами которой являются
//  заданные действительные числа а1, ..., аnn, расположенные в ней по схеме,
//  которая приведена на рисунке.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const int N = 5;
	float array[N][N];
	float massiv[N * N];

	enum Choise
	{
		Uninited = 0, WithConst, WithRand, ByUser
	};
	cout << "Choose the type of initialization: \n"
		<< (int)Choise::WithConst << ". constants\n"
		<< (int)Choise::WithRand << ". random\n"
		<< (int)Choise::ByUser << ". manually\n";
	int ch = 0;
	cin >> ch;

	switch ((Choise)ch)
	{
	case Choise::WithConst:
	{
		for (int i = 0; i < N * N; i++)
		{
			massiv[i] = i;
			cout << massiv[i] << " ";
		}
		cout << endl;
		break;
	}
	case Choise::WithRand:
	{
		for (int i = 0; i < N * N; i++)
		{
			massiv[i] = rand() % 200;
			cout << massiv[i] << " ";
		}
		cout << endl;
		break;

	}
	case Choise::ByUser:
	{
		for (int i = 0; i < N * N; i++)
		{
			cin >> massiv[i];
			cout << massiv[i] << " ";
		}
		cout << endl;
		break;
	}
	default: cout << "The program is stopped" << endl;
		return 0;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			array[i][j] = massiv[(N * i) + j];
		}
	}

	float array2[N][N];
	cout << "The matrix after the change: " << endl;
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (i == 0 || i % 2 == 0)
			{
				array2[i][j] = array[i][N - j - 1];
			}
			else
			{
				array2[i][j] = array[i][j];
			}
			cout << setw(3) << array2[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}