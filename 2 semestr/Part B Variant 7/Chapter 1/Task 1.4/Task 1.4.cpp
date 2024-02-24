#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>

using namespace std;

void print_A(int*, double a = -2, double b = 1, double epsilon = pow(10,-6), double s = 0);
double calc_func_A(double, double);
double derivative_A(double, double);
void print_B(int*, double a = 0, double b = 2, double s_start = 2.8, double s_end = 3.2, double delta_s = 0.05, double epsilon = pow(10,-6));
double calc_func_B(double, double);
double derivative_B(double, double);
void output_line();
void output_upper_part_table();
void output_contane(double, double, double, int);
void method_tangent(double (*)(double, double), double (*)(double, double), double, double, double, int, double);


int main()
{
    int counter = 0;
    double epsilon = pow(10, -6);
    double a_A = -2, b_A = 1;
    double a_B = 0, b_B = 2;
    double s_start = 2.8, s_end = 3.2, delta_s = 0.05;

    print_A(&counter);
    print_B(&counter);
}


void print_A(int* counter, double a, double b, double epsilon, double s)
{
    double (*A)(double, double) { calc_func_A };
    double (*A_der)(double, double) { derivative_A };
    cout << "Part A" << endl;
    output_line();
    output_upper_part_table();
    output_line();
    method_tangent(A, A_der, a, b, s, *counter, epsilon);
    cout << '\n' << '\n';
}
double calc_func_A(double x, double s)
{
    double function = pow((x + 3), 3) - 8;
    return function;
}
double derivative_A(double x, double s)
{
    double first_der_A = 3 * pow((x + 3), 2);
    return first_der_A;
}

void print_B(int* counter, double a, double b, double s_start, double s_end, double delta_s, double epsilon)
{
    cout << "Part B" << endl;
    output_line();
    output_upper_part_table();
    output_line();
    for (double s = s_start; s <= s_end; s += delta_s)
    {
        double (*B)(double, double) { calc_func_B };
        double (*B_der)(double, double) { derivative_B };
        method_tangent(B, B_der, a, b, s, *counter, epsilon);

    }
    cout << '\n' << '\n';
}
double calc_func_B(double x, double s)
{
    double function = cos((M_PI * x)) - pow(x, s);
    return function;
}
double derivative_B(double x, double s)
{
    double first_der_B = -M_PI * sin(M_PI * x) - s * pow(x, s - 1);
    return first_der_B;
}

void output_line()
{
    for (int i = 0; i < 77; ++i)
    {
        cout << "-";
    }
    cout << endl;
}
void output_upper_part_table()
{
    cout << "|" << setw(5) << "S" << setw(5) << '|'
        << setw(11) << "X" << setw(9) << "|"
        << setw(20) << "F(x)" << setw(12) << "|"
        << setw(7) << "Iter" << setw(7) << "|" << endl;
}
void output_contane(double s, double x, double function, int counter)
{
    cout << "|" << setw(5) << s << setw(5) << "|"
        << setw(14) << setprecision(10) << x << setw(6) << "|"
        << setw(25) << setprecision(12) << function << setw(7) << "|"
        << setw(7) << counter << setw(7) << "|" << endl;
}

void method_tangent(double (*calc_func)(double, double), double (*derivative)(double, double), double a, double b, double s, int counter, double epsilon)
{
    double x_pred = a, x_now = b, function = 0;
    while (abs(x_now - x_pred) > epsilon)
    {
        x_pred = x_now;
        x_now = x_pred - (calc_func(x_pred, s) / derivative(x_pred, s));
        function = calc_func(x_now, s);
        output_contane(s, x_now, function, counter);
        counter += 1;
    }

    output_line();
}