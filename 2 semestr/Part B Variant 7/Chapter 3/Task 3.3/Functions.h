#pragma once

#include <iostream>
#include <fstream>
#include "Student.h"

using namespace std;

void edit_student_by_ID(const char*);
void delete_student_by_ID(const char*);
void redefine_two_files(const char*, const char*);
void add_element_in_another_file(ofstream&, Student&);
void add_student_to_the_end(const char*);
void add_student_to_the_end(const char*, Student&);
void make_data_base_with_needed_length(const char*, int);
void make_file_with_needed_students(const char*, const char*, int, int);
void read_file(const char*);
int get_size_file(const char*);
void clear_file(const char*);