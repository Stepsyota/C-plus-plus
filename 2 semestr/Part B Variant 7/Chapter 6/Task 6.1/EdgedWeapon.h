#pragma once
#include "AplliedArtObject.h"

class EdgedWeapon : virtual public AplliedArtObject
{
	char* type;
	double degree_of_sharpening;

public:
	EdgedWeapon();
	EdgedWeapon(char[], int, char[], char[], char[], int, int, int, char[], double);
	EdgedWeapon(const EdgedWeapon&);
	EdgedWeapon(EdgedWeapon&&);
	~EdgedWeapon();

	void set_type(char[]);
	void set_degree_of_sharpening(double);

	char* get_type() const;
	double get_degree_of_sharpening() const;

	void pop_object() override;
	void print() const override;
};