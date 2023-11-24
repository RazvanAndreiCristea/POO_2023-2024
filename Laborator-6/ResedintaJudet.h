#pragma once
#include "Oras.h"
#include "Localitate.h"

class ResedintaJudet : public Localitate, public Oras
{
	char* numeResedinta;

public:

	ResedintaJudet();
	ResedintaJudet(const int& numarLocuitori, const float* salariiLocuitori,
		const char* primar, const int& numarBlocuri, const char* numeResedinta);
	ResedintaJudet(const ResedintaJudet& resedintaJudet);
	ResedintaJudet& operator=(const ResedintaJudet& resedintaJudet);
	~ResedintaJudet();

	friend std::ostream& operator<<(std::ostream& out, const ResedintaJudet& resedintaJudet);
};

void afisareVectorResedinte(ResedintaJudet*& resedinte, const int& numarResedinte);
void adaugareResedintaLaFinal(ResedintaJudet*& resedinte, int& numarResedinte, const ResedintaJudet& resedintaNoua);