#pragma once
#include "Motor.h"

class MotorBenzina : virtual public Motor
{
	float pret;
	int capacitate;

public:

	MotorBenzina();
	MotorBenzina(const float& pretMotor, const char* marca, const float& pretMotorBenzina, const int& capacitate);

	int getCapacitate() const;
	float getPretTotal() const;
	float getPret() const override;
	void afisareMotor(std::ostream& out) const override;
};