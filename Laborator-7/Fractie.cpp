#include "Fractie.h"

Fractie::Fractie(const double& numarator, const double& numitor)
{
	this->numarator = numarator;

	if (numitor != 0)
	{
		this->numitor = numitor;
	}
	else
	{
		this->numitor = 1;
	}
}

bool Fractie::operator<(const Fractie& fractie) const
{
	return (this->numarator / this->numitor < fractie.numarator / fractie.numitor);
}

std::ostream& operator<<(std::ostream& out, const Fractie& fractie)
{
	out << fractie.numarator << '/' << fractie.numitor << '\n';

	return out;
}