#include "Rosie.h"

void Rosie::afisareAliment(std::ostream& out) const
{
	out << "Pretul rosiei este: " << pret << " ron\n";;
	out << "Producatorul de rosii este: " << producator << '\n';
}

Rosie::Rosie()
{
	pret = 0.0f;
	producator = nullptr;
}

Rosie::Rosie(const float& pret, const char* producator)
{
	this->pret = pret;

	if (producator != nullptr)
	{
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);
	}
	else
	{
		this->producator = nullptr;
	}
}

Rosie::~Rosie()
{
	if (producator != nullptr)
	{
		delete[] producator;
	}
}

float Rosie::getPret() const
{
	return pret;
}

char* Rosie::getProducator() const
{
	return producator;
}

TipAliment Rosie::getTipAliment() const
{
	return TipAliment::kROSIE;
}