#pragma once
#include <iostream>
#include <string>

#pragma warning (disable : 4996)
#pragma warning (disable : 6031)

class Laptop
{
	int ram;
	float pret;
	char* sistemDeOperare;
	char serieProcesor[10];
	char* numeAdministrator;

public:

	Laptop();
	Laptop(const int ram, const float pret, const char serieProcesor[], const char* sistemDeOperare, const char* numeAdministrator);
	~Laptop();
	int getRam() const;
	float getPret() const;
	char* getSistemDeOperare() const;
	void setNumeAdministrator(const char* numeAdministrator);
	void modificareLaptop(const int ram, const float pret, const char serieProcesor[], const char* sistemDeOperare, const char* numeAdministrator);
	void modificareLaptop(const Laptop& laptop);
	void afisareLaptop() const;
};

void afisareVector(Laptop* laptopuri);

void sortareVector(Laptop* laptopuri);

void interchimbareLaptopuri(Laptop& l1, Laptop& l2);