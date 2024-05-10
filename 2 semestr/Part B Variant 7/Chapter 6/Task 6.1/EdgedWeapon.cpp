#include <iostream>
#include "EdgedWeapon.h"
#include "AplliedArtObject.h"
#include "ArtObject.h"

using namespace std;

EdgedWeapon::EdgedWeapon()
{
	this->type = new char[2] {"-"};
	this->degree_of_sharpening = 0;
}
EdgedWeapon::EdgedWeapon(char author[], int time_of_creation, char place_of_creation[],
	char designation[], char material[], int number_of_copies, int year_of_start_of_use,
	int year_of_end_of_use, char type[], double  degree_of_sharpening) : ArtObject(author,
		time_of_creation, place_of_creation, designation), AplliedArtObject(material,
			number_of_copies, year_of_start_of_use, year_of_end_of_use)
{
	int size_type = strlen(type) + 1;
	this->type = new char[size_type] {};
	strcpy_s(this->type, size_type, type);

	if (degree_of_sharpening < 0 || degree_of_sharpening > 90)
	{
		cout << "Error degree of sharpening\n";
		exit(5);
	}
	this->degree_of_sharpening = degree_of_sharpening;
}
EdgedWeapon::EdgedWeapon(const EdgedWeapon& other) : ArtObject(other), AplliedArtObject(other)
{
	int size_type = strlen(other.get_type()) + 1;
	this->type = new char[size_type] {};
	strcpy_s(this->type, size_type, other.get_type());

	this->degree_of_sharpening = other.get_degree_of_sharpening();
}
EdgedWeapon::EdgedWeapon(EdgedWeapon&& other) : ArtObject(move(other)), AplliedArtObject(move(other))
{
	int size_type = strlen(other.get_type()) + 1;
	this->type = new char[size_type] {};
	strcpy_s(this->type, size_type, other.get_type());

	this->degree_of_sharpening = other.get_degree_of_sharpening();

	other.pop_object();
}
EdgedWeapon::~EdgedWeapon()
{
	delete[] this->type;
}

void EdgedWeapon::set_type(char type[])
{
	int size_type = strlen(type) + 1;
	this->type = new char[size_type] {};
	strcpy_s(this->type, size_type, type);
}
void EdgedWeapon::set_degree_of_sharpening(double degree_of_sharpening)
{
	this->degree_of_sharpening = degree_of_sharpening;
}

char* EdgedWeapon::get_type() const
{
	return this->type;
}
double EdgedWeapon::get_degree_of_sharpening() const
{
	return this->degree_of_sharpening;
}

void EdgedWeapon::pop_object()
{
	ArtObject::pop_object();
	AplliedArtObject::pop_object();
	delete[] this->type;
	this->type = new char[2] {"-"};
	this->degree_of_sharpening = 0;
}
void EdgedWeapon::Print() const
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Category: EdgedWeapon\n";
	AplliedArtObject::Print();
	cout << "Type of edged weapon:\t" << this->type << endl;
	cout << "Degree of sharpening:\t" << this->degree_of_sharpening << " degrees" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}