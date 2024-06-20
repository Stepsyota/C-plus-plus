#pragma once
#include <iostream>
#include <vector>

using namespace std;

class String
{
private:
	char* string;
	int length;
public:
	String();
	String(char*);
	String(const String&);
	String(String&&);
	~String();

	int get_length() const;
	void input_string();

	void operator==(const String&) const;
	void operator!=(const String&) const;

	vector<String> separate_words();

	void print() const;

	void load_to_file(const char*);
	void input_from_file(const char*);
};