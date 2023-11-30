#pragma once
#include <iostream>
#include <cmath>

class NumarComplex
{
	double real;
	double imaginar;

public:

	NumarComplex(const double& real = 0, const double& imaginar = 0);

	bool operator<(const NumarComplex& z) const;

	friend std::ostream& operator<<(std::ostream& out, const NumarComplex& z);
};