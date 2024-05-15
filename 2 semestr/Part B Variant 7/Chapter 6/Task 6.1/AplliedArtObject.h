#pragma once
#include "ArtObject.h"

class AplliedArtObject : virtual public ArtObject
{
	char* material;
	int number_of_copies;
	int	year_of_start_of_use;
	int year_of_end_of_use;

public:
	AplliedArtObject();
	AplliedArtObject(char[], int, int, int);
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
	virtual void print() const override;
};