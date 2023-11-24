#include "ResedintaJudet.h"

ResedintaJudet::ResedintaJudet() : Localitate(), Oras()
{
	numeResedinta = nullptr;
}

ResedintaJudet::ResedintaJudet(const int& numarLocuitori, const float* salariiLocuitori, const char* primar,
	const int& numarBlocuri, const char* numeResedinta) : Localitate(numarLocuitori, salariiLocuitori), Oras(primar, numarBlocuri)
{
	if (numeResedinta != nullptr)
	{
		this->numeResedinta = new char[strlen(numeResedinta) + 1];
		strcpy(this->numeResedinta, numeResedinta);
	}
	else
	{
		this->numeResedinta = nullptr;
	}
}

ResedintaJudet::ResedintaJudet(const ResedintaJudet& resedintaJudet) : Localitate(resedintaJudet), Oras(resedintaJudet)
{
	if (resedintaJudet.numeResedinta != nullptr)
	{
		this->numeResedinta = new char[strlen(resedintaJudet.numeResedinta) + 1];
		strcpy(this->numeResedinta, resedintaJudet.numeResedinta);
	}
	else
	{
		this->numeResedinta = nullptr;
	}
}

ResedintaJudet& ResedintaJudet::operator=(const ResedintaJudet& resedintaJudet)
{
	if (this == &resedintaJudet)
	{
		return *this;
	}

	(Oras&)(*this) = resedintaJudet;
	(Localitate&)(*this) = resedintaJudet;

	if (this->numeResedinta != nullptr)
	{
		delete[] this->numeResedinta;
	}

	if (resedintaJudet.numeResedinta != nullptr)
	{
		this->numeResedinta = new char[strlen(resedintaJudet.numeResedinta) + 1];
		strcpy(this->numeResedinta, resedintaJudet.numeResedinta);
	}
	else
	{
		this->numeResedinta = nullptr;
	}

	return *this;
}

ResedintaJudet::~ResedintaJudet()
{
	if (numeResedinta != nullptr)
	{
		delete[] numeResedinta;
	}
}

std::ostream& operator<<(std::ostream& out, const ResedintaJudet& resedintaJudet)
{
	operator<<(out, (Localitate&)resedintaJudet);
	operator<<(out, (Oras&)resedintaJudet);

	if (resedintaJudet.numeResedinta != nullptr)
	{
		out << "Resedinta de judet este: " << resedintaJudet.numeResedinta << "\n\n";
	}
	else
	{
		out << "Nu exista resedinta de judet\n\n";
	}

	return out;
}

void afisareVectorResedinte(ResedintaJudet*& resedinte, const int& numarResedinte)
{
	if (resedinte == nullptr || numarResedinte <= 0)
	{
		std::cout << "Dimensinea vectorului de resedinte este 0 sau nu exista vectorul de resedinte\n\n";
		return;
	}

	for (int i = 0; i < numarResedinte; i++)
	{
		std::cout << resedinte[i];
	}
}

void adaugareResedintaLaFinal(ResedintaJudet*& resedinte, int& numarResedinte, const ResedintaJudet& resedintaNoua)
{
	numarResedinte++;

	ResedintaJudet* copieResedinte = new ResedintaJudet[numarResedinte];

	for (int j = 0; j < numarResedinte - 1; j++)
	{
		copieResedinte[j] = resedinte[j];
	}

	copieResedinte[numarResedinte - 1] = resedintaNoua;

	delete[] resedinte;

	resedinte = copieResedinte;
}