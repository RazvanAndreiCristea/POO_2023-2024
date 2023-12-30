#pragma once
#include <string>
#include <iostream>
#pragma warning(disable : 4996)

class Motor
{
	float pret;
	char* marca;

public:

	Motor();
	Motor(const float& pret, const char* marca);
	virtual ~Motor();

	char* getMarca() const;
	virtual float getPret() const;
	virtual void afisareMotor(std::ostream& out) const;

	friend std::ostream& operator<<(std::ostream& out, const Motor& motor);
};

void interschimbareMotoare(Motor*& a, Motor*& b);

void sortareMotoareDupaPret(Motor**& motoare, const int& size);

void afisareVectorMotoare(Motor**& motoare, const int& size, std::ostream& out);

void eliberareMemorieVectorMotoare(Motor**& motoare, const int& size);