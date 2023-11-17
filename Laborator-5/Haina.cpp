#include "Haina.h"

Haina::Haina()
{
	pret = 0.0f;
	material = nullptr;
}

Haina::Haina(const float& pret, const char* material)
{
	this->pret = pret;

	if (material != nullptr)
	{
		this->material = new char[1 + strlen(material)];
		strcpy(this->material, material);
	}
	else
	{
		this->material = nullptr;
	}
}

Haina::Haina(const Haina& haina)
{
	this->pret = haina.pret;

	if (haina.material != nullptr)
	{
		this->material = new char[1 + strlen(haina.material)];
		strcpy(this->material, haina.material);
	}
	else
	{
		this->material = nullptr;
	}
}

Haina& Haina::operator=(const Haina& haina)
{
	if (this == &haina)
	{
		return *this;
	}

	if (this->material != nullptr)
	{
		delete[] this->material;
	}

	this->pret = haina.pret;

	if (haina.material != nullptr)
	{
		this->material = new char[1 + strlen(haina.material)];
		strcpy(this->material, haina.material);
	}
	else
	{
		this->material = nullptr;
	}

	return *this;
}

Haina::~Haina()
{
	if (material != nullptr)
	{
		delete[] material;
	}
}

float Haina::getPret() const
{
	return pret;
}

std::istream& operator>>(std::istream& in, Haina& haina)
{
	if (haina.material != nullptr)
	{
		delete[] haina.material;
	}

	std::cout << "Introduceti pretul hainei: ";
	in >> haina.pret;

	char* buffer = new char[100];

	std::cout << "Introduceti materialul din care este confectionata haina: ";

	in.ignore();
	in.getline(buffer, 100);

	haina.material = new char[strlen(buffer) + 1];
	strcpy(haina.material, buffer);

	delete[] buffer;

	return in;
}

std::ostream& operator<<(std::ostream& out, const Haina& haina)
{
	out << "Pretul hainei este: " << haina.pret << '\n';
	out << "Materialul din care este confectionata haina este: " << haina.material << '\n';

	return out;
}