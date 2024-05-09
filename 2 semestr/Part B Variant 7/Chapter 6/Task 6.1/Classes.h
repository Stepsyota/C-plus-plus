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
	ArtObject();
	ArtObject(char[], int, char[], char[]);
	ArtObject(const ArtObject&);
	ArtObject(ArtObject&&);
	virtual ~ArtObject();

	void operator =(const ArtObject&);
	void operator =(ArtObject&&);
	void set_author(char[]);
	void set_time_of_creation(int);
	void set_place_of_creation(char[]);
	void set_designation(char[]);

	char* get_author() const;
	int get_time_of_creation() const;
	char* get_place_of_creation() const;
	char* get_designation() const;

	virtual void pop_object();
	virtual void Print();
};
/************************************************/
class AplliedArtObject : virtual public ArtObject
{
	char* material;
	int number_of_copies;
	int	year_of_start_of_use;
	int year_of_end_of_use;

public:
	AplliedArtObject();
	AplliedArtObject(char[], int, char[], char[],char[], int, int, int);
	AplliedArtObject(const AplliedArtObject&);
	AplliedArtObject(AplliedArtObject&&);
	virtual ~AplliedArtObject();

	void set_material(char*);
	void set_number_of_copies(int);
	void set_year_of_start_of_use(int);
	void set_year_of_end_of_use(int);

	char* get_material() const;
	int  get_number_of_copies() const;
	int get_year_of_start_of_use() const;
	int get_year_of_end_of_use() const;

	virtual void pop_object() override;
	virtual void Print() override;
};

class Coin : virtual public AplliedArtObject
{
	char* what_is_depicted;
	double value;

public:
	Coin();
	Coin(char[], int, char[], char[],char[], int, int, int,char[], double);
	Coin(const Coin&);
	Coin(Coin&&);
	~Coin();
	void set_what_is_depicted(char*);
	void set_value(double);

	char* get_what_is_depicted() const;
	double get_value() const;

	void pop_object() override;
	void Print() override;
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