#pragma once
#include "Aliment.h"

class Rosie : public Aliment
{
	float pret;
	char* producator;

	void afisareAliment(std::ostream& out) const override;

public:

	Rosie();
	Rosie(const float& pret, const char* producator);
	~Rosie();

	float getPret() const override;
	char* getProducator() const override;
	TipAliment getTipAliment() const override;
};