#pragma once
#include "VisualArtObject.h"

class Sculpture : virtual public VisualArtObject
{
	char* material;
	char* dimensions;

public:
	Sculpture();
	Sculpture(char[], int, char[], char[], char[], char[], char[], char[]);
	Sculpture(const Sculpture&);
	Sculpture(Sculpture&&);
	~Sculpture();

	void set_material(char*);
	void set_dimensions(char*);

	char* get_material() const;
	char* get_dimensions() const;

	void pop_object() override;
	void Print() const override;
};