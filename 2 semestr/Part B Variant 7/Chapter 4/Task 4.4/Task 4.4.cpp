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
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "Конструкторы\n";
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
		//	Объединение, пересечение, разность
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "Операции с множествами\n";
		CyrillicSet Alphabet7(size);
		cout << "Alphabet7: ";
		Alphabet7.output_set();

		CyrillicSet Alphabet8(size);
		cout << "Alphabet8: ";
		Alphabet8.output_set();

		CyrillicSet Alphabet9 =  Alphabet7 || Alphabet8;
		cout << "Alphabet9: ";
		Alphabet9.output_set();

		CyrillicSet Alphabet10 = Alphabet7 && Alphabet8;
		cout << "Alphabet10: ";
		Alphabet10.output_set();

		CyrillicSet Alphabet11 = Alphabet7 / Alphabet8;
		cout << "Alphabet11: ";
		Alphabet11.output_set();

		CyrillicSet Alphabet12 = Alphabet8 / Alphabet7;
		cout << "Alphabet12: ";
		Alphabet12.output_set();

		// Операторы ввода - вывода
		CyrillicSet Alphabet13(size);
		cout << "Alphabet13: ";
		Alphabet13.output_set();
		cout << "Alphabet13: ";
		cout << Alphabet13;

		CyrillicSet Alphabet14(1);
		cout << "Alphabet14: ";
		cin >> Alphabet14;
		Alphabet14.output_set();
		cout << "Alphabet14: ";
		cout << Alphabet14;
		//
}
