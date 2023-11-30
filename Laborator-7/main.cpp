#include "Vector.h"

int main()
{
	Vector<int> vectorIntregi(6);

	vectorIntregi[0] = -10;
	vectorIntregi[1] = 1;
	vectorIntregi[2] = 0;
	vectorIntregi[3] = 10;
	vectorIntregi[4] = 12;
	vectorIntregi[5] = 3;

	std::cout << "Vector inainte de sortare\n\n";

	for (int j = 0; j < vectorIntregi.getSize(); j++)
	{
		std::cout << vectorIntregi[j] << " \t";
	}

	vectorIntregi.sort();

	std::cout << "\n\nVector dupa sortare\n\n";

	for (int j = 0; j < vectorIntregi.getSize(); j++)
	{
		std::cout << vectorIntregi[j] << " \t";
	}

	std::cout << "\n\n";

	Vector<double> vectorDoubleuri(8);

	vectorDoubleuri[0] = -10;
	vectorDoubleuri[1] = 1;
	vectorDoubleuri[2] = 0.2;
	vectorDoubleuri[3] = 100;
	vectorDoubleuri[4] = 12.5;
	vectorDoubleuri[5] = 3;
	vectorDoubleuri[6] = 3.5;
	vectorDoubleuri[7] = -2.24;

	std::cout << "Vector inainte de sortare\n\n";

	for (int j = 0; j < vectorDoubleuri.getSize(); j++)
	{
		std::cout << vectorDoubleuri[j] << " \t";
	}

	vectorDoubleuri.sort();

	std::cout << "\n\nVector dupa sortare\n\n";

	for (int j = 0; j < vectorDoubleuri.getSize(); j++)
	{
		std::cout << vectorDoubleuri[j] << " \t";
	}

	std::cout << "\n\n";

	Vector<Fractie> vectorFractii(5);

	vectorFractii[0] = Fractie(1, 2);
	vectorFractii[1] = Fractie(-3, 5);
	vectorFractii[2] = Fractie(10, 2);
	vectorFractii[3] = Fractie(-2, -8);
	vectorFractii[4] = Fractie(12, 10);

	Vector<Fractie> copieFractii = vectorFractii;

	std::cout << "Vector inainte de sortare\n\n";

	for (int j = 0; j < copieFractii.getSize(); j++)
	{
		std::cout << copieFractii[j];
	}

	copieFractii.sort();

	std::cout << "\nVector dupa sortare\n\n";

	for (int j = 0; j < copieFractii.getSize(); j++)
	{
		std::cout << copieFractii[j];
	}

	std::cout << '\n';

	Vector<NumarComplex> vectorNrComplexe(5);

	vectorNrComplexe[0] = NumarComplex(2, 5);
	vectorNrComplexe[1] = NumarComplex(1, 3);
	vectorNrComplexe[2] = NumarComplex(2, -2);
	vectorNrComplexe[3] = NumarComplex(-10, 7);
	vectorNrComplexe[4] = NumarComplex(2, 1.5);

	std::cout << "Vector inainte de sortare\n\n";

	for (int j = 0; j < vectorNrComplexe.getSize(); j++)
	{
		std::cout << vectorNrComplexe[j];
	}

	vectorNrComplexe.sort();

	std::cout << "\nVector dupa sortare\n\n";

	for (int j = 0; j < vectorNrComplexe.getSize(); j++)
	{
		std::cout << vectorNrComplexe[j];
	}

	std::cout << '\n';

	std::cout << vectorNrComplexe[-1];

	return 0;
}