#pragma once
#include <string>
#include <iostream>
#pragma warning (disable : 4996)
#pragma warning (disable : 6031)

class Vagon
{
	int numarLocuri;
	float pretBilet;
	char* producator;

public:

	Vagon();
	Vagon(const int numarLocuri, const float pretBilet, const char* producator);
	Vagon(const Vagon& vagon);
	~Vagon();
	Vagon& operator=(const Vagon& vagon);
	int getNumarLocuri() const;
	char* getProducator() const;
	void setProducator(const char* producator);
	void afisareVagon() const;
	void modificareVagon(const int numarLocuri, const float pretBilet, const char* producator);
	friend float pretTotalLocuriPerVagon(const Vagon& vagon);
};

void afisareVector(Vagon*& vagoane);

void interschimbareVagoane(Vagon& v1, Vagon& v2);

void sortareAlfabetica(Vagon*& vagoane);