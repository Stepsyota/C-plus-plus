//Удалить в строке все буквы 'B', непосредственно за которыми
//  идёт цифра. Удалить из текста символы, являющиеся
//  строчными латинскими буквами.

#include <iostream>

using namespace std;

void Output_str(char []);
void Check_letter_B(char[], int);
void Del_letter_B(char [], int);
void Check_all_letters(char [], int);
void Del_all_letters(char[], int);

int main()
{
	char str[] = "B1jFlBd2Op";
	Output_str(str);
	cout << endl;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		Check_letter_B(str, i);
		Check_all_letters(str, i);
		cout << str[i];
	}
	return 0;
}

void Output_str(char str[])
{
	for (int i = 0; str[i] != '\0'; ++i)
	{
		cout << str[i];
	}
}

void Check_letter_B(char str[], int i)
{
	if (str[i] == 'B' && str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		Del_letter_B(str, i);
	}
}

void Del_letter_B(char str[], int i)
{
	for (int j = i + 1; j < str[i] != '\0'; j++)
	{
		str[j - 1] = str[j];
		str[j - 1] = '\0';
	}
}

void Check_all_letters(char str[], int i)
{
	if (str[i] >= 'a' && str[i] <= 'z')
	{
		Del_all_letters(str, i);
	}
}

void Del_all_letters(char str[], int i)
{
	for (int j = i + 1; j < str[i] != '\0'; j++)
	{
		str[j - 1] = str[j];
		str[j - 1] = '\0';
	}
}