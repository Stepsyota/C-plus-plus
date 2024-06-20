#include "String.h"
#include <fstream>

String::String()
{
	string = new char[1] {};
	length = 0;
}
String::String(char* str)
{
	string = new char[strlen(str) + 1] {};
	strcpy_s(string, sizeof string + 1, str);
	length = strlen(str) + 1;
}

void String::load_to_file(const char* file_name)
{
	ofstream file;
	file.open(file_name);
	if (!file)
	{
		cout << "Error\n";
		exit(-1);
	}
	file << string << endl;
	file.close();
}

void String::input_from_file(const char* file_name)
{
	ifstream file;
	file.open(file_name);
	if (!file)
	{
		cout << "Error\n";
		exit(-2);
	}
	char* str{};
	file >> str;
	string = new char[strlen(str) + 1] {};
	strcpy_s(string, sizeof string + 1, str);
	length = strlen(str) + 1;
	file.close();
}

String::String(const String&)
{

}
String::String(String&&)
{

}
String::~String()
{
	delete[] string;
	length = 0;
}
void String::print() const
{
	cout << string << endl;
}

int String::get_length() const
{
	return length;
}
void String::input_string()
{

}

void String::operator==(const String&) const
{

}
void String::operator!=(const String&) const
{

}

//vector<String> String::separate_words()
//{
//	
//}