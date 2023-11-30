#pragma once
#include <iostream>

class Fractie
{
	double numarator;
	double numitor;

public:

	Fractie(const double& numarator = 0, const double& numitor = 1);

	bool operator<(const Fractie& fractie) const;

	friend std::ostream& operator<<(std::ostream& out, const Fractie& fractie);
};