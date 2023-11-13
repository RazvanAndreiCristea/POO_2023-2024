#pragma once
#include <cmath>
#include <iostream>

class Punct
{
	double x;
	double y;
	double z;

public:

	// construtorul de copiere, operatorul egal si destructorul 
	// functioneaza corect si daca nu sunt declarati si implementati 

	Punct(const double x = 0, const double y = 0, const double z = 0);
	Punct(const Punct& punct);
	~Punct();
	Punct& operator=(const Punct& punct);

	int getX() const;
	int getY() const;
	int getZ() const;

	// operatori aritmetici specializati pentru lucrul intre obiecte

	Punct& operator+=(const Punct& punct);
	Punct& operator-=(const Punct& punct);
	Punct& operator*=(const Punct& punct);
	Punct& operator/=(const Punct& punct);

	Punct& operator++(); // forma pre-fixata
	Punct& operator--();
	Punct operator++(int); // forma post-fixata
	Punct operator--(int);

	// operatorul sageata

	Punct* operator->();

	// operatori logici de comparare intre obiecte

	bool operator<(const Punct& punct) const;
	bool operator<=(const Punct& punct) const;
	bool operator>(const Punct& punct) const;
	bool operator>=(const Punct& punct) const;
	bool operator==(const Punct& punct) const;
	bool operator!=(const Punct& punct) const;

	// operatori aritmetici specializati pentru a efectua operatii intre obiecte si alte tipuri de date

	friend Punct operator+(const Punct& p1, const Punct& p2);
	friend Punct operator+(const Punct& punct, const int& scalar);
	friend Punct operator+(const int& scalar, const Punct& punct);

	friend Punct operator-(const Punct& p1, const Punct& p2);
	friend Punct operator-(const Punct& punct, const int& scalar);
	friend Punct operator-(const int& scalar, const Punct& punct);

	friend Punct operator-(const Punct& punct); // returneaza opusul unui punct

	friend Punct operator*(const Punct& p1, const Punct& p2);
	friend Punct operator*(const Punct& punct, const int& scalar);
	friend Punct operator*(const int& scalar, const Punct& punct);

	friend Punct operator/(const Punct& p1, const Punct& p2);
	friend Punct operator/(const Punct& punct, const int& scalar);

	// operatorii de citire si afisare pentru obiecte de tip Punct

	friend std::istream& operator>>(std::istream& in, Punct& punct);
	friend std::ostream& operator<<(std::ostream& out, const Punct& punct);

	friend double lungimeDreapta(const Punct& p1, const Punct& p2);
};