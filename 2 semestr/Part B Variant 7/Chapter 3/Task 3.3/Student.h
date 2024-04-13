#pragma once

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct Student
{
	char full_name[90];
	int age;
	bool gender;
	double grade;
	int course;
	int id;

	void fill_info(int);
	void output_info();
};