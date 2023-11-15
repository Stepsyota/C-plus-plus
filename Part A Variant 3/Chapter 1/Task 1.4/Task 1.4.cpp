//Даны вещественные числа x, y. Определить, принадлежит ли точка 
//с координатами x, y заштрихованной части плоскости.

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double x, y;
	cout << "x= "; cin >> x;
	cout << "y= "; cin >> y;

	if (x <= 1 && x >= 0 && y >= 0 && y <= 1 && x + y <= 1 || // 1 chet
		x <= 0 && x >= -1 && y >= 0 && y <= 1 && x - y >= -1 || // 2 chet
		x <= 1 && x >= -1 && y >= -1 && y <= 0 && pow(x, 2) + pow(y, 2) <= 1) // 3,4 chet
	{
		cout << "Belongs to the graph";
	}
	else
	{
		cout << "Does not belong to the schedule";
	}
	return 0;
}