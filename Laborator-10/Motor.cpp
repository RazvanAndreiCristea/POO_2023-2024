#include "Motor.h"

Motor::Motor()
{
	pret = 0.0f;
	marca = nullptr;
}

Motor::Motor(const float& pret, const char* marca)
{
	this->pret = pret;

	if (marca != nullptr)
	{
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
	}
	else
	{
		this->marca = nullptr;
	}
}

Motor::~Motor()
{
	if (marca != nullptr)
	{
		delete[] marca;
	}
}

char* Motor::getMarca() const
{
	return marca;
}

float Motor::getPret() const
{
	return pret;
}

void Motor::afisareMotor(std::ostream& out) const
{
	out << "Pretul motorului este: " << pret << '\n';
	out << "Marca motorului este: " << marca << '\n';
}

std::ostream& operator<<(std::ostream& out, const Motor& motor)
{
	motor.afisareMotor(out);

	out << '\n';

	return out;
}

void interschimbareMotoare(Motor*& a, Motor*& b)
{
	Motor* aux = a;
	a = b;
	b = aux;
}

void sortareMotoareDupaPret(Motor**& motoare, const int& size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (motoare[i]->getPret() < motoare[j]->getPret())
			{
				interschimbareMotoare(motoare[i], motoare[j]);
			}
		}
	}
}

void afisareVectorMotoare(Motor**& motoare, const int& size, std::ostream& out)
{
	for (int j = 0; j < size; j++)
	{
		out << *motoare[j];
	}
}

void eliberareMemorieVectorMotoare(Motor**& motoare, const int& size)
{
	if (motoare == nullptr)
	{
		return;
	}

	for (int j = 0; j < size; j++)
	{
		if (motoare[j] == nullptr)
		{
			continue;
		}

		delete motoare[j];
	}

	delete[] motoare;
}