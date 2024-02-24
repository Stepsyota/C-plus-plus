// Даны натуральные числа n, m. Получить все общие кратные, меньшие m*n.

#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cout << "n = "; cin >> n;
	cout << "m = "; cin >> m;
	int k = 0;

	for (int i = 1; i < n * m; i++)
	{
		if (i % n == 0 && i % m == 0)
		{
			cout << i << " is a common multiple" << endl;
			k++;
		}
	}

	if (k == 0)
	{
		cout << "No solution";
	}
	return 0;
}