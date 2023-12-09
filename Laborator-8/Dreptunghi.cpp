#include "Dreptunghi.h"

Dreptunghi::Dreptunghi(const double& lungime, const double& latime)
{
	this->lungime = lungime;
	this->latime = latime;
}

bool Dreptunghi::operator>(const Dreptunghi& dreptunghi)
{
	return (this->lungime * this->latime > dreptunghi.lungime * dreptunghi.latime);
}

std::ostream& operator<<(std::ostream& out, const Dreptunghi& dreptunghi)
{
	std::cout << "Lungimea dreptunghiului este: " << dreptunghi.lungime << '\n';
	std::cout << "Latimea dreptunghiului este: " << dreptunghi.latime << '\n';

	return out;
}