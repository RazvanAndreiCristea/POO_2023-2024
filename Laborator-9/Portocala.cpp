#include "Portocala.h"

void Portocala::afisareAliment(std::ostream& out) const
{
	out << "Pretul portocalei este: " << pret << " ron\n";
	out << "Producatorul de portocale este: " << producator << '\n';
}

Portocala::Portocala()
{
	pret = 0.0f;
	producator = nullptr;
}

Portocala::Portocala(const float& pret, const char* producator)
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

Portocala::~Portocala()
{
	if (producator != nullptr)
	{
		delete[] producator;
	}
}

float Portocala::getPret() const
{
	return pret;
}

char* Portocala::getProducator() const
{
	return producator;
}

TipAliment Portocala::getTipAliment() const
{
	return TipAliment::kPORTOCALA;
}