#pragma once
#include "VisualArtObject.h"

class Photo : virtual public VisualArtObject
{
	char* photo_format;
	bool color_photo;

public:
	Photo();
	Photo(char[], int, char[], char[], char[], char[], char[], bool);
	Photo(const Photo&);
	Photo(Photo&&);
	~Photo();

	void set_photo_format(char*);
	void set_color_photo(bool);

	char* get_photo_format() const;
	bool get_color_photo() const;

	void pop_object() override;
	void print() const override;
};