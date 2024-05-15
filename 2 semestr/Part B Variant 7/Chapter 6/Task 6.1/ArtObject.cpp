#include <iostream>
#include "ArtObject.h"

using namespace std;

ArtObject::ArtObject()
{
	this->author = new char[2] {"-"};
	this->time_of_creation = 0;
	this->place_of_creation = new char[2] {"-"};
	this->designation = new char[2] {"-"};
}
ArtObject::ArtObject(char author[], int time_of_creation, char place_of_creation[], char designation[])
{
	int size_aut = strlen(author) + 1;
	int size_pla = strlen(place_of_creation) + 1;
	int size_des = strlen(designation) + 1;

	this->author = new char[size_aut] {};
	this->place_of_creation = new char[size_pla] {};
	this->designation = new char[size_des] {};

	strcpy_s(this->author, size_aut, author);
	strcpy_s(this->place_of_creation, size_pla, place_of_creation);
	strcpy_s(this->designation, size_des, designation);
	if (time_of_creation < 0 || time_of_creation > 2024)
	{
		cout << "Error time of creation\n";
		exit(1);
	}
	this->time_of_creation = time_of_creation;
}
ArtObject::ArtObject(const ArtObject& other)
{
	int size_aut = strlen(other.get_author()) + 1;
	int size_pla = strlen(other.get_place_of_creation()) + 1;
	int size_des = strlen(other.get_designation()) + 1;

	this->author = new char[size_aut] {};
	this->place_of_creation = new char[size_pla] {};
	this->designation = new char[size_des] {};

	strcpy_s(this->author, size_aut, other.get_author());
	strcpy_s(this->place_of_creation, size_pla, other.get_place_of_creation());
	strcpy_s(this->designation, size_des, other.get_designation());

	this->time_of_creation = other.get_time_of_creation();
}
ArtObject::ArtObject(ArtObject&& other)
{
	int size_aut = strlen(other.get_author()) + 1;
	int size_pla = strlen(other.get_place_of_creation()) + 1;
	int size_des = strlen(other.get_designation()) + 1;

	this->author = new char[size_aut] {};
	this->place_of_creation = new char[size_pla] {};
	this->designation = new char[size_des] {};

	strcpy_s(this->author, size_aut, other.get_author());
	strcpy_s(this->place_of_creation, size_pla, other.get_place_of_creation());
	strcpy_s(this->designation, size_des, other.get_designation());

	this->time_of_creation = other.get_time_of_creation();
}
ArtObject::~ArtObject()
{
	delete[] this->author;
	delete[] this->designation;
	delete[] this->place_of_creation;
}

void ArtObject::set_author(char author[])
{
	int size_aut = strlen(author) + 1;
	strcpy_s(this->author, size_aut, author);
}
void ArtObject::set_time_of_creation(int time_of_creation)
{
	if (time_of_creation < 0 || time_of_creation > 2024)
	{
		cout << "Error time of creation\n";
		exit(1);
	}
	this->time_of_creation = time_of_creation;
}
void ArtObject::set_place_of_creation(char place_of_creation[])
{
	int size_pla = strlen(place_of_creation) + 1;
	strcpy_s(this->place_of_creation, size_pla, place_of_creation);
}
void ArtObject::set_designation(char designation[])
{
	int size_des = strlen(designation) + 1;
	strcpy_s(this->designation, size_des, designation);
}


char* ArtObject::get_author() const
{
	return this->author;
}
int ArtObject::get_time_of_creation() const
{
	return this->time_of_creation;
}
char* ArtObject::get_place_of_creation() const
{
	return this->place_of_creation;
}
char* ArtObject::get_designation() const
{
	return this->designation;
}

void ArtObject::pop_object()
{
	delete[] this->author;
	delete[] this->designation;
	delete[] this->place_of_creation;

	this->author = new char[2] {"-"};
	this->designation = new char[2] {"-"};
	this->place_of_creation = new char[2] {"-"};
	this->time_of_creation = 0;
}
void ArtObject::print() const
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Designation:\t\t" << this->designation << endl;
	cout << "Author:\t\t\t" << this->author << endl;
	cout << "Place of creation:\t" << this->place_of_creation << endl;
	cout << "Time of creation:\t" << this->time_of_creation << " year" << endl;
}