#include "Task 6.4.h"

int main()
{
    ObjectForwardList ObjArr1;
    cout << "List 1:\n";
    ObjArr1.output_list();

    Coin obj1;
    obj1.set_time_of_creation(1563);
    ObjArr1.push_after(&obj1, 0);
    cout << "List 1:\n";
    ObjArr1.output_list();

    Photo obj2;
    obj2.set_time_of_creation(1993);
    ObjArr1.push_front(&obj2);
    cout << "List 1:\n";
    ObjArr1.output_list();
    ObjArr1.pop_front();
    obj2.print();
    cout << "List 1:\n";
    ObjArr1.output_list();

    ObjectForwardList ObjArr2(ObjArr1);
    cout << "List 2:\n";
    ObjArr2.output_list();

    Sculpture obj3;
    obj3.set_time_of_creation(1789);
    ObjArr2.push_back(&obj3);
    cout << "List 2:\n";
    ObjArr2.output_list();

    int time_create = rand() % 1200 + 800;
    int year_end = time_create + rand() % (2024 - time_create);
    int year_start = time_create + rand() % (year_end - time_create);
    Coin obj4(authors[rand() % 15], time_create, places_of_creation[rand() % 6], designations_of_coin[rand() % 5],
        materials_coin[rand() % 5], rand() % 1000 * 1000, year_start, year_end, images_on_coin[rand() % 5],
        values_coin[rand() % 5]);
    ObjArr2.push_front(&obj4);
    cout << "List 2:\n";
    ObjArr2.output_list();

    cout << "List 2:\n";
    ObjArr2.output_list();

    ObjectForwardList ObjArr3(move(ObjArr2));
    cout << "List 3:\n";
    ObjArr3.output_list();
    cout << "List 2:\n";
    ObjArr2.output_list();

    ObjectForwardList ObjArr4 = ObjArr3;
    cout << "List 4:\n";
    ObjArr4.output_list();

    ObjectForwardList ObjArr5 = move(ObjArr4);
    cout << "List 5:\n";
    ObjArr5.output_list();
    cout << "List 4:\n";
    ObjArr4.output_list();

    ObjectForwardList ObjArr6;
    ObjArr6.copy_list(ObjArr5);
    cout << "List 6:\n";
    ObjArr6.output_list();

    ObjArr6.pop_front();
    cout << "List 6:\n";
    ObjArr6.output_list();
    cout << "List 5:\n";
    ObjArr5.output_list();

    ObjArr6.pop_forward_list();
    cout << "List 6:\n";
    ObjArr6.output_list();
    cout << "List 5:\n";
    ObjArr5.output_list();

    ObjArr5.pop_forward_list();
    cout << "List 5:\n";
    ObjArr5.output_list();

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Object:\n";
    obj1.print();
    obj2.print();
    obj3.print();
    obj4.print();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    return 0;
}