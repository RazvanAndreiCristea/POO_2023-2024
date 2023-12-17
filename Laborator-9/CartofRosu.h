#pragma once
#include "Cartof.h"

class CartofRosu : public Cartof
{
	double greutate;

	void afisareAliment(std::ostream& out) const override;

public:

	CartofRosu();
	CartofRosu(const float& pret, const char* producator, const double& greutate);

	TipAliment getTipAliment() const override;
};