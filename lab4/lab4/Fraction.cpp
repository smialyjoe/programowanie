#include "stdafx.h"
#include "Fraction.h"


Fraction::Fraction()
{
	numerator = 0;
	denominator = 1;
}
Fraction::Fraction(int numerator, int denominator) : numerator(numerator)
{
	this->setDenominator(denominator);
}
Fraction::~Fraction()
{

}
ostream& operator<<(ostream& stream, Fraction& frac)
{
	stream << frac.ToStringInproper();
	return stream;
}
istream& operator>>(istream& stream, Fraction& frac)
{
	return stream;
}
float Fraction::ConvertToDecimalFraction()
{
	return (float)numerator / denominator;
}

Fraction Fraction::operator+(Fraction b)
{
	Fraction result = Fraction();
	result.setNumerator(this->numerator + b.getNumerator());
	result.setDenominator(this->denominator + b.getDenominator());
	return result;
}

Fraction Fraction::operator-(Fraction b)
{
	Fraction result = Fraction();
	result.setNumerator(this->numerator - b.getNumerator());
	result.setDenominator(this->denominator - b.getDenominator());
	return result;
}

Fraction Fraction::operator/(Fraction b)
{
	Fraction result = Fraction();
	if (this->denominator == 0 || b.getDenominator() == 0)
		return result;
	result.setNumerator(this->numerator / b.getNumerator());
	result.setDenominator(this->denominator / b.getDenominator());
	return result;
}

Fraction Fraction::operator*(Fraction b)
{
	Fraction result = Fraction();
	result.setNumerator(this->numerator * b.getNumerator());
	result.setDenominator(this->denominator * b.getDenominator());
	return result;
}

Fraction Fraction::operator^(Fraction b)
{
	Fraction result = Fraction();
	result.setNumerator(this->numerator ^ b.getNumerator());
	result.setDenominator(this->denominator ^ b.getDenominator());
	return result;
}
string Fraction::ToStringInproper()
{
	stringstream ss;
	string frac = "";
	ss << numerator;
	ss >> frac;
	ss.str("");
	ss.clear();
	frac.append("/");
	ss << denominator;
	frac.append(ss.str());
	return frac;
}

string Fraction::ToStringMixedNumber()
{
	stringstream ss;
	string result;
	int whole_number = numerator / denominator;
	if (whole_number > 0)
	{
		ss << numerator / denominator;
		result.append(ss.str());
		result.append(" ");
		ss.str("");
		ss.clear();
		int fraction = numerator % denominator;
		if (fraction != 0)
		{
			ss << fraction;
			result.append(ss.str());
			ss.str("");
			ss.clear();
			result.append("/");
			ss << denominator;
			result.append(ss.str());
		}
		return result;
	}
	else
		return this->ToStringInproper();
}

void Fraction::setDenominator(int denominator)
{
	if (denominator == 0)
		return;
	this->denominator = denominator;
}

void Fraction::setNumerator(int numerator)
{
	this->numerator = numerator;
}

int Fraction::getDenominator()
{
	return this->denominator;
}

int Fraction::getNumerator()
{
	return this->numerator;
}

/*
Precyzja okreœla z jak¹ dok³adnoœci¹ bêdziemy konwertowaæ pierwiastek spowrotem u³amek zwyk³y
jest to wyk³adnik potêgi 10, maksymalnie 9, ¿eby nie przekroczyæ zakresu floata
*/
Fraction Fraction::fsqrt(int precision)
{
	Fraction result = Fraction();
	float frac = this->ConvertToDecimalFraction();
	frac = sqrt(frac);
	if (precision > 9)
		precision = 9;
	unsigned int multipler = pow(10,precision);
	result.setNumerator((int)(frac * multipler) % multipler);
	result.setDenominator(multipler);
	return result;
}