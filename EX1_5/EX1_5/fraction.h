#pragma once
#include <iostream>
using namespace std;

/// <summary>
/// 
///		A FRACTION class has:
///			nume	: numerator
///			deno	: denominator
/// 
/// </summary>

class FRACTION {
private:
	int nume, deno;	

	// Function to find greatest common divisor and least common multiple
	int GCD(int a, int b);
	int LCM(int a, int b);
public:
	FRACTION();
	FRACTION(int, int);
	~FRACTION();

	//Supportive function group
	void format();
	FRACTION reduction();
	FRACTION inversion();

	//input and output data in class
	friend istream& operator>>(istream&, FRACTION&);
	friend ostream& operator<<(ostream&, FRACTION);	

	int getNumerator();
	int getDenominator();
	void setNumerator(int);
	void setDenominator(int);

	//Calculation function group
	FRACTION operator +(const FRACTION&);
	FRACTION operator -(const FRACTION&);
	FRACTION operator *(const FRACTION&);
	FRACTION operator /(const FRACTION&);
};