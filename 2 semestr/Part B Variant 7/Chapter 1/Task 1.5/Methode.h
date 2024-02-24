#pragma once


void output_line();
void output_upper_part_table();
void output_contane(double, double, double, int);
double calc_func(double, double, double);
void methode(double (*)(double, double, double), double a, double b, double s1, double s2, double delta_s, double t1, double t2, double delta_t, double epsilon);