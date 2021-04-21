#include "Fraction.hpp"
using namespace std;

//----------------------------------------------------------//
// Implementation of class functions                        //
//----------------------------------------------------------//

Fraction::Fraction (int nn, int dd) : m_iNom (nn), m_iDenom (dd)
{
	if (m_iDenom == 0) m_iDenom = 1;
	reduce ();
}

int Fraction::gcd (int i, int j)
{
	if ((i == 0) || (j == 0))
		return i + j;
	while (i %= j) 
	{
		int t = i;
		i = j;
		j = t;
	}
	return j;
}

void Fraction::reduce ()
{
	int g = gcd (m_iNom, m_iDenom);
	m_iNom /= g;
	m_iDenom /= g;
}

//----------------------------------------------------------//
// Implementation of class operators                        //
//----------------------------------------------------------//

bool Fraction::operator == (const Fraction &f) const
{
	return ((m_iNom == f.m_iNom) && (m_iDenom == f.m_iDenom));
}

bool Fraction::operator != (const Fraction &f) const
{
	return !(*this == f);
}

Fraction& Fraction::operator ++ ()
{
	m_iNom += m_iDenom;
	reduce ();
	return *this;
}

const Fraction Fraction::operator ++ (int)
{
	int nn = m_iNom;
	int dd = m_iDenom;
	m_iNom += m_iDenom;
	reduce ();
	return Fraction (nn, dd);
}

//----------------------------------------------------------//
// Implementation of friend functions                       //
//----------------------------------------------------------//

Fraction operator + (const Fraction &f1, const Fraction &f2)
{
	int nn = f1.m_iNom * f2.m_iDenom + f1.m_iDenom * f2.m_iNom;
	int dd = f1.m_iDenom * f2.m_iDenom;
	return Fraction (nn, dd);
}

Fraction operator - (const Fraction &f1, const Fraction &f2)
{
	int nn = f1.m_iNom * f2.m_iDenom - f1.m_iDenom * f2.m_iNom;
	int dd = f1.m_iDenom * f2.m_iDenom;
	return Fraction (nn, dd);
}

Fraction operator * (const Fraction &f1, const Fraction &f2)
{
	int nn = f1.m_iNom * f2.m_iNom;
	int dd = f1.m_iDenom * f2.m_iDenom;
	return Fraction (nn, dd);
}

Fraction operator / (const Fraction &f1, const Fraction &f2)
{
	int nn = f1.m_iNom * f2.m_iDenom;
	int dd = f1.m_iDenom * f2.m_iNom;
	return Fraction (nn, dd);
}

ostream& operator << (ostream& os, const Fraction &frac)
{
	return os << frac.m_iNom << "/" << frac.m_iDenom;
}

istream& operator >> (istream &is, Fraction &frac)
{
	char divSign;
	is >> frac.m_iNom >> divSign >> frac.m_iDenom;
	if (frac.m_iDenom == 0)
		frac.m_iDenom = 1;
	frac.reduce ();
	return is;
}

//----------------------------------------------------------//
// Implementation of bad operator. No syntax error here     //
//----------------------------------------------------------//

Fraction operator % (const Fraction &f1, const Fraction &f2)
{
	int nn = f1.m_iNom + f2.m_iNom;
	int dd = f2.m_iDenom + f2.m_iDenom;
	return Fraction (nn, dd);
}