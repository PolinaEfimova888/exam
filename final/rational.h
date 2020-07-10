
#include <iostream>

using namespace std;

class Rational {
public:
	int numer, denom;
	Rational r(int x, int y);
	Rational();
	Rational(int number);
	Rational(int n, int d);
	Rational& operator +=(const Rational& r);
	Rational operator +(const Rational& r) const;
	Rational& operator -=(const Rational& r);
	Rational operator -() const;
	Rational operator -(const Rational& r) const;
	Rational& operator *=(const Rational& r);
	Rational operator *(const Rational& r) const;
	Rational& operator /=(const Rational& r);
	Rational operator /(const Rational& r) const;
	Rational operator +(const int num) const;
	Rational& operator +=(const int num);
	Rational& operator -=(const int num);
	Rational operator -(const int num) const;
	Rational& operator *=(const int num);
	Rational operator *(const int num) const;
	Rational& operator /= (const int num);
	Rational operator /(const int num) const;
	void simplify();
};


istream& operator >>(istream& in, Rational& r);
ostream& operator <<(ostream& out, const Rational& r);
