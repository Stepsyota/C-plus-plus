// Ввести с клавиатуры целое число n. Определить все способы выплаты 
// суммы n с помощью монет достоинством в 1, 5, 10, 15, 20, 50 копеек.
#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "n = ";
	cin >> n;
	cout << "Payment methods:" << endl;
	int k1, k5, k10, k15, k20, k50;

	for (k50 = 0; k50 <= n; k50++)
	{
		for (k20 = 0; k20 <= (n - k50 * 50) / 20; k20++)
		{
			for (k15 = 0; k15 <= (n - k50 * 50 - k20 * 20) / 15; k15++)
			{
				for (k10 = 0; k10 <= (n - k50 * 50 - k20 * 20 - k15 * 15) / 10; k10++)
				{
					for (k5 = 0; k5 <= (n - k50 * 50 - k20 * 20 - k15 * 15 - k10 * 10) / 5; k5++)
					{
						k1 = (n - k50 * 50 - k20 * 20 - k15 * 15 - k10 * 10 - k5 * 5);
						cout << "1 kopeek = " << k1 << " | 5 kopeek = " << k5 << " | 10 kopeek = " << k10 << " | 15 kopeek = " << k15 << " | 20 kopeek = " << k20 << " | 50 kopeek = " << k50 << endl;
					}
				}
			}
		}
	}
	return 0;
}