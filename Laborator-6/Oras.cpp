#include "Oras.h"

Oras::Oras()
{
	primar = nullptr;
	numarBlocuri = 0;
}

Oras::Oras(const char* primar, const int& numarBlocuri)
{
	this->numarBlocuri = numarBlocuri;

	if (primar != nullptr)
	{
		this->primar = new char[strlen(primar) + 1];
		strcpy(this->primar, primar);
	}
	else
	{
		this->primar = nullptr;
	}
}

Oras::Oras(const Oras& oras)
{
	this->numarBlocuri = oras.numarBlocuri;

	if (oras.primar != nullptr)
	{
		this->primar = new char[strlen(oras.primar) + 1];
		strcpy(this->primar, oras.primar);
	}
	else
	{
		this->primar = nullptr;
	}
}

Oras& Oras::operator=(const Oras& oras)
{
	if (this == &oras)
	{
		return *this;
	}

	if (this->primar != nullptr)
	{
		delete[] this->primar;
	}

	this->numarBlocuri = oras.numarBlocuri;

	if (oras.primar != nullptr)
	{
		this->primar = new char[strlen(oras.primar) + 1];
		strcpy(this->primar, oras.primar);
	}
	else
	{
		this->primar = nullptr;
	}

	return *this;
}

Oras::~Oras()
{
	if (primar != nullptr)
	{
		delete[] primar;
	}
}

std::ostream& operator<<(std::ostream& out, const Oras& oras)
{
	out << "Numarul de blocuri din oras este: " << oras.numarBlocuri << '\n';

	if (oras.primar != nullptr)
	{
		out << "Numele primarului din oras este: " << oras.primar << "\n\n";
	}
	else
	{
		out << "Nu exista primar in orasul curent\n\n";
	}

	return out;
}