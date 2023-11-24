#include "Tara.h"

Tara::Tara()
{
	numarJudete = 0;
	resedinte = nullptr;
	presedinte = nullptr;
}

Tara::Tara(const int& numarJudete, const char* presedinte, const ResedintaJudet* resedinte)
{
	this->numarJudete = numarJudete;

	if (presedinte != nullptr)
	{
		this->presedinte = new char[strlen(presedinte) + 1];
		strcpy(this->presedinte, presedinte);
	}
	else
	{
		this->presedinte = nullptr;
	}

	if (resedinte != nullptr && numarJudete > 0)
	{
		this->resedinte = new ResedintaJudet[numarJudete];

		for (int j = 0; j < numarJudete; j++)
		{
			this->resedinte[j] = resedinte[j];
		}
	}
	else
	{
		this->resedinte = nullptr;
	}
}

Tara::Tara(const Tara& tara)
{
	this->numarJudete = tara.numarJudete;

	if (tara.presedinte != nullptr)
	{
		this->presedinte = new char[strlen(tara.presedinte) + 1];
		strcpy(this->presedinte, tara.presedinte);
	}
	else
	{
		this->presedinte = nullptr;
	}

	if (tara.resedinte != nullptr && tara.numarJudete > 0)
	{
		this->resedinte = new ResedintaJudet[tara.numarJudete];

		for (int j = 0; j < tara.numarJudete; j++)
		{
			this->resedinte[j] = tara.resedinte[j];
		}
	}
	else
	{
		this->resedinte = nullptr;
	}
}

Tara& Tara::operator=(const Tara& tara)
{
	if (this == &tara)
	{
		return *this;
	}

	if (presedinte != nullptr)
	{
		delete[] presedinte;
	}

	if (resedinte != nullptr)
	{
		delete[] resedinte;
	}

	this->numarJudete = tara.numarJudete;

	if (tara.presedinte != nullptr)
	{
		this->presedinte = new char[strlen(tara.presedinte) + 1];
		strcpy(this->presedinte, tara.presedinte);
	}
	else
	{
		this->presedinte = nullptr;
	}

	if (tara.resedinte != nullptr && tara.numarJudete > 0)
	{
		this->resedinte = new ResedintaJudet[tara.numarJudete];

		for (int j = 0; j < tara.numarJudete; j++)
		{
			this->resedinte[j] = tara.resedinte[j];
		}
	}
	else
	{
		this->resedinte = nullptr;
	}

	return *this;
}

Tara::~Tara()
{
	if (presedinte != nullptr)
	{
		delete[] presedinte;
	}

	if (resedinte != nullptr)
	{
		delete[] resedinte;
	}
}

void Tara::setPresedinte(const char* presedinte)
{
	if (presedinte == nullptr)
	{
		return;
	}

	if (this->presedinte != nullptr)
	{
		delete[] this->presedinte;
	}

	this->presedinte = new char[strlen(presedinte) + 1];
	strcpy(this->presedinte, presedinte);
}

void sortareResedinte(Tara& tara, ResedintaJudet& aux)
{
	if (tara.numarJudete <= 0 || tara.resedinte == nullptr)
	{
		return;
	}

	for (int i = 0; i < tara.numarJudete - 1; i++)
	{
		for (int j = i + 1; j < tara.numarJudete; j++)
		{
			if (tara.resedinte[i].getSalariuMediuPerLocalitate() > tara.resedinte[j].getSalariuMediuPerLocalitate())
			{
				aux = tara.resedinte[i];
				tara.resedinte[i] = tara.resedinte[j];
				tara.resedinte[j] = aux;
			}
		}
	}
}

std::ostream& operator<<(std::ostream& out, const Tara& tara)
{
	out << "Tara are " << tara.numarJudete << " resedinte de judet" << '\n';

	if (tara.presedinte != nullptr)
	{
		out << "Numele presedintelui din tara curenta este: " << tara.presedinte << '\n';
	}
	else
	{
		out << "Nu exista presedinte in tara curenta\n\n";
	}

	if (tara.resedinte != nullptr && tara.numarJudete > 0)
	{
		out << "Resedintele tarii vor aparea mai jos\n\n";

		for (int j = 0; j < tara.numarJudete; j++)
		{
			out << tara.resedinte[j];
		}
	}
	else
	{
		out << "Nu exista resedinte de judet in tara curenta\n\n";
	}

	return out;
}