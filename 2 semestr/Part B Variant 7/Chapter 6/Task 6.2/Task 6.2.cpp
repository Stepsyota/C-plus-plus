#include "Task 6.2.h"

using namespace std;

int main()
{
    ObjectArray ObjArr1;
    ObjArr1.output_array();

    Coin obj1;
    ObjArr1.push_after(obj1, 0);
    ObjArr1.output_array();

    Photo obj2;
    ObjArr1.push_after(obj2, 0);
    ObjArr1.output_array();
    //ObjArr1.pop_back();
    //ObjArr1.output_array();

    //ObjectArray ObjArr2(ObjArr1);
    //ObjArr2.output_array();

    //ArtObject* obj3 = new Sculpture();
    //ObjArr2.push_back(obj3);
    //ObjArr2.output_array();
    return 0;
}