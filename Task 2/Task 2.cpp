#include <iostream>
#include "String.h"

using namespace std;

int main()
{
	const char* file = "file1.txt";
	char* a = new char[9]{ "operator" };
	String a1;
	a1.input_from_file(file);
	a1.print();
	//a1.load_to_file(file);
	delete[] a;
	return 0;
}