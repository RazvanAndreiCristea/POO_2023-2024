#include "Punct.h"

int main()
{
	Punct punct1;

	std::cout << punct1++ << '\n';
	std::cout << ++punct1 << '\n';

	punct1 = -punct1;

	std::cout << punct1 << '\n';
	std::cout << punct1 << '\n';

	int abscisa = punct1->getX();
	int ordonata = punct1.getY();

	Punct punct2;

	punct2 = punct1;
	punct2 = 10 + punct2 - 1 / 2 * punct1;
	punct2 = punct2 + 8;
	punct2 += punct1;

	punct1 = punct1 - 10;
	punct1 = 5 - punct1;
	punct1 -= punct2;

	std::cout << punct1 + punct2 << '\n';
	std::cout << punct1 - punct2 << '\n';
	std::cout << punct1 * punct2 << '\n';
	std::cout << punct1 / punct2 << '\n';

	std::cin >> punct1;
	std::cout << punct1 << '\n';

	return 0;
}