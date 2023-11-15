// Задано натуральное n, вещественное x. Вычислить результат выражения
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	int n;
	int sum1 = 0;
	double amount = 0;
	int factorial = 1;
	cout << "n = "; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		factorial *= i;
		for (int j = 1; j <= i; j++)
		{
			sum1 += i + j * j;
		}
		amount += factorial * sum1;
		sum1 = 0;
	}
	cout << "Amount = " << amount;
	return 0;
}