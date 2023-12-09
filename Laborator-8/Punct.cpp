#include "Punct.h"

Punct::Punct(const double& x, const double& y)
{
	this->x = x;
	this->y = y;
}

bool Punct::operator>(const Punct& punct) const
{
	return (this->x > punct.x && this->y > punct.y);
}

std::ostream& operator<<(std::ostream& out, const Punct& punct)
{
	out << "Coordonata x a punctului este: " << punct.x << '\n';
	out << "Coordonata y a punctului este: " << punct.y << '\n';

	return out;
}