#pragma once
#include "AplliedArtObject.h"

class Coin : virtual public AplliedArtObject
{
	char* what_is_depicted;
	double value;

public:
	Coin();
	Coin(char[], int, char[], char[], char[], int, int, int, char[], double);
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