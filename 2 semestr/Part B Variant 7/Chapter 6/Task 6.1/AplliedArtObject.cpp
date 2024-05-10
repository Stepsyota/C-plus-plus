#include <iostream>
#include "AplliedArtObject.h"
#include "ArtObject.h"

using namespace std;

AplliedArtObject::AplliedArtObject() : ArtObject()
{
	this->material = new char[2] {"-"};
	this->number_of_copies = 0;
	this->year_of_start_of_use = 0;
	this->year_of_end_of_use = 0;

}
AplliedArtObject::AplliedArtObject(char material[], int number_of_copies,
	int year_of_start_of_use, int year_of_end_of_use)
{
	int size_mat = strlen(material) + 1;
	this->material = new char[size_mat] {};
	strcpy_s(this->material, size_mat, material);

	if (number_of_copies < 0)
	{
		cout << "Error number of copies\n";
		exit(2);
	}
	if (year_of_start_of_use < get_time_of_creation() || year_of_start_of_use > 2024)
	{
		cout << "Error year of start of use\n";
		exit(3);
	}
	if (year_of_end_of_use <  year_of_start_of_use || year_of_end_of_use > 2024)
	{
		cout << "Error year of end of use\n";
		exit(3);
	}
	this->number_of_copies = number_of_copies;
	this->year_of_start_of_use = year_of_start_of_use;
	this->year_of_end_of_use = year_of_end_of_use;
}
AplliedArtObject::AplliedArtObject(const AplliedArtObject& other)
{
	int size_mat = strlen(other.get_material()) + 1;
	this->material = new char[size_mat] {};
	strcpy_s(this->material, size_mat, other.get_material());

	this->number_of_copies = other.get_number_of_copies();
	this->year_of_start_of_use = other.get_year_of_start_of_use();
	this->year_of_end_of_use = other.get_year_of_end_of_use();
}
AplliedArtObject::AplliedArtObject(AplliedArtObject&& other)
{
	int size_mat = strlen(other.get_material()) + 1;
	this->material = new char[size_mat] {};
	strcpy_s(this->material, size_mat, other.get_material());

	this->number_of_copies = other.get_number_of_copies();
	this->year_of_start_of_use = other.get_year_of_start_of_use();
	this->year_of_end_of_use = other.get_year_of_end_of_use();
}
AplliedArtObject:: ~AplliedArtObject()
{
	delete[] this->material;
}

void AplliedArtObject::set_material(char* material)
{
	int size_mat = strlen(material) + 1;
	this->material = new char[size_mat] {};
	strcpy_s(this->material, size_mat, material);
}
void AplliedArtObject::set_number_of_copies(int number_of_copies)
{
	if (number_of_copies < 0)
	{
		cout << "Error number of copies\n";
		exit(2);
	}
	this->number_of_copies = number_of_copies;
}
void AplliedArtObject::set_year_of_start_of_use(int year_of_start_of_use)
{
	if (year_of_start_of_use < 0 || year_of_start_of_use > get_time_of_creation())
	{
		cout << "Error year of start of use\n";
		exit(3);
	}
	this->year_of_start_of_use = year_of_start_of_use;
}
void AplliedArtObject::set_year_of_end_of_use(int year_of_end_of_use)
{
	if (year_of_end_of_use < 0 || year_of_end_of_use > year_of_start_of_use)
	{
		cout << "Error year of end of use\n";
		exit(3);
	}
	this->year_of_end_of_use = year_of_end_of_use;
}

char* AplliedArtObject::get_material() const
{
	return this->material;
}
int AplliedArtObject::get_number_of_copies() const
{
	return this->number_of_copies;
}
int AplliedArtObject::get_year_of_start_of_use() const
{
	return this->year_of_start_of_use;
}
int AplliedArtObject::get_year_of_end_of_use() const
{
	return this->year_of_end_of_use;
}

void AplliedArtObject::pop_object()
{
	delete[] this->material;
	this->material = new char[2] {"-"};
	this->number_of_copies = 0;
	this->year_of_start_of_use = 0;
	this->year_of_end_of_use = 0;
}
void AplliedArtObject::Print() const
{
	ArtObject::Print();
	cout << "Material:\t\t" << this->material << endl;
	cout << "Number of copies:\t" << this->number_of_copies << endl;
	cout << "Year of start of use:\t" << this->year_of_start_of_use << " year" << endl;
	cout << "Year of end of use:\t" << this->year_of_end_of_use << " year" << endl;
}