#include "Classes.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
ArtObject::ArtObject()
{
	this->author = new char[1] {};
	this->time_of_creation = 0;
	this->place_of_creation = new char[1] {};
	this->designation = new char[1] {};
}
ArtObject::ArtObject(char* author, int time_of_creation, char* place_of_creation, char* designation)
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

	this->time_of_creation = rand() % 800 + 1200;
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

	other.pop_object();
}
ArtObject::~ArtObject()
{
	delete[] this->author;
	delete[] this->designation;
	delete[] this->place_of_creation;
}

void ArtObject::operator=(const ArtObject& other)
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
void ArtObject::operator=(ArtObject&& other)
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

	other.pop_object();
}

void ArtObject::set_author(char author[])
{
	int size_aut = strlen(author) + 1;
	strcpy_s(this->author, size_aut, author);
}
void ArtObject::set_time_of_creation(int time_of_creation)
{
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

	this->author = new char[1] {};
	this->designation = new char[1] {};
	this->place_of_creation = new char[1] {};
	this->time_of_creation = 0;
}

void ArtObject::Print()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Designation:\t\t" << this->designation << endl;
	cout << "Author:\t\t\t" << this->author << endl;
	cout << "Place of creation:\t" << this->place_of_creation << " year" << endl;
	cout << "Time of creation:\t" << this->time_of_creation << endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
AplliedArtObject::AplliedArtObject() : ArtObject()
{
	this->material = new char[1] {};
	this->number_of_copies = 0;
	this->year_of_start_of_use = 0;
	this->year_of_end_of_use = 0;

}
AplliedArtObject::AplliedArtObject(char author[], int time_of_creation, char place_of_creation[],
	char designation[], char material[], int number_of_copies, int year_of_start_of_use, int year_of_end_of_use)
{
	ArtObject(author, time_of_creation, place_of_creation, designation);
	int size_mat = strlen(material) + 1;
	this->material = new char[size_mat] {};
	strcpy_s(this->material, size_mat, material);

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
	ArtObject::pop_object();
	delete[] this->material;
	this->material = new char[1] {};
	this->number_of_copies = 0;
	this->year_of_start_of_use = 0;
	this->year_of_end_of_use = 0;
}
void AplliedArtObject::Print()
{
	ArtObject::Print();
	cout << "Designation:\t\t" << this->material << endl;
	cout << "Number of copies:\t\t\t" << this->number_of_copies << endl;
	cout << "Year of start of use:\t" << this->year_of_start_of_use << " year" << endl;
	cout << "Year of end of use:\t" << this->year_of_end_of_use << " year" << endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
Coin::Coin() : AplliedArtObject()
{
	this->what_is_depicted = new char[1] {};
	this->value = 0;
}
Coin::Coin(char author[], int time_of_creation, char place_of_creation[], char designation[],
	char material[], int number_of_copies, int year_of_start_of_use, int year_of_end_of_use,
	char what_is_depicted[], double value)
{ 
	AplliedArtObject(author, time_of_creation, place_of_creation, designation,
		material, number_of_copies, year_of_start_of_use, year_of_end_of_use);
	int size_dep = strlen(what_is_depicted) + 1;
	this->what_is_depicted = new char[size_dep] {};
	strcpy_s(this->what_is_depicted, size_dep, what_is_depicted);

	this->value = value;
}
Coin::Coin(const Coin& other)
{
	int size_dep = strlen(other.get_what_is_depicted()) + 1;
	this->what_is_depicted = new char[size_dep] {};
	strcpy_s(this->what_is_depicted, size_dep, other.get_what_is_depicted());

	this->value = other.get_value();
}
Coin::Coin(Coin&& other)
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
	AplliedArtObject::pop_object();
	delete[] what_is_depicted;
	this->what_is_depicted = new char[1] {};
	this->value = 0;
}
void Coin::Print()
{
	AplliedArtObject::Print();
	cout << "What is depicted:\t" << this->what_is_depicted << endl;
	cout << "Value:\t" << this->value  << " rub" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
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