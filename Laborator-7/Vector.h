#pragma once
#include <iostream>
#include <exception>
#include "Fractie.h"
#include "NumarComplex.h"

template <typename TYPE>
class Vector
{
	int size;
	TYPE* buffer;

public:

	Vector();
	Vector(const int& size);
	Vector(const int& size, const TYPE* buffer);
	Vector(const Vector& vector);
	Vector& operator=(const Vector& vector);
	~Vector();

	void sort();
	int getSize() const;

	TYPE& operator[](const int& index);
};