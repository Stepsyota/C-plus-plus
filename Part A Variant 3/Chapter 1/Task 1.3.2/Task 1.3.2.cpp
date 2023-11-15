// Объяснить результат и вывести на экран результат логического выражения
//T = S для заданных значений логических переменных.

#include <iostream>
using namespace std;

int main()
{
	bool T, S;
	bool a = 1;
	bool b = 0;
	bool c = 0;
	bool d = 0;

	T = (a || b) && !c && !d;
	S = a && !(c || d) || b && !(c || d);
	cout << "T= " << T << endl;
	cout << "S= " << S << endl;
	if (T == S)
		cout << "T=S";
	else
		cout << " T not equal S";
	return 0;
}