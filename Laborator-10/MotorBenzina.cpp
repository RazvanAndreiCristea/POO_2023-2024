#include "MotorBenzina.h"

MotorBenzina::MotorBenzina() : Motor()
{
	pret = 0.0f;
	capacitate = 0;
}

MotorBenzina::MotorBenzina(const float& pretMotor, const char* marca, const float& pretMotorBenzina, const int& capacitate) : 
	Motor(pretMotor, marca)
{
	this->pret = pretMotorBenzina;
	this->capacitate = capacitate;
}

int MotorBenzina::getCapacitate() const
{
	return capacitate;
}

float MotorBenzina::getPretTotal() const
{
	return pret + Motor::getPret();
}

float MotorBenzina::getPret() const
{
	return pret;
}

void MotorBenzina::afisareMotor(std::ostream& out) const
{
	Motor::afisareMotor(out);

	out << "Pretul motorului pe benzina este: " << pret << '\n';
	out << "Capacitatea motorului pe benzina este: " << capacitate << '\n';
}