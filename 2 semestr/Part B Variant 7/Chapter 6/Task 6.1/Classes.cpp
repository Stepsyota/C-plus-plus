#include "Classes.h"

void ArtObject::set_author(char* author)
{
	this->author = author;
}
void ArtObject::set_time_of_creation(int time_of_creation)
{
	this->time_of_creation = time_of_creation;
}
void ArtObject::set_place_of_creation(char* place_of_creation)
{
	this->place_of_creation = place_of_creation;
}
void ArtObject::set_designation(char* designation)
{
	this->designation = designation;
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

void ArtObject::output_author() const
{
	cout << "Author:\t" << this->author << endl;
}
void ArtObject::output_time_of_creation() const
{
	cout << "Time of creation:\t" << this->time_of_creation << endl;
}
void ArtObject::output_place_of_creation() const
{
	cout << "Place of creation:\t" << this->place_of_creation << endl;
}
void ArtObject::output_designation() const
{
	cout << "Designation:\t" << this->designation << endl;
}

ArtObject::ArtObject()
{
	this->author = new char[1] {};
	this->time_of_creation = 0;
	this->place_of_creation = new char[1] {};
	this->designation = new char[1] {};
}
ArtObject::ArtObject(char* author, int time_of_creation, char* place_of_creation, char* designation)
{
	this->author = new char[sizeof author] {};
	this->place_of_creation = new char[sizeof place_of_creation] {};
	this->designation = new char[sizeof designation] {};
	strcpy_s(this->author, sizeof this->author, author);
	this->time_of_creation = time_of_creation;
	strcpy_s(this->place_of_creation, sizeof this->place_of_creation, place_of_creation);
	strcpy_s(this->designation, sizeof this->place_of_creation, designation);
}
ArtObject::ArtObject(const ArtObject& other)
{
	this->author = other.get_author();
	this->time_of_creation = other.get_time_of_creation();
	this->place_of_creation = other.get_place_of_creation();
	this->designation = other.get_designation();
}
ArtObject::ArtObject(ArtObject&& other)
{
	this->author = other.get_author();
	this->time_of_creation = other.get_time_of_creation();
	this->place_of_creation = other.get_place_of_creation();
	this->designation = other.get_designation();
}
ArtObject::~ArtObject()
{
	delete[] author;
	delete[] place_of_creation;
	delete[] designation;
}

void AplliedArtObject::set_material(char* material)
{
	this->material = material;
}
void AplliedArtObject::set_number_of_copies(int number_of_copies)
{
	this->number_of_copies = number_of_copies;
}
void AplliedArtObject::set_year_of_start_of_use(int year_of_start_of_use)
{
	this->year_of_start_of_use = year_of_start_of_use;
}
void AplliedArtObject::set_year_of_end_of_use(int year_of_end_of_use)
{
	this->year_of_end_of_use = year_of_end_of_use;
}

char* AplliedArtObject::get_material()
{
	return this->material;
}
int AplliedArtObject::get_number_of_copies()
{
	return this->number_of_copies;
}
int AplliedArtObject::get_year_of_start_of_use()
{
	return this->year_of_start_of_use;
}
int AplliedArtObject::get_year_of_end_of_use()
{
	return this->year_of_end_of_use;
}

void AplliedArtObject::output_material()
{
	cout << "Material:\t" << this->material << endl;
}
void AplliedArtObject::output_number_of_copies()
{
	cout << "Number of copies:\t" << this->number_of_copies << endl;
}
void AplliedArtObject::output_year_of_start_of_use()
{
	cout << "The year of start of use:\t" << this->year_of_start_of_use << endl;
}
void AplliedArtObject::output_year_of_end_of_use()
{
	cout << "The year of end of use:\t" << this->year_of_end_of_use << endl;
}


void Coin::set_what_is_depicted(char* what_is_depicted)
{
	this->what_is_depicted = what_is_depicted;
}
void Coin::set_value(double value)
{
	this->value = value;
}

char* Coin::get_what_is_depicted()
{
	return this->what_is_depicted;
}
double Coin::get_value()
{
	return this->value;
}

void Coin::output_what_is_depicted()
{
	cout << "What is depicted:\t" << this->what_is_depicted << endl;
}
void Coin::output_value()
{
	cout << "Value:\t" << this->value << endl;
}


void EdgedWeapon::set_type(char* type)
{
	this->type = type;
}
void EdgedWeapon::set_degree_of_sharpening(double degree_of_sharpening)
{
	this->degree_of_sharpening = degree_of_sharpening;
}

char* EdgedWeapon::get_type()
{
	return this->type;
}
double EdgedWeapon::get_degree_of_sharpening()
{
	return this->degree_of_sharpening;
}

void EdgedWeapon::output_type()
{
	cout << "Type:\t" << this->type << endl;
}
void EdgedWeapon::output_degree_of_sharpening()
{
	cout << "Degree of sharpening:\t" << this->degree_of_sharpening << endl;
}