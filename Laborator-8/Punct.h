#pragma once
#include <iostream>

class Punct
{
	double x;
	double y;

public:

	Punct(const double& x = 0, const double& y = 0);
	bool operator>(const Punct& punct) const;
	friend std::ostream& operator<<(std::ostream& out, const Punct& punct);
};