#pragma once
#include <string>
#include <iostream>
#pragma warning (disable : 4996)

class Haina
{
protected:

	float pret;
	char* material;

public:

	Haina();
	Haina(const float& pret, const char* material);
	Haina(const Haina& haina);
	Haina& operator=(const Haina& haina);
	~Haina();

	float getPret() const;

	friend std::istream& operator>>(std::istream& in, Haina& haina);
	friend std::ostream& operator<<(std::ostream& out, const Haina& haina);
};