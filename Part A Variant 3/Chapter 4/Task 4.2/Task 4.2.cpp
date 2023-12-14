//Написать программу перевода целых чисел из
//десятичной системы счисления в двоичную.
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    const int N = 100;
    char str[N] = { 0 };
    double number_d = 0;
    int number;
    cout << "Enter the number: ";
    cin >> number_d;

    if (number_d == int(number_d))
    {
        number = int(number_d);
    }
    else
    {
        cout << "The number is not an integer";
        return 0;
    }

    int remain;
    int i = 0;
    do
    {
        remain = number % 2;
        number /= 2;
        str[i] = char('0' + remain);
        i++;

    } while (number > 0);

    int temp;

    for (int j = 0; j < i / 2; ++j)
    {
        temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }

    cout << "A number in binary form: " << str;
    return 0;
}

