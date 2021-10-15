#include "fraction.h"
using namespace std;

// Function to find greatest common divisor
int FRACTION::GCD(int a, int b) {
		if (b == 0) return a;
		return GCD(b, a % b);
}

// Function to find least common multiple
int FRACTION::LCM(int a, int b) {
	return (a * b) / GCD(a, b);
}

// Function create of class
FRACTION::FRACTION() {
	this->nume = this->deno = 0;
}

// Function cancel of class 
FRACTION::~FRACTION() {
	this->nume = this->deno = 0;
}

// Function to format fraction (convert the denominator to positive)
void FRACTION::format() {
	if (this->deno < 0) {
		this->deno = -this->deno;
		this->nume = -this->nume;
	}
}

// Function to reduction a fraction
FRACTION FRACTION::reduction() {
	int d = GCD(this->nume, this->deno);
	if (d == 0 || d == 1)	return *this;

	this->nume /= d;
	this->deno /= d;
	return *this;
}

// Function to inversion fraction
FRACTION FRACTION::inversion() {
	swap(this->nume, this->deno);
	return *this;
}

// Function input fraction
istream& operator>>(istream& is, FRACTION& ft) {
	cout << "- Enter the numerator: ";
	is >> ft.nume;

	while (1) {
		cout << "- Enter the denominator: ";
		is >> ft.deno;
		if (ft.deno != 0)
			break;
		cout << "Unknown fraction!\n";
	}
	ft.format();
	return is;
}

// Function output fraction
ostream& operator<<(ostream& os, FRACTION ft) {
	ft.format();
	os << "(";
	if (ft.deno == 0)
		os << "inf";
	else
		if (ft.nume == ft.deno)
			os << 1;
		else
			if (!ft.nume || ft.deno == 1)
				os << ft.nume;
			else 
				os << ft.nume << "/" << ft.deno;
	os << ")";
	return os;
}

FRACTION FRACTION::operator +(const FRACTION& ft2) {
	FRACTION addFt;
	int lcm = LCM(abs(this->deno), abs(ft2.deno));

	addFt.nume = this->nume * (lcm / this->deno) + ft2.nume * (lcm / ft2.deno);
	addFt.deno = lcm;

	return addFt;
}

FRACTION FRACTION::operator -(const FRACTION& ft2) {
	FRACTION tempFt = ft2;
	
	tempFt.nume = -tempFt.nume;
		
	return *this + tempFt;
}

FRACTION FRACTION::operator *(const FRACTION& ft2) {
	FRACTION mulFt;
	mulFt.nume = this->nume * ft2.nume;
	mulFt.deno = this->deno * ft2.deno;
	return mulFt;
}

FRACTION FRACTION::operator /(const FRACTION& ft2) {
	FRACTION inverFt2 = ft2;
	inverFt2.inversion();
	return *this * inverFt2;
}