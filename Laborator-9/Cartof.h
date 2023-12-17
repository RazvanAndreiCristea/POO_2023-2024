#pragma once
#include "Aliment.h"

class Cartof : public Aliment
{
	float pret;
	char* producator;

protected:

	void afisareAliment(std::ostream& out) const override;

public:
	Cartof();
	Cartof(const float& pret, const char* producator);
	~Cartof();
	float getPret() const override;
	char* getProducator() const override;
	TipAliment getTipAliment() const override;
};