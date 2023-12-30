#include "MotorMixt.h" 

MotorMixt::MotorMixt() : Motor(), MotorGpl(), MotorBenzina()
{
	capacitateTotala = 0;
}

MotorMixt::MotorMixt(const float& pretMotor, const char* marca, const float& pretMotorGpl, const int& capacitateMotorGpl,
	const float& pretMotorBenzina, const int& capacitateMotorBenzina) :
	Motor(pretMotor, marca),
	MotorGpl(pretMotor, marca, pretMotorGpl, capacitateMotorGpl),
	MotorBenzina(pretMotor, marca, pretMotorBenzina, capacitateMotorBenzina)
{
	capacitateTotala = capacitateMotorGpl + capacitateMotorBenzina;
}

float MotorMixt::getPret() const
{
	return MotorGpl::getPretTotal() + MotorBenzina::getPretTotal() - Motor::getPret();
}

void MotorMixt::afisareMotor(std::ostream& out) const
{
	Motor::afisareMotor(out);

	out << "Pretul motorului GPL este: " << MotorGpl::getPret() << '\n';
	out << "Capacitatea motorului GPL este: " << MotorGpl::getCapacitate() << '\n';
	out << "Pretul motorului pe benzina este: " << MotorBenzina::getPret() << '\n';
	out << "Capacitatea motorului pe benzina este: " << MotorBenzina::getCapacitate() << '\n';
	out << "Pretul total al motorului mixt este: " << getPret() << '\n';
	out << "Capacitatea totala a motorului mixt este: " << capacitateTotala << '\n';
}