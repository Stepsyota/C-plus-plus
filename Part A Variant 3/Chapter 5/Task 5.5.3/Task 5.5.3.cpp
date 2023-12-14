// Получить строку, составленную из последних букв
//  слов исходной строки.

#include <iostream>

using namespace std;

void check_str(char [], const int);
void create_sec_str(const int, char [], char [], int*);
void check_letter(char [], char [], int, int*);
void form_sec_str(char [], char [], int, int*);

int main()
{
	
		const int N = 100;
		char str[N] = { 0 };
		cout << "Enter the text: ";
		check_str(str, N);

		char str2[N] = { 0 };
		int counter = 0;

		create_sec_str(N, str, str2, &counter);
		cout << endl << str2;
		
	return 0;
}
void check_str(char str[], const int N)
{
	while (cin.getline(str, N))
	{
		if (strcmp(str, ""))
		{
			break;
		}
	}
	cout << str;
}

void create_sec_str(const int N, char str[], char str2[], int *counter)
{
	for (int i = 1; i < N; ++i)
	{
		check_letter(str, str2, i, counter);
	}
}

void check_letter(char str[], char str2[], int i, int *counter)
{
	if ((*(str + i) == ' ' || *(str + i) == '\0' || *(str + i) == ',' || *(str + i) == '.') &&
		((*(str + i - 1) >= 'a' && *(str + i - 1) <= 'z') ||
			(*(str + i - 1) >= 'A' && *(str + i - 1) <= 'Z')))
	{
		form_sec_str(str, str2, i, counter);
	}
}

void form_sec_str(char str[], char str2[], int i, int *counter)
{
	str2[*counter] = str[i - 1];
	*counter += 1;
}