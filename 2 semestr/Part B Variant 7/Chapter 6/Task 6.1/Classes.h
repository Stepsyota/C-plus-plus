#pragma once

#include <iostream>

using namespace std;

//1. ћонеты
//Х наименование (строка)
//Х номинал (может быть как целым, так и дол€ми от целого)
//Х годы использовани€ (диапазон лет Ц два целочисленных года)
// 
//2. ’олодное оружие
//Х наименование (строка)
//Х приблизительна€ датировка (диапазон лет Ц два целочисленных года)
// 
//3.  артины
//Х что изображено (строка)
//Х автор (строка)
//Х врем€ создани€ (год)
// 
//4. —татуэтки
//Х что изображено (строка)
//Х автор (строка)
//Х врем€ создани€ (год)
// 
//5. ‘отографии
//Х что изображено (строка)
//Х врем€ создани€ (год)

class Instance
{
protected:
	char* name;
	int year_start;
	int year_end;
};

class ArtObject
{
protected:
	char* what_is_puctured;
	int year_of_creation;
};

class Coins : public Instance
{
	double value;
};

class Edged_Weapon : public Instance
{
};

class Photos : public ArtObject
{
};

class Paintings : public ArtObject
{
	char* author;
};

class Statuettes : public ArtObject
{
	char* author;
};