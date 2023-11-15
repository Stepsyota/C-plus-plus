//Написать программу, которая по введённому значению аргумента вычисляет 
// значение функции, заданной в виде графика.

#include <iostream>
#include <math.h>

using namespace std;
int main()
{
	double x, y;
	int R = 3;
	cout << "x= "; cin >> x;

	if (x < -10 || x > 6)
	{
		cout << "Not defined with such an x";
	}
	if (x >= -10 && x < -7) // 1 segment
	{
		cout << "y = -2";
	}
	if (x >= -7 && x <= -5) // 2 segment
	{
		y = -0.5 * x - 2.5;
		cout << "y = " << y;
	}
	if (x > -5 && x < 0) // 3 segment
	{
		y = 0.6 * x + 3;
		cout << "y = " << y;
	}
	if (x >= 0 && x <= 3) // 4 segment
	{
		y = pow(pow(R, 2) - pow(x, 2), 0.5);
		cout << "y = " << y;
	}
	if (x > 3 && x <= 6) // 5 segment
	{
		y = -pow(pow(R, 2) - pow(6 - x, 2), 0.5);
		cout << "y = " << y;
	}
	return 0;
}