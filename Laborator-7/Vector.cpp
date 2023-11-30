#include "Vector.h"

template<typename TYPE>
Vector<TYPE>::Vector()
{
	size = 0;
	buffer = nullptr;
}

template<typename TYPE>
Vector<TYPE>::Vector(const int& size)
{
	this->size = size;
	this->buffer = new TYPE[size]{ 0 };
}

template<typename TYPE>
Vector<TYPE>::Vector(const int& size, const TYPE* buffer)
{
	this->size = size;

	if (buffer != nullptr && size > 0)
	{
		this->buffer = new TYPE[size];

		for (int j = 0; j < size; j++)
		{
			this->buffer[j] = buffer[j];
		}
	}
	else
	{
		this->buffer = nullptr;
	}
}

template<typename TYPE>
Vector<TYPE>::Vector(const Vector<TYPE>& vector)
{
	this->size = vector.size;

	if (vector.buffer != nullptr && vector.size > 0)
	{
		this->buffer = new TYPE[vector.size];

		for (int j = 0; j < vector.size; j++)
		{
			this->buffer[j] = vector.buffer[j];
		}
	}
	else
	{
		this->buffer = nullptr;
	}
}

template<typename TYPE>
Vector<TYPE>& Vector<TYPE>::operator=(const Vector<TYPE>& vector)
{
	if (this == &vector)
	{
		return *this;
	}

	if (this->buffer != nullptr)
	{
		delete[] this->buffer;
	}

	this->size = vector.size;

	if (vector.buffer != nullptr && vector.size > 0)
	{
		this->buffer = new TYPE[vector.size];

		for (int j = 0; j < vector.size; j++)
		{
			this->buffer[j] = vector.buffer[j];
		}
	}
	else
	{
		this->buffer = nullptr;
	}

	return *this;
}

template<typename TYPE>
Vector<TYPE>::~Vector()
{
	if (buffer != nullptr)
	{
		delete[] buffer;
	}
}

template<typename TYPE>
void Vector<TYPE>::sort()
{
	if (size == 0 || size == 1)
	{
		return;
	}

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (buffer[i] < buffer[j])
			{
				TYPE aux = buffer[i];
				buffer[i] = buffer[j];
				buffer[j] = aux;
			}
		}
	}
}

template<typename TYPE>
int Vector<TYPE>::getSize() const
{
	return size;
}

template<typename TYPE>
TYPE& Vector<TYPE>::operator[](const int& index) // o varianta de implementare, nu constituie obiectivul laboratorului
{
	try
	{
		if (index >= 0 && index < size)
		{
			return buffer[index];
		}
		else
		{
			throw std::out_of_range("Index out of bounds");
		}
	}
	catch (const std::out_of_range& exception)
	{
		std::cerr << "Error: " << exception.what() << ". Default value returned: ";
		static TYPE defaultValue = TYPE();
		return defaultValue;
	}
}

void TestVector()
{
	Vector<int> vectorIntregi(6);

	vectorIntregi[0] = -10;
	vectorIntregi[1] = 1;
	vectorIntregi[2] = 0;

	int dimInt = vectorIntregi.getSize();

	vectorIntregi.sort();

	Vector<double> vectorDoubleuri(8);

	vectorDoubleuri[0] = -10;
	vectorDoubleuri[1] = 1;
	vectorDoubleuri[2] = 0.2;

	int dimDouble = vectorDoubleuri.getSize();

	vectorDoubleuri.sort();

	Vector<Fractie> vectorFractii(5);

	vectorFractii[0] = Fractie(1, 2);
	vectorFractii[1] = Fractie(-3, 5);
	vectorFractii[2] = Fractie(10, 2);

	Vector<Fractie> copieFractii = vectorFractii;

	int dimFractii = vectorFractii.getSize();

	copieFractii.sort();

	Vector<NumarComplex> vectorNrComplexe(4);

	vectorNrComplexe[0] = NumarComplex(2, 5);
	vectorNrComplexe[1] = NumarComplex(1, 3);
	vectorNrComplexe[2] = NumarComplex(2, -2);
	vectorNrComplexe[3] = NumarComplex(-10, 7);

	int dimNrComplexe = vectorNrComplexe.getSize();

	vectorNrComplexe.sort();
}