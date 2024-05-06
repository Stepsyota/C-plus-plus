// 
#include "Task 6.1.h"
#include "Classes.h"

int main()
{
	ArtObject A;
	A.output_author();
	A.output_time_of_creation();
	A.output_place_of_creation();
	A.output_designation();

	ArtObject B(authors[0], 100, places_of_creation[0], designations_of_coin[0]);
	B.output_author();
	B.output_time_of_creation();
	B.output_place_of_creation();
	B.output_designation();
}
