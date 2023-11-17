#include "Geaca.h"

Geaca::Geaca() : Haina()
{
	marime = 0;
	brand = nullptr;
}

Geaca::Geaca(const float& pret, const char* material, const int& marime, const char* brand) : Haina(pret, material)
{
	this->marime = marime;

	if (brand != nullptr)
	{
		this->brand = new char[1 + strlen(brand)];
		strcpy(this->brand, brand);
	}
	else
	{
		this->brand = nullptr;
	}
}

Geaca::Geaca(const Geaca& geaca) : Haina(geaca)
{
	this->marime = geaca.marime;

	if (geaca.brand != nullptr)
	{
		this->brand = new char[1 + strlen(geaca.brand)];
		strcpy(this->brand, geaca.brand);
	}
	else
	{
		this->brand = nullptr;
	}
}

Geaca& Geaca::operator=(const Geaca& geaca)
{
	if (this == &geaca)
	{
		return *this;
	}

	(Haina&)(*this) = geaca;

	// echivalent cu a apela explicit operatorul '=' din clasa de baza (in cazul nostru Haina): Haina::operator=(geaca);

	if (this->brand != nullptr)
	{
		delete[] this->brand;
	}

	this->marime = geaca.marime;

	if (geaca.brand != nullptr)
	{
		this->brand = new char[1 + strlen(geaca.brand)];
		strcpy(this->brand, geaca.brand);
	}
	else
	{
		this->brand = nullptr;
	}

	return *this;
}

Geaca::~Geaca()
{
	if (brand != nullptr)
	{
		delete[] brand;
	}
}

int Geaca::getMarime() const
{
	return marime;
}

std::istream& operator>>(std::istream& in, Geaca& geaca)
{
	operator>>(in, (Haina&)geaca);

	if (geaca.brand != nullptr)
	{
		delete[] geaca.brand;
	}

	std::cout << "Introduceti marimea gecii: ";
	in >> geaca.marime;

	char* buffer = new char[100];

	std::cout << "Introduceti brandul gecii: ";

	in.ignore();
	in.getline(buffer, 100);

	geaca.brand = new char[strlen(buffer) + 1];
	strcpy(geaca.brand, buffer);

	delete[] buffer;

	return in;
}

std::ostream& operator<<(std::ostream& out, const Geaca& geaca)
{
	operator<<(out, (Haina&)geaca);

	// sau acelasi lucru doar ca este un apel implicit: out << (Haina&) geaca;

	out << "Marimea gecii este: " << geaca.marime << '\n';
	out << "Brandul gecii esteL " << geaca.brand << '\n';

	return out;
}

void interschimbareGeci(Geaca& g1, Geaca& g2)
{
	Geaca aux = g1;
	g1 = g2;
	g2 = aux;
}

void sortareVectorGeci(Geaca*& geci, const int& dimensiune)
{
	for (int i = 0; i < dimensiune - 1; i++)
	{
		for (int j = i + 1; j < dimensiune; j++)
		{
			if (geci[i].getMarime() > geci[j].getMarime())
			{
				interschimbareGeci(geci[i], geci[j]);
			}
		}
	}
}

void afisareVectorGeci(Geaca*& geci, const int& dimensiune)
{
	for (int j = 0; j < dimensiune; j++)
	{
		std::cout << geci[j] << '\n';
	}
}