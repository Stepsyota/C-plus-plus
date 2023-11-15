//Получить квадратную матрицу заданного порядка n.
#include <iostream>
using namespace std;

int main()
{
	const int N = 10;
	double array[N][N];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			array[i][j] = N - j - i;
			if (array[i][j] < 0)
			{
				array[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}