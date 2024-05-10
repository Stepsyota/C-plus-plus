#include <iostream>
#include "Coin.h"
#include "AplliedArtObject.h"
#include "ArtObject.h"

using namespace std;

Coin::Coin() : AplliedArtObject()
{
	this->what_is_depicted = new char[2] {"-"};
	this->value = 0;
}
Coin::Coin(char author[], int time_of_creation, char place_of_creation[], char designation[],
	char material[], int number_of_copies, int year_of_start_of_use, int year_of_end_of_use,
	char what_is_depicted[], double value) : AplliedArtObject(material, number_of_copies, year_of_start_of_use,
		year_of_end_of_use), ArtObject(author, time_of_creation, place_of_creation, designation)
{
	int size_dep = strlen(what_is_depicted) + 1;
	this->what_is_depicted = new char[size_dep] {};
	strcpy_s(this->what_is_depicted, size_dep, what_is_depicted);

	if (value < 0)
	{
		cout << "Error value\n";
		exit(4);
	}
	this->value = value;
}
Coin::Coin(const Coin& other) : ArtObject(other), AplliedArtObject(other)
{
	int size_dep = strlen(other.get_what_is_depicted()) + 1;
	this->what_is_depicted = new char[size_dep] {};
	strcpy_s(this->what_is_depicted, size_dep, other.get_what_is_depicted());

	this->value = other.get_value();
}
Coin::Coin(Coin&& other) : ArtObject(move(other)), AplliedArtObject(move(other))
{
	int size_dep = strlen(other.get_what_is_depicted()) + 1;
	this->what_is_depicted = new char[size_dep] {};
	strcpy_s(this->what_is_depicted, size_dep, other.get_what_is_depicted());

	this->value = other.get_value();

	other.pop_object();
}
Coin::~Coin()
{
	delete[] this->what_is_depicted;
}

void Coin::set_what_is_depicted(char* what_is_depicted)
{
	int size_dep = strlen(what_is_depicted) + 1;
	this->what_is_depicted = new char[size_dep] {};
	strcpy_s(this->what_is_depicted, size_dep, what_is_depicted);
}
void Coin::set_value(double value)
{
	if (value < 0)
	{
		cout << "Error value\n";
		exit(4);
	}
	this->value = value;
}

char* Coin::get_what_is_depicted() const
{
	return this->what_is_depicted;
}
double Coin::get_value() const
{
	return this->value;
}

void Coin::pop_object()
{
	ArtObject::pop_object();
	AplliedArtObject::pop_object();
	delete[] this->what_is_depicted;
	this->what_is_depicted = new char[2] {"-"};
	this->value = 0;
}
void Coin::Print() const

{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Category: Coin\n";
	AplliedArtObject::Print();
	cout << "What is depicted:\t" << this->what_is_depicted << endl;
	cout << "Value:\t\t\t" << this->value << " rub" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}