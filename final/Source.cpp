
#include <iostream>
#include "rational.h"
#include <fstream>

using namespace std;

Rational::Rational()
{
	numer = 0;
	denom = 1;
}
Rational::Rational(int number)
{
	numer = number;
	denom = 1;
}
Rational::Rational(int n, int d)
{
	numer = n;
	denom = d;
}
Rational& Rational::operator +=(const Rational& r)
{
	numer = (numer * r.denom + denom * r.numer);
	denom *= r.denom;
	simplify();
	return *this;
}
Rational& Rational::operator +=(const int num)
{
	Rational r(num);
	numer = (numer * r.denom + denom * r.numer);
	denom *= r.denom;
	simplify();
	return *this;
}
Rational Rational::operator +(const Rational& r) const
{
	Rational res(*this);
	return res += r;
}
Rational Rational::operator +(const int num) const
{
	Rational res(*this);
	Rational second_num(num);
	return res += second_num;
}

Rational& Rational::operator -=(const Rational& r)
{
	return (*this += (-r));
}
Rational& Rational::operator -=(const int num)
{
	Rational r(num);
	return (*this += (-r));
}
Rational Rational::operator -() const
{
	Rational r(-numer, denom);
	return r;
}
Rational Rational::operator -(const Rational& r) const
{
	return *this + (-r);
}
Rational Rational::operator -(const int num) const
{
	Rational r(num);
	return *this + (-r);
}

Rational& Rational::operator *=(const Rational& r)
{
	numer *= r.numer;
	denom *= r.denom;
	simplify();
	return *this;
}
Rational& Rational::operator *=(const int num)
{
	Rational r(num);
	numer *= r.numer;
	denom *= r.denom;
	simplify();
	return *this;
}
Rational Rational::operator *(const Rational& r) const
{
	Rational res(*this);
	return res *= r;
}
Rational Rational::operator *(const int num) const
{
	Rational res(*this);
	Rational r(num);
	return res *= r;
}

Rational& Rational::operator /=(const Rational& r)
{
	numer *= r.denom;
	denom *= r.numer;
	simplify();
	return *this;
}
Rational& Rational::operator /=(const int num)
{
	Rational r(num);
	numer *= r.denom;
	denom *= r.numer;
	simplify();
	return *this;
}
Rational Rational::operator /(const Rational& r) const
{

	Rational res(*this);
	return res /= r;
}
Rational Rational::operator /(const int num) const
{
	Rational r(num);
	Rational res(*this);
	return res /= r;
}
void Rational::simplify()
{
	if (denom < 0)
	{
		numer = -numer;
		denom = -denom;
	}
	for (int i = 2; i <= abs(denom) && i <= abs(numer); i++)
		if (numer % i == 0 && denom % i == 0)
		{
			numer /= i;
			denom /= i;
			i--;
		}
}

ostream& operator <<(ostream& out, const Rational& r) {
	out << r.numer << "/" << r.denom;
	return out;
}
istream& operator >>(istream& in, Rational& r) {
	in >> r.numer >> r.denom;
	return in;
};