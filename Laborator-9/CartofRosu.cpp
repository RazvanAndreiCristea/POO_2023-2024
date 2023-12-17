#include "CartofRosu.h"

void CartofRosu::afisareAliment(std::ostream& out) const
{
	Cartof::afisareAliment(out);
	out << "Greutatea cartofului rosu este: " << greutate << " grame\n";
}

CartofRosu::CartofRosu() : Cartof()
{
	greutate = 0;
}

CartofRosu::CartofRosu(const float& pret, const char* producator, const double& greutate) : Cartof(pret, producator)
{
	this->greutate = greutate;
}

TipAliment CartofRosu::getTipAliment() const
{
	return TipAliment::kCARTOF_ROSU;
}