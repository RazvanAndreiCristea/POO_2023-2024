#pragma once
#include "Punct.h"
#include "Dreptunghi.h"

template <typename DATA_TYPE>
class ListaDubla;

template <typename DATA_TYPE>
class NodDublu
{
	DATA_TYPE info;
	NodDublu* next;
	NodDublu* prev;

public:

	NodDublu(const DATA_TYPE& info);
	friend class ListaDubla<DATA_TYPE>;
};

template <typename DATA_TYPE>
class ListaDubla
{
	unsigned int size;
	NodDublu<DATA_TYPE>* first;
	NodDublu<DATA_TYPE>* last;

public:

	ListaDubla();
	ListaDubla(const ListaDubla& lista); // cerinta bonus
	ListaDubla& operator=(const ListaDubla& lista); // cerinta bonus
	~ListaDubla();

	void pushFront(const DATA_TYPE& info);
	void pushBack(const DATA_TYPE& info);

	void popFront();
	void popBack();

	void sort();
	unsigned int getSize() const;

	bool isEmptyList() const;

	void showFirstNode(std::ostream& out) const;
	void showLastNode(std::ostream& out) const;

	void showListFromFirtsToLast(std::ostream& out) const;
	void showListFromLastToFirst(std::ostream& out) const;
};