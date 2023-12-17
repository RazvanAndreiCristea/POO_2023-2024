#pragma once
#include "Aliment.h"

class Morcov : public Aliment
{
	float pret;
	char* producator;

	void afisareAliment(std::ostream& out) const override;

public:

	Morcov();
	Morcov(const float& pret, const char* producator);
	~Morcov();

	float getPret() const override;
	char* getProducator() const override;
	TipAliment getTipAliment() const override;
};