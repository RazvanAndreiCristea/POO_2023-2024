#include "Vagon.h"

int main()
{
	Vagon vagon1(75, 22.5f, "Alstom");
	Vagon vagon2;

	std::cout << "Vom afisa 2 vagoane mai jos.\n\n";

	vagon1.afisareVagon();
	vagon2.afisareVagon();

	std::cout << "Numarul de locuri din primul vagon este: " << vagon1.getNumarLocuri() << "\n\n";

	Vagon vagon3 = vagon2;

	vagon3.setProducator("Astra Trans Arad");
	vagon2 = vagon1;

	std::cout << "Am folosit constructorul de copiere si operatorul egal\n\n";

	vagon2.afisareVagon();
	vagon3.afisareVagon();

	Vagon* vagoane = new Vagon[5];

	vagoane[0] = vagon1;
	vagoane[1].modificareVagon(80, 55, "Trans Continental");
	vagoane[2].modificareVagon(90, 25, "UTA");
	vagoane[3].modificareVagon(78, 100, "DB");
	vagoane[4].modificareVagon(55, 55, "Electroputere Craiova");

	std::cout << "Vector inainte de sortare\n\n";

	afisareVector(vagoane);

	sortareAlfabetica(vagoane);

	std::cout << "Vector dupa sortare\n\n";

	afisareVector(vagoane);

	float costTotal = 0.0f;

	for (int j = 0; j < 5; j++)
	{
		costTotal += pretTotalLocuriPerVagon(vagoane[j]);
	}

	std::cout << "Valoarea totala a locurilor din vectorul de vagoane este: " << costTotal << "\n\n";

	delete[] vagoane;
	vagoane = nullptr;

	return 0;
}