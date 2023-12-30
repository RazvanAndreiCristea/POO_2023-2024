#pragma once
#include "Motor.h"

class MotorGpl : virtual public Motor
{
	float pret;
	int capacitate;

public:

	MotorGpl();
	MotorGpl(const float& pretMotor, const char* marca, const float& pretMotorGpl, const int& capacitate);

	int getCapacitate() const;
	float getPretTotal() const;
	float getPret() const override;
	void afisareMotor(std::ostream& out) const override;
};