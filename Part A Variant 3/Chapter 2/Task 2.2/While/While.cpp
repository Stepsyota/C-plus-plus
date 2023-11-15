//Написать программу вычисления условной функции в точках хi e[х0; хn]; хi = х0 + iмоудульх,
//  i = 0, 1… n. Вывод результатов обеспечить в виде таблицы со столбцами значений аргумента,
//  функции и номера ветви расчёта. Столбцы должны иметь заголовки.Реализовать 3 версии
//  программы с использованием циклов while, do - while, for

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	int x0 = 0;
	int xn = 3;
	float delx = 0.1;
	float a = -0.5;
	double y, xi;
	int n;
	int i = 0;
	cout << "Input n: ";
	cin >> n;
	cout << "xi" << setw(20) << "y" << endl;
	while (i < n)
	{
		double xi = x0 + i * delx;
		cout << xi;
		if (xi < 1)
		{
			y = 1;
			cout << setw(20) << y << endl;
		}

		if (xi == 1)
		{
			cout << setw(20) << "y does not exist" << endl;
		}

		if (xi > 1 && xi <= 2)
		{
			y = a * pow(xi, 2) * log(xi);
			cout << setw(20) << y << endl;
		}
		if (xi > 2)
		{
			y = exp(a * xi) * cos(2 * xi);
			cout << setw(20) << y << endl;
		}
		i++;
	}
	return 0;
}