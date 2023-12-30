#include "MotorGpl.h"

MotorGpl::MotorGpl() : Motor()
{
	pret = 0.0f;
	capacitate = 0;
}

MotorGpl::MotorGpl(const float& pretMotor, const char* marca, const float& pretMotorGpl, const int& capacitate) :
	Motor(pretMotor, marca)
{
	this->pret = pretMotorGpl;
	this->capacitate = capacitate;
}

int MotorGpl::getCapacitate() const
{
	return capacitate;
}

float MotorGpl::getPretTotal() const
{
	return pret + Motor::getPret();
}

float MotorGpl::getPret() const
{
	return pret;
}

void MotorGpl::afisareMotor(std::ostream& out) const
{
	Motor::afisareMotor(out);

	out << "Pretul motorului GPL este: " << pret << '\n';
	out << "Capacitatea motorului GPL este: " << capacitate << '\n';
}