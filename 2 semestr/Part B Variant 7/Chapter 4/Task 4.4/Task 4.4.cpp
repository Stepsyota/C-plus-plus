﻿// Определить класс для работы с объектом «множество букв кириллицы».
// Реализовать: объединение двух множеств, пересечение двух множеств,
// разность двух множеств, добавление элемента во множество, удаление
// элемента из множества.

#include <iostream>
#include "Cyrillic.h"

using namespace std;

int main()
{
	system("chcp 1251");
	CyrillicSet Alphabet(30);
	Alphabet.output_set();
}