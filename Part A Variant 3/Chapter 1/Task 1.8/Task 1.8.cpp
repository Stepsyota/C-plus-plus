// Вычислить, объяснить результат выражения, используя поразрядные операции,
//  для заданных значений целых переменных a, b, c.
#include <iostream>
using namespace std;

int main()
{
	int a, b, c, result;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "c = "; cin >> c;

	result = a | b & ~c;
	cout << "Result = " << result;
	return 0;
}