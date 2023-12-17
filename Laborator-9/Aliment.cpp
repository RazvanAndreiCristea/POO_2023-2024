#include "Aliment.h"

Aliment::~Aliment()
{

}

std::ostream& operator<<(std::ostream& out, const Aliment& aliment)
{
	aliment.afisareAliment(out);

	out << '\n';

	return out;
}

void interchimbareAlimente(Aliment*& x, Aliment*& y)
{
	Aliment* aux = x;
	x = y;
	y = aux;
}

void partitionareAlimenteDupaCheie(Aliment**& alimente, const int& size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (alimente[i]->getTipAliment() > alimente[j]->getTipAliment())
			{
				interchimbareAlimente(alimente[i], alimente[j]);
			}
		}
	}
}

void afisareVectorAlimente(Aliment**& alimente, const int& size, std::ostream& out)
{
	for (int j = 0; j < size; j++)
	{
		out << *alimente[j];
	}
}