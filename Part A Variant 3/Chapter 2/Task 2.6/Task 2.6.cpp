﻿// Среди всех четырехзначных чисел получить все простые числа, у
//  каждого из которых сумма первых двух цифр равна сумме двух последних цифр.
#include <iostream>
using namespace std;
int main()
{
	int k = 0;
	int sum1, sum2, i;
	for (i = 1000; i < 10000; i++)
	{
		sum1 = ((i / 1000) % 10) + ((i / 100) % 10);
		sum2 = (i % 10) + ((i / 10) % 10);
		for (int j = 1000; j < 10000; j++)
		{
			if (i % j == 0)
			{
				k += 1;
			}
		}
		if (k == 2 && sum1 == sum2)
		{
			cout << "i = " << i << endl;
		}
		k = 0;
	}
	return 0;
}