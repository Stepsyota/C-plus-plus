#include <iostream>
#include "RatioFrac.h"
using namespace std;


int pow(int, int);
void calc_expression();

int main()
{
	cout << "First: ";
	RatioFrac first = RatioFrac();
	first.print_frac();

	cout << "Second: ";
	RatioFrac second = RatioFrac(2, 7, 8);
	second.print_frac();

	cout << "Third: ";
	RatioFrac third(second);
	third.print_frac();

	cout << "Fourth: ";
	RatioFrac fourth(move(third));
	fourth.print_frac();

	cout << "Third: ";
	third.print_frac();

	second += fourth;
	cout << "Second: ";
	second.print_frac();

	second -= fourth;
	cout << "Second: ";
	second.print_frac();

	cout << "Third: ";
	RatioFrac third(second);
	third.print_frac();

	cout << "Fourth: ";
	RatioFrac fourth(move(third));
	fourth.print_frac();
	//fourth.razn(second);
	//cout << "Fourth: ";
	//fourth.print_frac();

	//int i, j, k = 0;
	//cin >> i >> j >> k;
	//cout << "Sixth: ";
	//RatioFrac sixth = RatioFrac(i, j, k);
	//sixth.print_frac();

	//cin >> i >> j >> k;
	//cout << "Seventh: ";
	//RatioFrac seventh = RatioFrac(i, j, k);
	//seventh.print_frac();

	//sixth.summa(seventh);
	//cout << "Sixth: ";
	//sixth.print_frac();

	//sixth.razn(seventh);
	//cout << "Sixth: ";
	//sixth.print_frac();
	//calc_expression();
}

void calc_expression()
{
	RatioFrac Summa;
	for (int i = 1; i <= 20; ++i)
	{
		RatioFrac tek_chlen(0, 1, pow(2,i));
		Summa.summa(tek_chlen);
	}
	Summa.print_frac();
}

int pow(int a, int b)
{
	int c = 1;
	for (int i = 0; i < b; ++i)
	{
		c *= a;
	}
	return c;
}