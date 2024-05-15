#pragma once
#include "VisualArtObject.h"

class Painting : virtual public VisualArtObject
{
	char* type_of_paint;
	char* dimensions;

public:
	Painting();
	Painting(char[], int, char[], char[], char[], char[], char[], char[]);
	Painting(const Painting&);
	Painting(Painting&&);
	~Painting();

	void set_type_of_paint(char*);
	void set_dimensions(char*);

	char* get_type_of_paint() const;
	char* get_dimensions() const;

	void pop_object() override;
	void print() const override;
};