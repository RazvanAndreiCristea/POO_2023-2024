#include "Punct.h"

Punct::Punct(const double x, const double y, const double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Punct::Punct(const Punct& punct)
{
	this->x = punct.x;
	this->y = punct.y;
	this->z = punct.z;
}

Punct::~Punct()
{
	x = y = z = 0;
}

Punct& Punct::operator=(const Punct& punct)
{
	if (this == &punct)
	{
		return *this;
	}

	this->x = punct.x;
	this->y = punct.y;
	this->z = punct.z;

	return *this;
}

int Punct::getX() const
{
	return(int)x;
}

int Punct::getY() const
{
	return(int)y;
}

int Punct::getZ() const
{
	return(int)z;
}

Punct& Punct::operator+=(const Punct& punct)
{
	this->x += punct.x;
	this->y += punct.y;
	this->z += punct.z;

	return *this;
}

Punct& Punct::operator-=(const Punct& punct)
{
	this->x -= punct.x;
	this->y -= punct.y;
	this->z -= punct.z;

	return *this;
}

Punct& Punct::operator*=(const Punct& punct)
{
	this->x *= punct.x;
	this->y *= punct.y;
	this->z *= punct.z;

	return *this;
}

Punct& Punct::operator/=(const Punct& punct)
{
	this->x /= punct.x;
	this->y /= punct.y;
	this->z /= punct.z;

	return *this;
}

Punct& Punct::operator++()
{
	this->x++;
	this->y++;
	this->z++;

	return *this;
}

Punct& Punct::operator--()
{
	this->x--;
	this->y--;
	this->z--;

	return *this;
}

Punct Punct::operator++(int)
{
	Punct copiePunct = *this;

	this->x++;
	this->y++;
	this->z++;

	return copiePunct;
}

Punct Punct::operator--(int)
{
	Punct copiePunct = *this;

	this->x--;
	this->y--;
	this->z--;

	return copiePunct;
}

Punct* Punct::operator->()
{
	return this;
}

bool Punct::operator<(const Punct& punct) const
{
	if (this->x < punct.x && this->y < punct.y && this->z < punct.z)
	{
		return true;
	}

	return false;
}

bool Punct::operator<=(const Punct& punct) const
{
	if (this->x <= punct.x && this->y <= punct.y && this->z <= punct.z)
	{
		return true;
	}

	return false;
}

bool Punct::operator>(const Punct& punct) const
{
	if (this->x > punct.x && this->y > punct.y && this->z > punct.z)
	{
		return true;
	}

	return false;
}

bool Punct::operator>=(const Punct& punct) const
{
	if (this->x >= punct.x && this->y >= punct.y && this->z >= punct.z)
	{
		return true;
	}

	return false;
}

bool Punct::operator==(const Punct& punct) const
{
	if (this->x == punct.x && this->y == punct.y && this->z == punct.z)
	{
		return true;
	}

	return false;
}

bool Punct::operator!=(const Punct& punct) const
{
	if (this->x != punct.x || this->y != punct.y || this->z != punct.z)
	{
		return true;
	}

	return false;
}

Punct operator+(const Punct& p1, const Punct& p2)
{
	Punct p;

	p.x = p1.x + p2.x;
	p.y = p1.y + p2.y;
	p.z = p1.z + p2.z;

	return p;
}

Punct operator+(const Punct& punct, const int& scalar)
{
	Punct p;

	p.x = punct.x + scalar;
	p.y = punct.y + scalar;
	p.z = punct.z + scalar;

	return p;
}

Punct operator+(const int& scalar, const Punct& punct)
{
	Punct p;

	p.x = scalar + punct.x;
	p.y = scalar + punct.y;
	p.z = scalar + punct.z;

	return p;
}

Punct operator-(const Punct& p1, const Punct& p2)
{
	Punct p;

	p.x = p1.x - p2.x;
	p.y = p1.y - p2.y;
	p.z = p1.z - p2.z;

	return p;
}

Punct operator-(const Punct& punct, const int& scalar)
{
	Punct p;

	p.x = punct.x - scalar;
	p.y = punct.y - scalar;
	p.z = punct.z - scalar;

	return p;
}

Punct operator-(const int& scalar, const Punct& punct)
{
	Punct p;

	p.x = scalar - punct.x;
	p.y = scalar - punct.y;
	p.z = scalar - punct.z;

	return p;
}

Punct operator-(const Punct& punct)
{
	Punct p;

	p.x = -punct.x;
	p.y = -punct.y;
	p.z = -punct.z;

	return p;
}

Punct operator*(const Punct& p1, const Punct& p2)
{
	Punct p;

	p.x = p1.x * p2.x;
	p.y = p1.y * p2.y;
	p.z = p1.z * p2.z;

	return p;
}

Punct operator*(const Punct& punct, const int& scalar)
{
	Punct p;

	p.x = punct.x * scalar;
	p.y = punct.y * scalar;
	p.z = punct.z * scalar;

	return p;
}

Punct operator*(const int& scalar, const Punct& punct)
{
	Punct p;

	p.x = scalar * punct.x;
	p.y = scalar * punct.y;
	p.z = scalar * punct.z;

	return p;
}

Punct operator/(const Punct& p1, const Punct& p2)
{
	Punct p;

	p.x = p1.x / p2.x;
	p.y = p1.y / p2.y;
	p.z = p1.z / p2.z;

	return p;
}

Punct operator/(const Punct& punct, const int& scalar)
{
	Punct p;

	if (scalar != 0)
	{
		p.x = punct.x / scalar;
		p.y = punct.y / scalar;
		p.z = punct.z / scalar;
	}
	else
	{
		p.x = 0;
		p.y = 0;
		p.z = 0;
	}

	return p;
}

std::istream& operator>>(std::istream& in, Punct& punct)
{
	std::cout << "Introduceti coordonata x a punctului: ";
	in >> punct.x;
	std::cout << "Introduceti coordonata y a punctului: ";
	in >> punct.y;
	std::cout << "Introduceti coordonata z a punctului: ";
	in >> punct.z;

	return in;
}

std::ostream& operator<<(std::ostream& out, const Punct& punct)
{
	out << "Coordonata x a punctului este: " << punct.x << '\n';
	out << "Coordonata y a punctului este: " << punct.y << '\n';
	out << "Coordonata z a punctului este: " << punct.z << '\n';

	return out;
}

double lungimeDreapta(const Punct& p1, const Punct& p2)
{
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
}