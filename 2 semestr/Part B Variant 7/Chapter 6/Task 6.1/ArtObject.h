#pragma once

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

	void set_author(char[]);
	void set_time_of_creation(int);
	void set_place_of_creation(char[]);
	void set_designation(char[]);

	char* get_author() const;
	int get_time_of_creation() const;
	char* get_place_of_creation() const;
	char* get_designation() const;

	virtual void pop_object();
	virtual void print() const;

	virtual ArtObject* clone() const = 0;

	friend std::ostream& operator<<(std::ostream& out, const ArtObject& obj)
	{
		obj.print();
		return out;
	}
};