﻿#include "Task 6.1.h"

int main()
{
	cout << "Check for coins\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	Coin coin1;
	cout << "Coin1:\n";
	coin1.print();
	
	Coin coin2(authors[0], 1000, places_of_creation[0], designations_of_coin[0],
		materials_coin[0], 1000, 1200, 1350, images_on_coin[0], values_coin[0]);
	cout << "Coin2:\n";
	coin2.print();

	Coin coin3(coin2);
	cout << "Coin3:\n";
	coin3.print();

	Coin coin4(move(coin2));
	cout << "Coin4:\n";
	coin4.print();
	cout << "Coin2:\n";
	coin2.print();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Check for edged weapon\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	EdgedWeapon weap1;
	cout << "Weapon1\n";
	weap1.print();

	EdgedWeapon weap2(authors[0], 1000, places_of_creation[0], designations_of_edged_weapon[0],
		materials_edged_weapon[0], 1000, 1200, 1350, types_of_edged_weapon[0], 0.15);
	cout << "Weapon2\n";
	weap2.print();

	EdgedWeapon weap3(weap2);
	cout << "Weapon3\n";
	weap3.print();

	EdgedWeapon weap4(move(weap2));
	cout << "Weapon4\n";
	weap4.print();
	cout << "Weapon2\n";
	weap2.print();

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Check for painting\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	Painting paint1;
	cout << "Paint1\n";
	paint1.print();

	Painting paint2(authors[0], 1000, places_of_creation[0], designations_of_painting[0],
		genres_of_painting[0], image_on_painting[0], types_of_painting[0], dimensions_of_painting[0]);
	cout << "Paint2\n";
	paint2.print();

	Painting paint3(paint2);
	cout << "Paint3\n";
	paint3.print();

	Painting paint4(move(paint2));
	cout << "Paint4\n";
	paint4.print();
	cout << "Paint2\n";
	paint2.print();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Check for sculptures\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	Sculpture scupl1;
	cout << "Scupl1\n";
	scupl1.print();

	Sculpture scupl2(authors[0], 1000, places_of_creation[0], designations_of_painting[0],
		genres_of_painting[0], image_on_painting[0], materials_sculpture[0], dimensions_of_sculpture[0]);
	cout << "Scupl2\n";
	scupl2.print();

	Sculpture scupl3(scupl2);
	cout << "Scupl3\n";
	scupl3.print();

	Sculpture scupl4(move(scupl2));
	cout << "Scupl4\n";
	scupl4.print();
	cout << "Scupl2\n";
	scupl2.print();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Check for photos\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	Photo photo1;
	cout << "Photo1\n";
	photo1.print();

	Photo photo2(authors[0], 1000, places_of_creation[0], designations_of_painting[0],
		genres_of_painting[0], image_on_painting[0], formats_photo[0], 0);
	cout << "Photo2\n";
	photo2.print();

	Photo photo3(photo2);
	cout << "Photo3\n";
	photo3.print();

	Photo photo4(move(photo2));
	cout << "Photo4\n";
	photo4.print();
	cout << "Photo2\n";
	photo2.print();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	
	cout << coin4 << endl;
	cout << photo4 << endl;
	cout << weap4 << endl;
	cout << scupl4 << endl;
	cout << paint4 << endl;
	return 0;
}