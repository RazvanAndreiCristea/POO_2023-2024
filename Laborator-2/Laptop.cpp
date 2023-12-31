#include "Laptop.h"

Laptop::Laptop()
{
	ram = 0;
	pret = 0;

	strcpy(serieProcesor, "N/A");

	numeAdministrator = new char[strlen("Necunoscut") + 1];
	strcpy(numeAdministrator, "Necunoscut");

	sistemDeOperare = new char[strlen("Necunoscut") + 1];
	strcpy(sistemDeOperare, "Necunoscut");
}

Laptop::Laptop(const int ram, const float pret, const char serieProcesor[], const char* sistemDeOperare, const char* numeAdministrator)
{
	this->ram = ram;
	this->pret = pret;

	strcpy(this->serieProcesor, serieProcesor);

	if (numeAdministrator != nullptr)
	{
		this->numeAdministrator = new char[strlen(numeAdministrator) + 1];
		strcpy(this->numeAdministrator, numeAdministrator);
	}
	else
	{
		this->numeAdministrator = nullptr;
	}

	if (sistemDeOperare != nullptr)
	{
		this->sistemDeOperare = new char[strlen(sistemDeOperare) + 1];
		strcpy(this->sistemDeOperare, sistemDeOperare);
	}
	else
	{
		this->sistemDeOperare = nullptr;
	}
}

Laptop::~Laptop()
{
	if (numeAdministrator)
	{
		delete[] numeAdministrator;
	}

	if (sistemDeOperare)
	{
		delete[] sistemDeOperare;
	}
}

int Laptop::getRam() const
{
	return ram;
}

float Laptop::getPret() const
{
	return pret;
}

char* Laptop::getSistemDeOperare() const
{
	return sistemDeOperare;
}

void Laptop::setNumeAdministrator(const char* numeAdministrator)
{
	if (this->numeAdministrator)
	{
		delete[] this->numeAdministrator;
	}

	if (numeAdministrator != nullptr)
	{
		this->numeAdministrator = new char[strlen(numeAdministrator) + 1];
		strcpy(this->numeAdministrator, numeAdministrator);
	}
	else
	{
		this->numeAdministrator = nullptr;
	}
}

void Laptop::modificareLaptop(const int ram, const float pret, const char serieProcesor[], const char* sistemDeOperare, const char* numeAdministrator)
{
	this->ram = ram;
	this->pret = pret;

	strcpy(this->serieProcesor, serieProcesor);

	if (this->numeAdministrator)
	{
		delete[] this->numeAdministrator;
	}

	if (this->sistemDeOperare)
	{
		delete[] this->sistemDeOperare;
	}

	if (numeAdministrator != nullptr)
	{
		this->numeAdministrator = new char[strlen(numeAdministrator) + 1];
		strcpy(this->numeAdministrator, numeAdministrator);
	}
	else
	{
		this->numeAdministrator = nullptr;
	}

	if (sistemDeOperare != nullptr)
	{
		this->sistemDeOperare = new char[strlen(sistemDeOperare) + 1];
		strcpy(this->sistemDeOperare, sistemDeOperare);
	}
	else
	{
		this->sistemDeOperare = nullptr;
	}
}

void Laptop::modificareLaptop(const Laptop& laptop)
{
	this->ram = laptop.ram;
	this->pret = laptop.pret;

	strcpy(this->serieProcesor, laptop.serieProcesor);

	if (numeAdministrator != nullptr)
	{
		delete[] numeAdministrator;
	}

	if (sistemDeOperare != nullptr)
	{
		delete[] sistemDeOperare;
	}

	if (laptop.numeAdministrator != nullptr)
	{
		this->numeAdministrator = new char[strlen(laptop.numeAdministrator) + 1];
		strcpy(this->numeAdministrator, laptop.numeAdministrator);
	}
	else
	{
		this->numeAdministrator = nullptr;
	}

	if (laptop.sistemDeOperare != nullptr)
	{
		this->sistemDeOperare = new char[strlen(laptop.sistemDeOperare) + 1];
		strcpy(this->sistemDeOperare, laptop.sistemDeOperare);
	}
	else
	{
		this->sistemDeOperare = nullptr;
	}
}

void Laptop::afisareLaptop() const
{
	std::cout << "Dimensiunea memoriei ram este: " << ram << '\n';
	std::cout << "Pretul laptopului este: " << pret << '\n';
	std::cout << "Seria procesorului este: " << serieProcesor << '\n';
	std::cout << "Numele administratorului laptopului este: " << numeAdministrator << '\n';
	std::cout << "Sistemul de operare de pe laptop este: " << sistemDeOperare << '\n';
	std::cout << "\n\n===================================================\n\n";
}

void afisareVector(Laptop* laptopuri)
{
	for (int j = 0; j < 5; j++)
	{
		laptopuri[j].afisareLaptop();
	}
}

void sortareVector(Laptop* laptopuri)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (laptopuri[i].getPret() < laptopuri[j].getPret())
			{
				interchimbareLaptopuri(laptopuri[i], laptopuri[j]);
			}
		}
	}
}

void interchimbareLaptopuri(Laptop& l1, Laptop& l2)
{
	Laptop aux;

	aux.modificareLaptop(l1);
	l1.modificareLaptop(l2);
	l2.modificareLaptop(aux);
}