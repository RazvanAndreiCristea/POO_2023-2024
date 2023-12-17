#pragma once
#include <string>
#include <iostream>
#pragma warning(disable : 4996)

enum TipAliment { kCARTOF, kCARTOF_ROSU, kMORCOV, kROSIE, kPORTOCALA };

class Aliment // este o interfata pentru ca are doar metode virtual pure
{
protected:

	virtual void afisareAliment(std::ostream& out) const = 0;

public:

	virtual float getPret() const = 0;
	virtual TipAliment getTipAliment() const = 0;
	virtual char* getProducator() const = 0;
	virtual ~Aliment() = 0;

	friend std::ostream& operator<<(std::ostream& out, const Aliment& aliment);
};

void interchimbareAlimente(Aliment*& x, Aliment*& y);

void partitionareAlimenteDupaCheie(Aliment**& alimente, const int& size);

void afisareVectorAlimente(Aliment**& alimente, const int& size, std::ostream& out);