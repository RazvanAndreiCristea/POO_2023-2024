#include "Geaca.h"

int main()
{
	int dimensiune = 5;

	Geaca g;
	Haina haina(555.99f, "Bumbac");
	Geaca geaca(264.55f, "Piele", 3, "Givova");

	g = geaca;

	std::cout << g << '\n';
	std::cout << haina << '\n';
	std::cout << geaca << '\n';

	Geaca* geci = new Geaca[dimensiune];

	geci[0] = Geaca(geaca);
	geci[1] = Geaca(325.5f, "Bumbac", 2, "Patagonia");
	geci[2] = Geaca(699.99f, "Fas", 4, "Columbia");
	geci[3] = Geaca(700, "Lana", 1, "Monlcer");
	geci[4] = Geaca(200, "Puf", 5, "Gucci");

	std::cout << "Vom afisa un vector nesortat de geci mai jos\n\n";

	afisareVectorGeci(geci, dimensiune);

	std::cout << "Vectorul de geci sortat crescator dupa campul marime este afisat mai jos\n\n";

	sortareVectorGeci(geci, dimensiune);

	afisareVectorGeci(geci, dimensiune);

	Geaca geacaPretMaxim = geci[0];

	for (int j = 1; j < 5; j++)
	{
		if (geacaPretMaxim.getPret() < geci[j].getPret())
		{
			geacaPretMaxim = geci[j];
		}
	}

	std::cout << "Geaca cu pretul maxim din vector este mai jos\n\n" << geacaPretMaxim << '\n';

	delete[] geci;
	geci = nullptr;

	std::cout << "Vom citi si afisa un obiect de tip Geaca mai jos\n\n";

	std::cin >> g; // sirurile de caractere pot fi citite si cu spatii
	std::cout << '\n' << g << '\n';

	return 0;
}