//Удалить в строке все буквы 'B', непосредственно за которыми
//  идёт цифра. Удалить из текста символы, являющиеся
//  строчными латинскими буквами.
#include <iostream>

using namespace std;
int main()
{
	char str[] = "B1jFlBd2Op";
	for (int i = 0; str[i] != '\0'; ++i)
	{
		cout << str[i];
	}
	cout << endl;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] == 'B' && str[i + 1] >= '0' && str[i + 1] <= '9')
		{
			for (int j = i + 1; j < str[i] != '\0'; j++)
			{
				str[j - 1] = str[j];
				str[j - 1] = '\0';
			}
		}
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			for (int j = i + 1; j < str[i] != '\0'; j++)
			{
				str[j - 1] = str[j];
				str[j - 1] = '\0';
			}
		}
		cout << str[i];
	}
	return 0;
}