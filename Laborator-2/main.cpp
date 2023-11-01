#include "Laptop.h"

int main()
{
	Laptop l1(32, 5000, "AMD Ryzen", "Windows 10", "Gigel");
	Laptop l2;

	std::cout << "Sistemul de operare de pe laptop este " << l1.getSistemDeOperare() <<
		" iar pretul laptopului este " << l1.getPret() << "\n\n";

	l1.afisareLaptop();
	l2.afisareLaptop();

	l2.setNumeAdministrator("Ioana");

	std::cout << "\n\n============================================\n\n";

	l2.afisareLaptop();

	Laptop* laptopuri = new Laptop[5];

	laptopuri[0].modificareLaptop(l1);
	laptopuri[1].modificareLaptop(16, 3450, "AMD Ryzen", "Windows 10", "Andrei");
	laptopuri[2].modificareLaptop(32, 5000, "I9 104234", "Windows 11", "Paul");
	laptopuri[3].modificareLaptop(8, 1500, "I5 213459", "Linux Mint", "Ion");
	laptopuri[4].modificareLaptop(4, 2000, "I7 102384", "Mac OS", "Petru");

	std::cout << "Vom afisa elementele unui vector de laptopuri mai jos\n\n";

	afisareVector(laptopuri);

	std::cout << "\n\n============================================\n\n";

	sortareVector(laptopuri);

	std::cout << "\n\n============================================\n\n";

	afisareVector(laptopuri);

	Laptop laptopRamMaxim;

	laptopRamMaxim.modificareLaptop(laptopuri[0]);

	for (int j = 1; j < 5; j++)
	{
		if (laptopuri[j].getRam() > laptopRamMaxim.getRam())
		{
			laptopRamMaxim.modificareLaptop(laptopuri[j]);
		}
	}

	std::cout << "\n\n============================================\n\n";

	laptopRamMaxim.afisareLaptop();

	delete[] laptopuri;
	laptopuri = nullptr;

	return 0;
}