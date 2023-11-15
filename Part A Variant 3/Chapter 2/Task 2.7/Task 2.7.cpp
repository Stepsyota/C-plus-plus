//Заданы натуральные числа m, n. Вводятся целые числа а1, ..., an.
//  Вычислить b1 + ... + bm, где b1 = а1 + а2 + ... + an;
// b2 = а1^2 + а2^2 + ... + an^2;
#include <iostream>
using namespace std;

int main()
{
	int m, n, a;
	cout << "m = "; cin >> m;
	cout << "n = "; cin >> n;
	int b1 = 0;
	int sumb = 0;
	if (m < 0 || n < 0)
	{
		cout << "Need a positive n and m";
		return 0;
	}

	cout << "Enter the a value" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << " "; cin >> a;
		for (int i = 1; i <= m; i++)
		{
			sumb += pow(a, i);
		}
	}
	cout << "Amount = " << sumb;
	return 0;
}