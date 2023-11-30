#include "Tara.h"

namespace utils
{
	Tara tara;
	ResedintaJudet aux;
	ResedintaJudet* resedinte;
}

int main()
{
	int numarJudete = 5;

	float salarii1[4] = { 7500.f, 16000.f, 9245.f, 18000.f };
	float salarii2[3] = { 5000.f, 7000.f, 10000.f };
	float salarii3[2] = { 10000.f, 15000.f };
	float salarii4[5] = { 2000.f, 3000.f, 4600.f, 5320.f, 6800.f };
	float salarii5[3] = { 1000.f, 2000.f, 3000.f };
	float salarii6[6] = { 1500.f, 2050.f, 3200.f, 4800.f, 5900.f, 6100.f };

	utils::resedinte = new ResedintaJudet[numarJudete];

	utils::resedinte[0] = ResedintaJudet(4, salarii1, "Nicusor Dan", 500, "Bucuresti");
	utils::resedinte[1] = ResedintaJudet(3, salarii2, "Alin Stoica", 300, "Brasov");
	utils::resedinte[2] = ResedintaJudet(2, salarii3, "Marius Bostan", 200, "Cluj");
	utils::resedinte[3] = ResedintaJudet(5, salarii4, "Cristian Popescu", 600, "Constanta");
	utils::resedinte[4] = ResedintaJudet(3, salarii5, "Mihai Popa", 400, "Iasi");

	utils::tara = Tara(numarJudete, "Klaus Iohanis", utils::resedinte);

	std::cout << "Tara inainte de sortarea resedintelor dupa salariul mediu pe localitate\n\n"
		<< "================================================================\n\n" << utils::tara;

	sortareResedinte(utils::tara, utils::aux);
	utils::tara.setPresedinte("Nicolae Ceausescu");

	std::cout << "================================================================\n\n"
		<< "Tara dupa sortarea resedintelor dupa salariul mediu pe localitate si schimbarea presedintelui\n\n"
		<< "================================================================\n\n" << utils::tara;

	ResedintaJudet resedintaNoua = ResedintaJudet(6, salarii6, "Emil Boc", 400, "Oradea");

	adaugareResedintaLaFinal(utils::resedinte, numarJudete, resedintaNoua);

	std::cout << "================================================================\n\n"
		<< "Vector cu o resedinta adaugata pe utima pozitie\n\n"
		<< "================================================================\n\n";

	afisareVectorResedinte(utils::resedinte, numarJudete);

	delete[] utils::resedinte;

	utils::resedinte = nullptr;

	return 0;
}