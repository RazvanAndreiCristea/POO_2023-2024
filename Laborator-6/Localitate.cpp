#include "Localitate.h"

Localitate::Localitate()
{
	numarLocuitori = 0;
	salariiLocuitori = nullptr;
}

Localitate::Localitate(const int& numarLocuitori, const float* salariiLocuitori)
{
	this->numarLocuitori = numarLocuitori;

	if (salariiLocuitori != nullptr && numarLocuitori > 0)
	{
		this->salariiLocuitori = new float[numarLocuitori];

		for (int j = 0; j < numarLocuitori; j++)
		{
			this->salariiLocuitori[j] = salariiLocuitori[j];
		}
	}
	else
	{
		this->salariiLocuitori = nullptr;
	}
}

Localitate::Localitate(const Localitate& localitate)
{
	this->numarLocuitori = localitate.numarLocuitori;

	if (localitate.salariiLocuitori != nullptr && localitate.numarLocuitori > 0)
	{
		this->salariiLocuitori = new float[localitate.numarLocuitori];

		for (int j = 0; j < localitate.numarLocuitori; j++)
		{
			this->salariiLocuitori[j] = localitate.salariiLocuitori[j];
		}
	}
	else
	{
		this->salariiLocuitori = nullptr;
	}
}

Localitate& Localitate::operator=(const Localitate& localitate)
{
	if (this == &localitate)
	{
		return *this;
	}

	if (this->salariiLocuitori != nullptr)
	{
		delete[] this->salariiLocuitori;
	}

	this->numarLocuitori = localitate.numarLocuitori;

	if (localitate.salariiLocuitori != nullptr && localitate.numarLocuitori > 0)
	{
		this->salariiLocuitori = new float[localitate.numarLocuitori];

		for (int j = 0; j < localitate.numarLocuitori; j++)
		{
			this->salariiLocuitori[j] = localitate.salariiLocuitori[j];
		}
	}
	else
	{
		this->salariiLocuitori = nullptr;
	}

	return *this;
}

Localitate::~Localitate()
{
	if (salariiLocuitori != nullptr)
	{
		delete[] salariiLocuitori;
	}
}

float Localitate::getSalariuMediuPerLocalitate() const
{
	float sumaSalarii = 0.0f;
	float salariuMediuPerLocalitate = 0.0f;

	for (int j = 0; j < numarLocuitori; j++)
	{
		sumaSalarii += salariiLocuitori[j];
	}

	salariuMediuPerLocalitate = sumaSalarii / numarLocuitori;

	return salariuMediuPerLocalitate;
}

std::ostream& operator<<(std::ostream& out, const Localitate& localitate)
{
	out << "Numarul de locuitori din localitate este: " << localitate.numarLocuitori << '\n';

	if (localitate.salariiLocuitori != nullptr && localitate.numarLocuitori > 0)
	{
		out << "Salariile locuitorilor din localitate sunt: ";

		for (int j = 0; j < localitate.numarLocuitori; j++)
		{
			out << localitate.salariiLocuitori[j] << "  ";
		}

		out << "\n\n";
	}
	else
	{
		out << "Nu exista salarii pentru locuitorii din localitate\n\n";
	}

	return out;
}