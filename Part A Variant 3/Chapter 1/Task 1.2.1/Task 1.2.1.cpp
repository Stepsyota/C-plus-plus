//Присвоить целой переменной h третью от
//  конца цифру в записи натурального
//  четырехзначного числа k.

#include <iostream>

using namespace std;

int main()
{
	int h;
	unsigned int k;
	cout << "k=";
	cin >> k;
	if (k > 9999 || k <= 999)
		cout << "Not suitable";
	else
	{
		h = (k / 100) % 10;
		cout << "h=" << h;
	}
	return 0;
}