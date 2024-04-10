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


class Coins
{
protected:
	char* designation;
private:
	double denomination;
	unsigned int start_of_use;
	unsigned int end_of_use;
};

class Edged_Weapon : public Coins
{
private:
	unsigned int start_dating;
	unsigned int end_dating;
};

class Photos
{
protected:
	char* what_is_pictured;
	unsigned int creation_time;
};

class Paintings : public Photos
{
protected:
	char* author;
};

class Statuettes : public Paintings
{

};