#pragma once

#include <iostream>
//#include "Some Constants.h"

using namespace std;

class ArtObject
{
	char* author;
	int time_of_creation;
	char* place_of_creation;
	char* designation;
public:
	void set_author(char*);
	void set_time_of_creation(int);
	void set_place_of_creation(char*);
	void set_designation(char*);

	char* get_author() const;
	int get_time_of_creation() const;
	char* get_place_of_creation() const;
	char* get_designation() const;

	void output_author() const;
	void output_time_of_creation() const;
	void output_place_of_creation() const;
	void output_designation() const;

	ArtObject();
	ArtObject(char*, int, char*, char*);
	ArtObject(const ArtObject&);
	ArtObject(ArtObject&&);
	~ArtObject();
};
/************************************************/
class AplliedArtObject : public ArtObject
{
	char* material;
	int number_of_copies;
	int	year_of_start_of_use;
	int year_of_end_of_use;

public:
	void set_material(char*);
	void set_number_of_copies(int);
	void set_year_of_start_of_use(int);
	void set_year_of_end_of_use(int);

	char* get_material();
	int  get_number_of_copies();
	int get_year_of_start_of_use();
	int get_year_of_end_of_use();

	void output_material();
	void output_number_of_copies();
	void output_year_of_start_of_use();
	void output_year_of_end_of_use();
};

class Coin : public AplliedArtObject
{
	char* what_is_depicted;
	double value;

public:
	void set_what_is_depicted(char*);
	void set_value(double);

	char* get_what_is_depicted();
	double get_value();

	void output_what_is_depicted();
	void output_value();

	Coin();
};

class EdgedWeapon : public AplliedArtObject
{
	char* type;
	double degree_of_sharpening;

public:
	void set_type(char*);
	void set_degree_of_sharpening(double);

	char* get_type();
	double get_degree_of_sharpening();

	void output_type();
	void output_degree_of_sharpening();
};
/************************************************/
class VisualArtObject : public ArtObject
{
	char* genre;
	char* what_is_depicted;
};

class Painting : public VisualArtObject
{
	char* type_of_paint;
	char* dimensions;
};

class Sculpture : public VisualArtObject
{
	char* material;
	char* dimensions;
};

class Photo : public VisualArtObject
{
	char* photo_format;
	bool color_photo;
};
/************************************************/