// Определить номер последней строки, содержащей наименьшее
//  число знаков '+' и '-'.
#include <iostream>
using namespace std;

int main()
{
	const int N = 55;
	char array[N][N];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			array[i][j] = static_cast<char>(43 + (rand() % 13));
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl << endl;
	}
	int counter = 0;
	int min = N;
	int line_min = 0;
	for (int i = N - 1; i >= 0; --i)
	{
		for (int j = N - 1; j >= 0; --j)
		{
			if (array[i][j] == static_cast<char>(43) || array[i][j] == static_cast<char>(45))
			{
				++counter;
			}
		}
		if (counter == 0)
		{
			min = min;
		}
		else if (min > counter)
		{
			min = counter;
			line_min = i + 1;
		}
		counter = 0;
	}
	if (min == N && line_min == 0)
	{
		cout << "There are no such signs in the given array" << endl;
		return 0;
	}
	cout << endl << "Minimum number of characters (+ && -) = " << min << endl;
	cout << "They are in the line number " << line_min;
	return 0;
}