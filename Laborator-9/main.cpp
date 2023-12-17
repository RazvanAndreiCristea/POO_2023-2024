#include "Rosie.h"
#include "Morcov.h"
#include "Portocala.h"
#include "CartofRosu.h"

int main()
{
	int dimensiune = 10;

	Aliment** alimente = new Aliment * [dimensiune];

	alimente[0] = new CartofRosu(2.55f, "Simon Huba", 200);
	alimente[1] = new Morcov(1.5f, "Legumele proaspete ale mamei");
	alimente[2] = new Portocala(3.4f, "LIDL");
	alimente[3] = new Cartof(2.10f, "SC PAN NAUTIC S.R.L");
	alimente[4] = new Rosie(1.87f, "Kaufland");
	alimente[5] = new Portocala(5.4f, "Spania");
	alimente[6] = new Rosie(2.25f, "Dabuleni");
	alimente[7] = new Cartof(1.75f, "Leguminoasele");
	alimente[8] = new CartofRosu(1.6f, "Selgros", 80);
	alimente[9] = new Morcov(1.25f, "Morcovescu");

	std::cout << "Vector inainte de partitionare\n\n";

	afisareVectorAlimente(alimente, dimensiune, std::cout);

	std::cout << "===========================================================\n\n";
	std::cout << "Vector dupa partitionare\n\n";

	partitionareAlimenteDupaCheie(alimente, dimensiune);
	afisareVectorAlimente(alimente, dimensiune, std::cout);

	std::cout << "===========================================================\n\n";
	std::cout << "Producatorii de morcovi din vectorul neomogen sunt afisati mai jos\n\n";

	for (int j = 0; j < dimensiune; j++)
	{
		if (alimente[j]->getTipAliment() == TipAliment::kMORCOV)
		{
			std::cout << alimente[j]->getProducator() << '\n';
		}
	}

	std::cout << "\n\n";

	for (int j = 0; j < dimensiune; j++)
	{
		delete alimente[j];
	}

	delete[] alimente;

	return 0;
}