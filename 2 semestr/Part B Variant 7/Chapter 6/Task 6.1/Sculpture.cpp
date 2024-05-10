#include <iostream>
#include "Sculpture.h"
#include "VisualArtObject.h"
#include "ArtObject.h"

using namespace std;

Sculpture::Sculpture()
{
	this->material = new char[2] {"-"};
	this->dimensions = new char[2] {"-"};
}
Sculpture::Sculpture(char author[], int time_of_creation, char place_of_creation[], char designation[],
	char genre[], char what_is_depicted[], char material[], char dimensions[]) : ArtObject(author,
		time_of_creation, place_of_creation, designation), VisualArtObject(genre, what_is_depicted)
{
	int size_mat = strlen(material) + 1;
	this->material = new char[size_mat] {};
	strcpy_s(this->material, size_mat, material);

	int size_dim = strlen(dimensions) + 1;
	this->dimensions = new char[size_dim] {};
	strcpy_s(this->dimensions, size_dim, dimensions);

}
Sculpture::Sculpture(const Sculpture& other) : ArtObject(other), VisualArtObject(other)
{
	int size_mat = strlen(other.get_material()) + 1;
	this->material = new char[size_mat] {};
	strcpy_s(this->material, size_mat, other.get_material());

	int size_dim = strlen(other.get_dimensions()) + 1;
	this->dimensions = new char[size_dim] {};
	strcpy_s(this->dimensions, size_dim, other.get_dimensions());
}
Sculpture::Sculpture(Sculpture&& other) : ArtObject(move(other)), VisualArtObject(move(other))
{
	int size_mat = strlen(other.get_material()) + 1;
	this->material = new char[size_mat] {};
	strcpy_s(this->material, size_mat, other.get_material());

	int size_dim = strlen(other.get_dimensions()) + 1;
	this->dimensions = new char[size_dim] {};
	strcpy_s(this->dimensions, size_dim, other.get_dimensions());

	other.pop_object();
}
Sculpture::~Sculpture()
{
	delete[] this->material;
	delete[] this->dimensions;
}

void Sculpture::set_material(char* material)
{
	int size_mat = strlen(material) + 1;
	this->material = new char[size_mat] {};
	strcpy_s(this->material, size_mat, material);
}
void Sculpture::set_dimensions(char* dimensions)
{
	int size_dim = strlen(dimensions) + 1;
	this->dimensions = new char[size_dim] {};
	strcpy_s(this->dimensions, size_dim, dimensions);
}

char* Sculpture::get_material() const
{
	return this->material;
}
char* Sculpture::get_dimensions() const
{
	return this->dimensions;
}

void Sculpture::pop_object()
{
	ArtObject::pop_object();
	VisualArtObject::pop_object();
	delete[] this->material;
	delete[] this->dimensions;
	this->material = new char[2] {"-"};
	this->dimensions = new char[2] {"-"};
}
void Sculpture::Print()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Category: Sculpture\n";
	VisualArtObject::Print();
	cout << "Material:\t\t" << this->material << endl;
	cout << "Dimensions:\t\t" << this->dimensions << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}