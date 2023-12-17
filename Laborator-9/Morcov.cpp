#include "Morcov.h"

void Morcov::afisareAliment(std::ostream& out) const
{
	out << "Pretul morcovului este: " << pret << " ron\n";;
	out << "Producatorul de morcovi este: " << producator << '\n';
}

Morcov::Morcov()
{
	pret = 0.0f;
	producator = nullptr;
}

Morcov::Morcov(const float& pret, const char* producator)
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

Morcov::~Morcov()
{
	if (producator != nullptr)
	{
		delete[] producator;
	}
}

float Morcov::getPret() const
{
	return pret;
}

char* Morcov::getProducator() const
{
	return producator;
}

TipAliment Morcov::getTipAliment() const
{
	return TipAliment::kMORCOV;
}