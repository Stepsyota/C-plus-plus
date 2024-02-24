// Получить строку, составленную из последних букв
//  слов исходной строки.
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    const int N = 100;
    char str[N] = { 0 };
    cout << "Enter the text: ";
    while (cin.getline(str, N))
    {
        if (strcmp(str, ""))
        {
            break;
        }  
    }
    cout << str;
    char str2[N] = { 0 };
    int counter = 0;
    for (int i = 1; i < N; ++i)
    {
        if ((*(str + i) == ' ' || *(str + i) == '\0' || *(str + i) == ',' || *(str + i) == '.') &&
           ((*(str + i - 1) >= 'a' && *(str + i - 1) <= 'z') ||
           (*(str + i - 1) >= 'A' && *(str + i - 1) <=  'Z')))
        {  
            str2[counter] = str[i - 1];
            counter++;
        }
    }
    cout << endl << str2;
    return 0;
}