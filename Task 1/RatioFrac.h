#include <iostream>
#pragma once

using namespace std;

class RatioFrac
{
public:
	RatioFrac();
	RatioFrac(int , int, int);
	RatioFrac(const RatioFrac&);
	RatioFrac(RatioFrac&&);

	void operator=(const RatioFrac&);
	void operator=(RatioFrac&&);

	void operator+=(RatioFrac&);
	void operator-=(RatioFrac&);
	void set_celoe_chislo(int);
	void set_chisl(int);
	void set_znamen(int);

	int get_celoe_chislo() const;
	int get_chisl() const;
	int get_znamen() const;

	void print_frac() const;
	void clear();

	void summa(RatioFrac&);
	void razn(RatioFrac&);
private:
	int celoe_chislo;
	int chisl;
	int znamen;

	void racionalize();
	int find_znamen(RatioFrac&) const;
};