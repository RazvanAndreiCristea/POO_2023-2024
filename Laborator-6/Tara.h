#pragma once
#include "ResedintaJudet.h" 

class Tara
{
	int numarJudete;
	char* presedinte;
	ResedintaJudet* resedinte;

public:

	Tara();
	Tara(const int& numarJudete, const char* presedinte, const ResedintaJudet* resedinte);
	Tara(const Tara& tara);
	Tara& operator=(const Tara& tara);
	~Tara();

	void setPresedinte(const char* presedinte);

	friend void sortareResedinte(Tara& tara, ResedintaJudet& aux);
	friend std::ostream& operator<<(std::ostream& out, const Tara& tara);
};