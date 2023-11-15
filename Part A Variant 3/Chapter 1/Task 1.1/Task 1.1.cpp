//Написать программу, вычисляющую значение функции для различных значений аргумента
//  x, задавая его как целое число, как вещественное число. Обеспечить варианты : ввода
//  данного с клавиатуры, инициализации данного в тексте программы. Проанализировать
//  результат выполнения программы при x = 0, x = -1.
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main()
{
	int x;
	double y;
	cout << "x=";
	cin >> x;
	y = (sin(M_PI * pow(x, 2)) + log(pow(x, 2))) / (sin(M_PI * pow(x, 2)) + sin(x) + log(pow(x, 2)) + pow(x, 2) + (pow(M_E, cos(x))));
	cout << "y = " << y << endl;
	return 0;
}