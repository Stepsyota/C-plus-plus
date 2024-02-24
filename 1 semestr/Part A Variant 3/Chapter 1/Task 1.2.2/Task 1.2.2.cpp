// Присвоить целой переменной d четвертую цифру из дробной части положительного вещественного числа x.

#include <iostream>      

using namespace std;
int main()
{
	int d;
	double x;
	cout << "x=";
	cin >> x;
	d = int(x * 10000) % 10;
	cout << "d=" << d;
	return 0;
}