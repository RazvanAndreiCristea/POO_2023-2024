#pragma once
#include "MotorGpl.h"
#include "MotorBenzina.h"

class MotorMixt : public MotorGpl, public MotorBenzina
{
	int capacitateTotala;

public:

	MotorMixt();
	MotorMixt(const float& pretMotor, const char* marca, const float& pretMotorGpl, const int& capacitateMotorGpl,
		const float& pretMotorBenzina, const int& capacitateMotorBenzina);

	float getPret() const override;
	void afisareMotor(std::ostream& out) const override;
};