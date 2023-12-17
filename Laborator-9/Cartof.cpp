#include "Cartof.h"

void Cartof::afisareAliment(std::ostream& out) const
{
	out << "Pretul cartofului este: " << pret << " ron\n";
	out << "Producatorul de cartofi este: " << producator << '\n';
}

Cartof::Cartof()
{
	pret = 0.0f;
	producator = nullptr;
}

Cartof::Cartof(const float& pret, const char* producator)
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

Cartof::~Cartof()
{
	if (producator != nullptr)
	{
		delete[] producator;
	}
}

float Cartof::getPret() const // float Cartof::getPret(const Cartof* this)
{
	return pret;
}

char* Cartof::getProducator() const
{
	return producator;
}

TipAliment Cartof::getTipAliment() const
{
	return TipAliment::kCARTOF;
}