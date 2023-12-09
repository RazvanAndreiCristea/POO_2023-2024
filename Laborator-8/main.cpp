#include "Lista-Dubla.h"

int main()
{
	ListaDubla<int> listaIntregi;

	listaIntregi.pushBack(0);
	listaIntregi.pushFront(1);
	listaIntregi.pushFront(-1);
	listaIntregi.pushFront(10);
	listaIntregi.pushBack(2);

	ListaDubla<int> copieListaIntregi = listaIntregi;

	listaIntregi.showListFromFirtsToLast(std::cout);

	std::cout << '\n';

	listaIntregi.showListFromLastToFirst(std::cout);

	std::cout << '\n';

	copieListaIntregi.showListFromFirtsToLast(std::cout);

	std::cout << '\n';

	copieListaIntregi.showListFromLastToFirst(std::cout);

	copieListaIntregi.popFront();

	listaIntregi = copieListaIntregi;

	std::cout << "\n\n===============================================\n\n";

	listaIntregi.showListFromFirtsToLast(std::cout);

	std::cout << '\n';

	listaIntregi.showListFromLastToFirst(std::cout);

	std::cout << '\n';

	copieListaIntregi.showListFromFirtsToLast(std::cout);

	std::cout << '\n';

	copieListaIntregi.showListFromLastToFirst(std::cout);

	std::cout << '\n';

	listaIntregi.sort();

	listaIntregi.showListFromFirtsToLast(std::cout);

	std::cout << '\n';

	listaIntregi.showListFromLastToFirst(std::cout);

	std::cout << "\n\n============================================\n\n";

	listaIntregi.showFirstNode(std::cout);
	listaIntregi.showLastNode(std::cout);

	std::cout << "\nDimensiunea listei este: " << listaIntregi.getSize() << '\n';

	listaIntregi.popFront();
	listaIntregi.popBack();

	std::cout << '\n';

	listaIntregi.showFirstNode(std::cout);
	listaIntregi.showLastNode(std::cout);

	std::cout << "\nDimensiunea listei este: " << listaIntregi.getSize() << '\n';

	// Analog si pentru restul tipurilor de date se va proceda la fel

	return 0;
}