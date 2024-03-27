#pragma once

#include <iostream>
#include <fstream>

using namespace std;

struct Student
{
	char full_name[60];
	int age;
	bool gender;
	double grade;
	int course;
	int id;

	void fill_info(int);
	void output_info();
};