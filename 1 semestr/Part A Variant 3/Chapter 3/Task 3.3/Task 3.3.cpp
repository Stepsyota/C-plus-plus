//Дана действительная матрица порядка n. Найти сумму элементов,
//расположенных в закрашенной части матрицы на рисунке.
#include <iostream>
using namespace std;

int main()
{
	const int N = 5;
	double array[N][N];

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
		for (int i = 0; i < N; i++)
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
	case Choise::WithRand:
	{
		for (int i = 0; i < N; i++)
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
	case Choise::ByUser:
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
	default: cout << "The program is stopped" << endl;
		return 0;
	}


	double Sum = 0;
	cout << "Suitable elements: ";
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = N - 1 - i; j < N; j++)
		{
			Sum += array[i][j];
			cout << array[i][j] << " ";
		}
	}
	cout << endl << "Sum = " << Sum;
	return 0;
}