#include "Task 6.2.h"

using namespace std;

int main()
{
    ObjectArray ObjArr1;
    cout << "Array 1:\n";
    ObjArr1.output_array();

    Coin obj1;
    ObjArr1.push_after(obj1, 0);
    cout << "Array 1:\n";
    ObjArr1.output_array();

    Photo obj2;
    ObjArr1.push_back(obj2);
    cout << "Array 1:\n";
    ObjArr1.output_array();
    ObjArr1.pop_back();
    cout << "Array 1:\n";
    ObjArr1.output_array();

    ObjectArray ObjArr2(ObjArr1);
    cout << "Array 2:\n";
    ObjArr2.output_array();

    Sculpture obj3;
    ObjArr2.push_back(obj3);
    cout << "Array 2:\n";
    ObjArr2.output_array();

     int time_create = rand() % 1200 + 800;
     int year_end = time_create + rand() % (2024 - time_create);
     int year_start = time_create + rand() % (year_end - time_create);
     Coin obj4(authors[rand() % 15], time_create, places_of_creation[rand() % 6], designations_of_coin[rand() % 5],
         materials_coin[rand() % 5], rand() % 1000 * 1000, year_start, year_end, images_on_coin[rand() % 5],
         values_coin[rand() % 5]);
     ObjArr2.push_back(obj4);
     cout << "Array 2:\n";
     ObjArr2.output_array();

     ObjectArray ObjArr3(move(ObjArr2));
     cout << "Array 3:\n";
     ObjArr3.output_array();
     cout << "Array 2:\n";
     ObjArr2.output_array();

     ObjectArray ObjArr4 = ObjArr3;
     cout << "Array 4:\n";
     ObjArr4.output_array();

     ObjectArray ObjArr5 = move(ObjArr4);
     cout << "Array 5:\n";
     ObjArr5.output_array();
     cout << "Array 4:\n";
     ObjArr4.output_array();

    return 0;
}