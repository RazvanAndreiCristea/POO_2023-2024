#pragma once
#include <string>
#include <iostream>
#pragma warning (disable : 4996)

class Oras
{
protected:

	char* primar;
	int numarBlocuri;

public:

	Oras();
	Oras(const char* primar, const int& numarBlocuri);
	Oras(const Oras& oras);
	Oras& operator=(const Oras& oras);
	~Oras();

	friend std::ostream& operator<<(std::ostream& out, const Oras& oras);
};