#include "RatioFrac.h"

RatioFrac::RatioFrac()
{
	this->celoe_chislo = 0;
	this->chisl = 0;
	this->znamen = 1;
}
RatioFrac::RatioFrac(int celoe_chislo, int chisl, int znamen)
{
	this->celoe_chislo = celoe_chislo;
	this->chisl = chisl;
	this->znamen = znamen;
}
RatioFrac::RatioFrac(const RatioFrac& other)
{
	this->celoe_chislo = other.get_celoe_chislo();
	this->chisl = other.get_chisl();
	this->znamen = other.get_znamen();
}
RatioFrac::RatioFrac(RatioFrac&& other)
{
	this->celoe_chislo = other.get_celoe_chislo();
	this->chisl = other.get_chisl();
	this->znamen = other.get_znamen();
	other.clear();
}

void RatioFrac::set_celoe_chislo(int celoe_chislo)
{
	this->celoe_chislo = celoe_chislo;
}
void RatioFrac::set_chisl(int chisl)
{
	this->chisl = chisl;
}
void RatioFrac::set_znamen(int znamen)
{
	this->znamen = znamen;
}

int RatioFrac::get_celoe_chislo() const
{
	return celoe_chislo;
}
int RatioFrac::get_chisl() const
{
	return chisl;
}
int RatioFrac::get_znamen() const
{
	return znamen;
}

void RatioFrac::print_frac() const
{
	cout << celoe_chislo;
	if (chisl == 0)
	{
		cout << endl;
		return;
	}
	if ((chisl > 0 && znamen > 0) || (chisl < 0 && znamen < 0))
	{
		cout << " + ";
	}
	else
	{
		cout << " - ";
	}
	cout << chisl << "/" << znamen << endl;
}

void RatioFrac::clear()
{
	this->celoe_chislo = 0;
	this->chisl = 0;
	this->znamen = 1;
}

void RatioFrac::racionalize()
{
	if ((chisl % znamen != 0 || chisl > znamen) && znamen != 1)
	{
		celoe_chislo += chisl / znamen;
		chisl = chisl % znamen;
	}
	if (celoe_chislo > 0 && chisl < 0 && znamen > 0 || celoe_chislo > 0 && chisl > 0 && znamen < 0)
	{
		celoe_chislo -= 1;
		chisl += znamen;
		
		if (chisl < 0)
		{
			chisl = 0 - chisl;
		}
		if (znamen < 0)
		{
			znamen = 0 - znamen;
		}
	} 
	for (int i = chisl - 1; i > 0; --i)
	{
		if (chisl % i == 0 && znamen % i == 0)
		{
			chisl /= i;
			znamen /= i;
		}
	}

}

void RatioFrac::summa(RatioFrac& other)
{
	RatioFrac dublicat = RatioFrac(other);
	int need_znamen = find_znamen(dublicat);

	this->chisl *= need_znamen / this->znamen;
	this->znamen = need_znamen;

	dublicat.set_chisl(dublicat.get_chisl() * need_znamen / dublicat.get_znamen());
	dublicat.set_znamen(need_znamen);

	this->celoe_chislo += dublicat.get_celoe_chislo();
	this->chisl += dublicat.get_chisl();
	racionalize();
}

void RatioFrac::razn(RatioFrac& other)
{
	RatioFrac dublicat = RatioFrac(other);
	int need_znamen = find_znamen(dublicat);

	this->chisl *= need_znamen / this->znamen;
	this->znamen = need_znamen;

	dublicat.set_chisl(dublicat.get_chisl() * need_znamen / dublicat.get_znamen());
	dublicat.set_znamen(need_znamen);

	this->celoe_chislo -= dublicat.get_celoe_chislo();
	this->chisl -= dublicat.get_chisl();
	racionalize();
}

int RatioFrac::find_znamen(RatioFrac& other) const
{
	int znam1 = this->znamen;
	int znam2 = other.get_znamen();
	int high_znamen = znam1 > znam2 ? znam1 : znam2;
	while (high_znamen % znam1 != 0 || high_znamen % znam2 != 0)
	{
		high_znamen++;
	}
	return high_znamen;
}

void RatioFrac::operator+=(RatioFrac& other)
{
	summa(other);
}

void RatioFrac::operator-=(RatioFrac& other)
{
	razn(other);
}

void RatioFrac::operator=(const RatioFrac& other)
{
	this->celoe_chislo = other.get_celoe_chislo();
	this->chisl = other.get_chisl();
	this->znamen = other.get_znamen();
}

void RatioFrac::operator=(RatioFrac&& other)
{
	this->celoe_chislo = other.get_celoe_chislo();
	this->chisl = other.get_chisl();
	this->znamen = other.get_znamen();
	other.clear();
}