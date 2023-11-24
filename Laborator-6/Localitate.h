#pragma once
#include <iostream>

class Localitate
{
protected:

	int numarLocuitori;
	float* salariiLocuitori;

public:

	Localitate();
	Localitate(const int& numarLocuitori, const float* salariiLocuitori);
	Localitate(const Localitate& localitate);
	Localitate& operator=(const Localitate& localitate);
	~Localitate();

	float getSalariuMediuPerLocalitate() const;

	friend std::ostream& operator<<(std::ostream& out, const Localitate& localitate);
};