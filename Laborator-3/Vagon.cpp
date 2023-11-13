#include "Vagon.h"

Vagon::Vagon()
{
	numarLocuri = 0;
	pretBilet = 0.0f;

	producator = new char[strlen("Necunoscut") + 1];
	strcpy(producator, "Necunoscut");
}

Vagon::Vagon(const int numarLocuri, const float pretBilet, const char* producator)
{
	this->numarLocuri = numarLocuri;
	this->pretBilet = pretBilet;

	if (producator != nullptr)
	{
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);
	}
	else
	{
		this->producator = nullptr;
	}
}

Vagon::Vagon(const Vagon& vagon)
{
	this->numarLocuri = vagon.numarLocuri;
	this->pretBilet = vagon.pretBilet;

	if (vagon.producator != nullptr)
	{
		this->producator = new char[strlen(vagon.producator) + 1];
		strcpy(this->producator, vagon.producator);
	}
	else
	{
		this->producator = nullptr;
	}
}

Vagon::~Vagon()
{
	if (producator != nullptr)
	{
		delete[] producator;
	}
}

Vagon& Vagon::operator=(const Vagon& vagon)
{
	if (this == &vagon)
	{
		return *this;
	}

	if (this->producator != nullptr)
	{
		delete[] this->producator;
	}

	this->numarLocuri = vagon.numarLocuri;
	this->pretBilet = vagon.pretBilet;

	if (vagon.producator != nullptr)
	{
		this->producator = new char[strlen(vagon.producator) + 1];
		strcpy(this->producator, vagon.producator);
	}
	else
	{
		this->producator = nullptr;
	}

	return *this;
}

int Vagon::getNumarLocuri() const
{
	return numarLocuri;
}

char* Vagon::getProducator() const
{
	return producator;
}

void Vagon::setProducator(const char* producator)
{
	if (producator == nullptr)
	{
		return;
	}

	if (this->producator != nullptr)
	{
		delete[] this->producator;
	}

	this->producator = new char[strlen(producator) + 1];
	strcpy(this->producator, producator);
}

void Vagon::afisareVagon() const
{
	std::cout << "Capacitatea vagonului este: " << numarLocuri << '\n';

	if (producator != nullptr)
	{
		std::cout << "Producatorul vagonului este: " << producator << '\n';
	}
	else
	{
		std::cout << "Producatorul este nullptr" << '\n';
	}

	std::cout << "Pretul unui bilet este: " << pretBilet << '\n';
	std::cout << "\n===========================================================\n\n";
}

void Vagon::modificareVagon(const int numarLocuri, const float pretBilet, const char* producator)
{
	this->numarLocuri = numarLocuri;
	this->pretBilet = pretBilet;

	if (this->producator != nullptr)
	{
		delete[] this->producator;
	}

	if (producator != nullptr)
	{
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);
	}
	else
	{
		this->producator = nullptr;
	}
}

float pretTotalLocuriPerVagon(const Vagon& vagon)
{
	return vagon.numarLocuri * vagon.pretBilet;
}

void afisareVector(Vagon*& vagoane)
{
	for (int j = 0; j < 5; j++)
	{
		vagoane[j].afisareVagon();
	}
}

void interschimbareVagoane(Vagon& v1, Vagon& v2)
{
	Vagon aux = v1;
	v1 = v2;
	v2 = aux;
}

void sortareAlfabetica(Vagon*& vagoane)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (strcmp(vagoane[i].getProducator(), vagoane[j].getProducator()) > 0)
			{
				interschimbareVagoane(vagoane[i], vagoane[j]);
			}
		}
	}
}