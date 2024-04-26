// Определить класс для работы с объектом «множество букв кириллицы».
// Реализовать: объединение двух множеств, пересечение двух множеств,
// разность двух множеств, добавление элемента во множество, удаление
// элемента из множества.

#include <iostream>
#include "Cyrillic.h"

using namespace std;

int main()
{
	system("chcp 1251");
	int size = 0;
	do
	{
		cout << "Enter the size of the set: ";
		cin >> size;
	}
	while (size < 1);

	// For check all methods and constructors
		//With parametr, copy, move and operators
		CyrillicSet Alphabet1(size);
		cout << "Alphabet1: ";
		Alphabet1.output_set();

		CyrillicSet Alphabet2(Alphabet1);
		cout << "Alphabet2: ";
		Alphabet2.output_set();

		cout << "Alphabet1: ";
		Alphabet1.output_set();

		CyrillicSet Alphabet3(move(Alphabet1));
		cout << "Alphabet3: ";
		Alphabet3.output_set();

		cout << "Alphabet1: ";
		Alphabet1.output_set();

		CyrillicSet Alphabet4 = Alphabet2;
		cout << "Alphabet4: ";
		Alphabet4.output_set();

		cout << "Alphabet2: ";
		Alphabet2.output_set();

		CyrillicSet Alphabet6 = move(Alphabet2);
		cout << "Alphabet6: ";
		Alphabet3.output_set();

		cout << "Alphabet2: ";
		Alphabet2.output_set();
		//
}
