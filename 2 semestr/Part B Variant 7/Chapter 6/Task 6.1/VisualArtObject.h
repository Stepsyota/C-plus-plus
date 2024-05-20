#pragma once
#include "ArtObject.h"

class VisualArtObject : virtual public ArtObject
{
	char* genre;
	char* what_is_depicted;
public:
	VisualArtObject();
	VisualArtObject(char[], char[]);
	VisualArtObject(const VisualArtObject&);
	VisualArtObject(VisualArtObject&&);
	virtual ~VisualArtObject();

	void set_genre(char*);
	void set_what_is_depicted(char*);

	char* get_genre() const;
	char* get_what_is_depicted() const;

	virtual void pop_object() override;
	virtual void print() const override;

	virtual ArtObject* clone() const override = 0;
};