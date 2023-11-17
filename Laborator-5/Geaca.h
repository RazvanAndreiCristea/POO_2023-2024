#pragma once
#include "Haina.h"

class Geaca : public Haina
{
	int marime;
	char* brand;

public:

	Geaca();
	Geaca(const float& pret, const char* material, const int& marime, const char* brand);
	Geaca(const Geaca& geaca);
	Geaca& operator=(const Geaca& geaca);
	~Geaca();

	int getMarime() const;

	friend std::istream& operator>>(std::istream& in, Geaca& haina);
	friend std::ostream& operator<<(std::ostream& out, const Geaca& geaca);
};

void interschimbareGeci(Geaca& g1, Geaca& g2);

void sortareVectorGeci(Geaca*& geci, const int& dimensiune);

void afisareVectorGeci(Geaca*& geci, const int& dimensiune);