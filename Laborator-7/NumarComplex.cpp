#include "NumarComplex.h"

NumarComplex::NumarComplex(const double& real, const double& imaginar)
{
	this->real = real;
	this->imaginar = imaginar;
}

bool NumarComplex::operator<(const NumarComplex& z) const
{
	return (sqrt(pow(this->real, 2) + pow(this->imaginar, 2)) <
		sqrt(pow(z.real, 2) + pow(z.imaginar, 2)));
}

std::ostream& operator<<(std::ostream& out, const NumarComplex& z)
{
	out << z.real << " + " << z.imaginar << "j\n";

	return out;
}