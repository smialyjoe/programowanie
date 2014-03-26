#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>


using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;
public:
	Fraction();
	Fraction(int numerator, int denominator);
	~Fraction();
	int getNumerator();
	int getDenominator();
	void setNumerator(int numerator);
	void setDenominator(int denominator);
	friend ostream& operator<<(ostream& stream, Fraction& frac);
	friend istream& operator>>(istream& stream, Fraction& frac);
	float ConvertToDecimalFraction();
	Fraction operator+(Fraction b);
	Fraction operator-(Fraction b);
	Fraction operator/(Fraction b);
	Fraction operator*(Fraction b);
	Fraction operator^(Fraction b);
	Fraction fsqrt(int precision=5);
	string ToStringInproper();
	string ToStringMixedNumber();
	
};

