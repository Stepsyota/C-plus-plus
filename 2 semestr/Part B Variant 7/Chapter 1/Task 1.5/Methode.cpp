#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void output_line()
{
    for (int i = 0; i < 67; ++i)
    {
        cout << "-";
    }
    cout << endl;
}
void output_upper_part_table()
{
    cout << "|" << setw(5) << "S" << setw(5) << '|'
        << setw(5) << "t" << setw(5) << "|"
        << setw(18) << "Int" << setw(14) << "|"
        << setw(7) << "Iter" << setw(7) << "|" << endl;
}
void output_contane(double s, double t, double function, int counter)
{
    cout << "|" << setw(5) << s << setw(5) << "|"
        << setw(5) << t << setw(5) << "|"
        << setw(25) << setprecision(12) << function << setw(7) << "|"
        << setw(7) << counter << setw(7) << "|" << endl;
}

double calc_func(double x, double t, double s)
{
    double function = (tan(pow(x, 2)) + pow(x, 1 / 2)) / (t * log10(x + s));
    return function;
}
void methode(double (*calc_func)(double, double, double), double a, double b, double s1, double s2, double delta_s, double t1, double t2, double delta_t, double epsilon)
{
    int counter = 0, step1 = 1, step2 = 0;
    double h1 = 0, h2 = 0;
    double Integral_step1, Integral_step2;
    double x = a;
    for (double s = s1; s <= s2; s += delta_s)
    {
        for (double t = t1; t <= t2; t += delta_t)
        {
            do
            {
                Integral_step1 = 0;
                Integral_step2 = 0;
                step1 += 1;
                step2 = step1 / 2;
                h1 = (b - a) / step1;
                h2 = (b - a) / step2;
                for (int i = 0; i < step1; ++i)
                {
                    x = a + h1 / 2 + i * h1;
                    Integral_step1 += calc_func(x, t, s);
                }
                Integral_step1 *= h1;
                for (int j = 0; j < step2; ++j)
                {
                    x = a + h2 / 2 + j * h2;
                    Integral_step2 += calc_func(x, t, s);
                }
                Integral_step2 *= h2;
                counter += 1;
            } while (abs(Integral_step1 - Integral_step2) > epsilon);
            output_contane(s, t, Integral_step1, counter);
            step1 = 1, step2 = 0;
            counter = 0;
        }
    }
}