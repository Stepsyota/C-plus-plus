#include <iostream>
#include "Photo.h"
#include "VisualArtObject.h"
#include "ArtObject.h"

using namespace std;

Photo::Photo()
{
	this->photo_format = new char[2] {"-"};
	this->color_photo = 0;
}
Photo::Photo(char author[], int time_of_creation, char place_of_creation[], char designation[],
	char genre[], char what_is_depicted[], char photo_format[], bool color_photo) : ArtObject(author,
		time_of_creation, place_of_creation, designation), VisualArtObject(genre, what_is_depicted)
{
	int size_form = strlen(photo_format) + 1;
	this->photo_format = new char[size_form] {};
	strcpy_s(this->photo_format, size_form, photo_format);

	this->color_photo = color_photo;

}
Photo::Photo(const Photo& other) : ArtObject(other), VisualArtObject(other)
{
	int size_form = strlen(other.get_photo_format()) + 1;
	this->photo_format = new char[size_form] {};
	strcpy_s(this->photo_format, size_form, other.get_photo_format());

	this->color_photo = other.get_color_photo();
}
Photo::Photo(Photo&& other) : ArtObject(move(other)), VisualArtObject(move(other))
{
	int size_form = strlen(other.get_photo_format()) + 1;
	this->photo_format = new char[size_form] {};
	strcpy_s(this->photo_format, size_form, other.get_photo_format());

	this->color_photo = other.get_color_photo();

	other.pop_object();
}
Photo::~Photo()
{
	delete[] this->photo_format;
}

void Photo::set_photo_format(char* photo_format)
{
	int size_form = strlen(photo_format) + 1;
	this->photo_format = new char[size_form] {};
	strcpy_s(this->photo_format, size_form, photo_format);
}
void Photo::set_color_photo(bool color_photo)
{
	this->color_photo = color_photo;
}

char* Photo::get_photo_format() const
{
	return this->photo_format;
}
bool Photo::get_color_photo() const
{
	return this->color_photo;
}

void Photo::pop_object()
{
	ArtObject::pop_object();
	VisualArtObject::pop_object();
	delete[] this->photo_format;
	this->photo_format = new char[2] {"-"};
	this->color_photo = 0;
}
void Photo::Print()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Category: Photo\n";
	VisualArtObject::Print();
	cout << "Photo format:\t\t" << this->photo_format << endl;
	cout << "Color photo:\t\t"; if (this->color_photo) { cout << "True\n"; }
	else { cout << "False\n"; };
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}