#pragma once
#include <iostream>

class Dreptunghi
{
	double lungime;
	double latime;

public:

	Dreptunghi(const double& lungime = 0, const double& latime = 0);
	bool operator>(const Dreptunghi& dreptunghi);
	friend std::ostream& operator<<(std::ostream& out, const Dreptunghi& dreptunghi);
};