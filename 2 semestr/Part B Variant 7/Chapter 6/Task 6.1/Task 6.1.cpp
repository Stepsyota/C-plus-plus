#include "Task 6.1.h"
#include "Classes.h"

int main()
{
	Coin coin1;
	coin1.Print();
	

	Coin coin2(authors[0], 1000, places_of_creation[0], designations_of_coin[0],
		materials_coin[0], 1000, 1200, 1350, images_on_coin[0], values_coin[0]);
	coin2.Print();
	return 0;
}
