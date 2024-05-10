#include <iostream>
#include "VisualArtObject.h"
#include "ArtObject.h"

using namespace std;

VisualArtObject::VisualArtObject()
{
	this->genre = new char[2] {"-"};
	this->what_is_depicted = new char[2] {"-"};
}
VisualArtObject::VisualArtObject(char genre[], char what_is_depicted[])
{
	int size_gen = strlen(genre) + 1;
	this->genre = new char[size_gen] {};
	strcpy_s(this->genre, size_gen, genre);

	int size_dep = strlen(what_is_depicted) + 1;
	this->what_is_depicted = new char[size_dep] {};
	strcpy_s(this->what_is_depicted, size_dep, what_is_depicted);
}
VisualArtObject::VisualArtObject(const VisualArtObject& other)
{
	int size_gen = strlen(other.get_genre()) + 1;
	this->genre = new char[size_gen] {};
	strcpy_s(this->genre, size_gen, other.get_genre());

	int size_dep = strlen(other.get_what_is_depicted()) + 1;
	this->what_is_depicted = new char[size_dep] {};
	strcpy_s(this->what_is_depicted, size_dep, other.get_what_is_depicted());
}
VisualArtObject::VisualArtObject(VisualArtObject&& other)
{
	int size_gen = strlen(other.get_genre()) + 1;
	this->genre = new char[size_gen] {};
	strcpy_s(this->genre, size_gen, other.get_genre());

	int size_dep = strlen(other.get_what_is_depicted()) + 1;
	this->what_is_depicted = new char[size_dep] {};
	strcpy_s(this->what_is_depicted, size_dep, other.get_what_is_depicted());
}
VisualArtObject::~VisualArtObject()
{
	delete[] this->genre;
	delete[] this->what_is_depicted;
}

void VisualArtObject::set_genre(char* genre)
{
	int size_gen = strlen(genre) + 1;
	strcpy_s(this->genre, size_gen, genre);
}
void VisualArtObject::set_what_is_depicted(char* what_is_depicted)
{
	int size_dep = strlen(what_is_depicted) + 1;
	strcpy_s(this->what_is_depicted, size_dep, what_is_depicted);
}

char* VisualArtObject::get_genre() const
{
	return this->genre;
}
char* VisualArtObject::get_what_is_depicted() const
{
	return this->what_is_depicted;
}

void VisualArtObject::pop_object()
{
	delete[] this->genre;
	this->genre = new char[2] {"-"};
	delete[] this->what_is_depicted;
	this->what_is_depicted = new char[2] {"-"};
}
void VisualArtObject::Print() const
{
	ArtObject::Print();
	cout << "Genre:\t\t\t" << this->genre << endl;
	cout << "What is depicted:\t" << this->what_is_depicted << endl;
}