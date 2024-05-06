#pragma once

#include <iostream>

using namespace std;

/*
1.ћонеты
Х наименование (строка)
Х автор (строка)
Х врем€ создани€ (год)
Х место создани€ (строка)

Х номинал (может быть как целым, так и дол€ми от целого)
Х годы использовани€ (диапазон лет Ц два целочисленных года)

Х что изображено (строка)
Х материал (строка)
Х тираж (число)

2. ’олодное оружие
Х наименование (строка)
Х автор (строка)
Х врем€ создани€ (год)
Х место создани€ (строка)

Х приблизительна€ датировка (диапазон лет Ц два целочисленных года)

Х материал (строка)
Х тираж (число)
 
3.  артины
Х наименование (строка)
Х автор (строка)
Х врем€ создани€ (год)
Х место создани€ (строка)

Х что изображено (строка)
Х размер (строка)
 
4. —татуэтки
Х наименование (строка)
Х автор (строка)
Х врем€ создани€ (год)
Х место создани€ (строка)

Х материал (строка)
Х что изображено (строка)
Х размер (строка)
 
5. ‘отографии
Х наименование (строка)
Х автор (строка)
Х врем€ создани€ (год)
Х место создани€ (строка)

Х что изображено (строка)
*/


class ArtObject
{
	char* author;
	int time_of_creation;
	char* place_of_creation;
	char* designation;

	ArtObject();
};
/************************************************/
class AplliedArtObject : public ArtObject
{
	char* material;
	int number_of_copies;
	int	year_of_start_of_use;
	int year_of_end_of_use;
};

class Coin : public AplliedArtObject
{
	char* what_is_depicted;
	double value;
};

class EdgedWeapon : public AplliedArtObject
{
	char* type;
	double degree_of_sharpening;
};
/************************************************/
class VisualArtObject : public ArtObject
{
	char* genre;
	char* what_is_depicted;
};

class Painting : public VisualArtObject
{
	char* type_of_paint;
	char* dimensions;
};

class Sculpture : public VisualArtObject
{
	char* material;
	char* dimensions;
};

class Photo : public VisualArtObject
{
	char* photo_format;
	bool color_photo;
};
/************************************************/