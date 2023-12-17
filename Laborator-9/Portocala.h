#pragma once
#include "Aliment.h"

class Portocala : public Aliment
{
	float pret;
	char* producator;

	void afisareAliment(std::ostream& out) const override;

public:

	Portocala();
	Portocala(const float& pret, const char* producator);
	~Portocala();

	float getPret() const override;
	char* getProducator() const override;
	TipAliment getTipAliment() const override;
};