#include "Task 6.1.h"

int main()
{
	cout << "Check for coins\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	Coin coin1;
	cout << "Coin1:\n";
	coin1.Print();
	
	Coin coin2(authors[0], 1000, places_of_creation[0], designations_of_coin[0],
		materials_coin[0], 1000, 1200, 1350, images_on_coin[0], values_coin[0]);
	cout << "Coin2:\n";
	coin2.Print();

	Coin coin3(coin2);
	cout << "Coin3:\n";
	coin3.Print();

	Coin coin4(move(coin2));
	cout << "Coin4:\n";
	coin4.Print();
	cout << "Coin2:\n";
	coin2.Print();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Check for edged weapon\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	EdgedWeapon weap1;
	cout << "Weapon1\n";
	weap1.Print();

	EdgedWeapon weap2(authors[0], 1000, places_of_creation[0], designations_of_edged_weapon[0],
		materials_edged_weapon[0], 1000, 1200, 1350, types_of_edged_weapon[0], 0.15);
	cout << "Weapon2\n";
	weap2.Print();

	EdgedWeapon weap3(weap2);
	cout << "Weapon3\n";
	weap3.Print();

	EdgedWeapon weap4(move(weap2));
	cout << "Weapon4\n";
	weap4.Print();
	cout << "Weapon2\n";
	weap2.Print();

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Check for painting\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	Painting paint1;
	cout << "Paint1\n";
	paint1.Print();

	Painting paint2(authors[0], 1000, places_of_creation[0], designations_of_painting[0],
		genres_of_painting[0], image_on_painting[0], types_of_painting[0], dimensions_of_painting[0]);
	cout << "Paint2\n";
	paint2.Print();

	Painting paint3(paint2);
	cout << "Paint3\n";
	paint3.Print();

	Painting paint4(move(paint2));
	cout << "Paint4\n";
	paint4.Print();
	cout << "Paint2\n";
	paint2.Print();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Check for sculptures\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	Sculpture scupl1;
	cout << "Scupl1\n";
	scupl1.Print();

	Sculpture scupl2(authors[0], 1000, places_of_creation[0], designations_of_painting[0],
		genres_of_painting[0], image_on_painting[0], materials_sculpture[0], dimensions_of_sculpture[0]);
	cout << "Scupl2\n";
	scupl2.Print();

	Sculpture scupl3(scupl2);
	cout << "Scupl3\n";
	scupl3.Print();

	Sculpture scupl4(move(scupl2));
	cout << "Scupl4\n";
	scupl4.Print();
	cout << "Scupl2\n";
	scupl2.Print();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Check for photos\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	Photo photo1;
	cout << "Photo1\n";
	photo1.Print();

	Photo photo2(authors[0], 1000, places_of_creation[0], designations_of_painting[0],
		genres_of_painting[0], image_on_painting[0], formats_photo[0], 0);
	cout << "Photo2\n";
	photo2.Print();

	Photo photo3(photo2);
	cout << "Photo3\n";
	photo3.Print();

	Photo photo4(move(photo2));
	cout << "Photo4\n";
	photo4.Print();
	cout << "Photo2\n";
	photo2.Print();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	
	cout << coin4 << endl;
	cout << photo4 << endl;
	cout << weap4 << endl;
	cout << scupl4 << endl;
	cout << paint4 << endl;
	return 0;
}