#include <iostream>
#include "Painting.h"
#include "VisualArtObject.h"
#include "ArtObject.h"

using namespace std;

Painting::Painting()
{
	this->type_of_paint = new char[2] {"-"};
	this->dimensions = new char[2] {"-"};
}
Painting::Painting(char author[], int time_of_creation, char place_of_creation[], char designation[],
	char genre[], char what_is_depicted[], char type_of_paint[], char dimensions[]) : ArtObject(author,
		time_of_creation, place_of_creation, designation), VisualArtObject(genre, what_is_depicted)
{
	int size_type = strlen(type_of_paint) + 1;
	this->type_of_paint = new char[size_type] {};
	strcpy_s(this->type_of_paint, size_type, type_of_paint);

	int size_dim = strlen(dimensions) + 1;
	this->dimensions = new char[size_dim] {};
	strcpy_s(this->dimensions, size_dim, dimensions);

}
Painting::Painting(const Painting& other) : ArtObject(other), VisualArtObject(other)
{
	int size_type = strlen(other.get_type_of_paint()) + 1;
	this->type_of_paint = new char[size_type] {};
	strcpy_s(this->type_of_paint, size_type, other.get_type_of_paint());

	int size_dim = strlen(other.get_dimensions()) + 1;
	this->dimensions = new char[size_dim] {};
	strcpy_s(this->dimensions, size_dim, other.get_dimensions());
}
Painting::Painting(Painting&& other) : ArtObject(move(other)), VisualArtObject(move(other))
{
	int size_type = strlen(other.get_type_of_paint()) + 1;
	this->type_of_paint = new char[size_type] {};
	strcpy_s(this->type_of_paint, size_type, other.get_type_of_paint());

	int size_dim = strlen(other.get_dimensions()) + 1;
	this->dimensions = new char[size_dim] {};
	strcpy_s(this->dimensions, size_dim, other.get_dimensions());

	other.pop_object();
}
Painting::~Painting()
{
	delete[] this->type_of_paint;
	delete[] this->dimensions;
}

void Painting::set_type_of_paint(char* type_of_paint)
{
	int size_type = strlen(type_of_paint) + 1;
	this->type_of_paint = new char[size_type] {};
	strcpy_s(this->type_of_paint, size_type, type_of_paint);
}
void Painting::set_dimensions(char* dimensions)
{
	int size_dim = strlen(dimensions) + 1;
	this->dimensions = new char[size_dim] {};
	strcpy_s(this->dimensions, size_dim, dimensions);
}

char* Painting::get_type_of_paint() const
{
	return this->type_of_paint;
}
char* Painting::get_dimensions() const
{
	return this->dimensions;
}

void Painting::pop_object()
{
	ArtObject::pop_object();
	VisualArtObject::pop_object();
	delete[] this->type_of_paint;
	delete[] this->dimensions;
	this->type_of_paint = new char[2] {"-"};
	this->dimensions = new char[2] {"-"};
}
void Painting::print() const
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Category: Painting\n";
	VisualArtObject::print();
	cout << "Type of paint:\t\t" << this->type_of_paint << endl;
	cout << "Dimensions:\t\t" << this->dimensions << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

ArtObject* Painting::clone() const
{
	return new Painting(*this);
}