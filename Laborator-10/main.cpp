#include "MotorMixt.h"

int main()
{
	int dimensiune = 10;

	Motor** motoare = new Motor * [dimensiune];

	motoare[0] = new MotorBenzina(2000, "Toyota", 4000, 25);
	motoare[1] = new MotorMixt(3500, "Honda", 4000, 15, 4500, 37);
	motoare[2] = new Motor(6000, "Mazda");
	motoare[3] = new MotorGpl(1500, "Peugeout", 3500, 17);
	motoare[4] = new Motor(2500, "Volkswagen");
	motoare[5] = new MotorMixt(3000, "Dacia-Renault", 3500, 14, 7000, 40);
	motoare[6] = new MotorGpl(2800, "Audi", 3700, 20);
	motoare[7] = new MotorBenzina(3000, "Hyundai", 2200, 25);
	motoare[8] = new MotorGpl(1000, "Ford", 1300, 12);
	motoare[9] = new Motor(1800, "BMW");

	afisareVectorMotoare(motoare, dimensiune, std::cout);

	std::cout << "\n==============================================================\n\n";

	sortareMotoareDupaPret(motoare, dimensiune);
	afisareVectorMotoare(motoare, dimensiune, std::cout);

	std::cout << "\n==============================================================\n\n";

	eliberareMemorieVectorMotoare(motoare, dimensiune);

	return 0;
}