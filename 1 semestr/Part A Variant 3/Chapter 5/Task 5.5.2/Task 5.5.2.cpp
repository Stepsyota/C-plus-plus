//Написать программу перевода целых чисел из
//десятичной системы счисления в двоичную.

#include <iostream>

using namespace std;
void check_number(double, int*, int*);
void transf_str(int*, int*, char [], int*);
void flip_str(char[], int*, int);

int main()
{
		const int N = 100;
		char str[N] = { 0 };
		double number_d = 0;
		int number = 0, check = 0, remain = 0, i = 0, temp = 0;

		cout << "Enter the number: ";
		cin >> number_d;

		check_number(number_d, &number, &check);
		if (check == 1)
		{
		}
		else
		{
			return 0;
		}

		transf_str(&remain, &number, str, &i);
		flip_str(str, &temp, i);

		cout << "A number in binary form: " << str;

	return 0;
}

void check_number(double number_d, int *number, int *check)
{
	if (number_d == int(number_d))
	{
		*number = int(number_d);
		*check = 1;
	}
	else
	{
		cout << "The number is not an integer";
		*check = 0;
	}
}

void transf_str(int *remain, int *number, char str[], int *i)
{
	do
	{
		*remain = *number % 2;
		*number /= 2;
		str[*i] = char('0' + *remain);
		*i += 1;
	} while (*number > 0);
}

void flip_str(char str[], int *temp, int i)
{
	for (int j = 0; j < i / 2; ++j)
	{
		*temp = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = *temp;
	}
}