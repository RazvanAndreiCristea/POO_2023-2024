#include "Lista-Dubla.h"

template <typename DATA_TYPE>
NodDublu<DATA_TYPE>::NodDublu(const DATA_TYPE& info)
{
	this->info = info;
	this->next = nullptr;
	this->prev = nullptr;
}

template <typename DATA_TYPE>
ListaDubla<DATA_TYPE>::ListaDubla()
{
	size = 0;
	first = nullptr;
	last = nullptr;
}

template<typename DATA_TYPE>
ListaDubla<DATA_TYPE>::ListaDubla(const ListaDubla<DATA_TYPE>& lista)
{
	if (!lista.isEmptyList())
	{
		this->size = lista.size;

		NodDublu<DATA_TYPE>* current = lista.first;

		while (current != nullptr)
		{
			NodDublu<DATA_TYPE>* noulNod = new(std::nothrow)NodDublu<DATA_TYPE>(current->info);

			if (noulNod == nullptr)
			{
				break;
			}

			if (this->isEmptyList())
			{
				this->first = noulNod;
				this->last = noulNod;
			}
			else
			{
				noulNod->prev = this->last;

				if (this->last != nullptr)
				{
					this->last->next = noulNod;
				}

				this->last = noulNod;
			}

			current = current->next;
		}
	}
	else
	{
		this->size = 0;
		this->first = nullptr;
		this->last = nullptr;
	}
}

template<typename DATA_TYPE>
ListaDubla<DATA_TYPE>& ListaDubla<DATA_TYPE>::operator=(const ListaDubla<DATA_TYPE>& lista)
{
	if (this == &lista)
	{
		return *this;
	}

	if (!this->isEmptyList())
	{
		while (first != nullptr)
		{
			NodDublu<DATA_TYPE>* aux = first;
			this->first = this->first->next;
			delete aux;
			this->size--;
		}

		this->last = nullptr;
	}

	if (!lista.isEmptyList())
	{
		this->size = lista.size;

		NodDublu<DATA_TYPE>* current = lista.first;

		while (current != nullptr)
		{
			NodDublu<DATA_TYPE>* noulNod = new(std::nothrow)NodDublu<DATA_TYPE>(current->info);

			if (noulNod == nullptr)
			{
				break;
			}

			if (this->isEmptyList())
			{
				this->first = noulNod;
				this->last = noulNod;
			}
			else
			{
				noulNod->prev = this->last;

				if (this->last != nullptr)
				{
					this->last->next = noulNod;
				}

				this->last = noulNod;
			}

			current = current->next;
		}
	}
	else
	{
		this->size = 0;
		this->first = nullptr;
		this->last = nullptr;
	}

	return *this;
}

template <typename DATA_TYPE>
ListaDubla<DATA_TYPE>::~ListaDubla()
{
	while (first != nullptr)
	{
		NodDublu<DATA_TYPE>* aux = first;
		first = first->next;
		delete aux;
		size--;
	}

	last = nullptr;
}

template <typename DATA_TYPE>
void ListaDubla<DATA_TYPE>::pushFront(const DATA_TYPE& info)
{
	NodDublu<DATA_TYPE>* noulNod = new(std::nothrow) NodDublu<DATA_TYPE>(info);

	if (noulNod == nullptr)
	{
		return;
	}

	if (isEmptyList())
	{
		first = noulNod;
		last = noulNod;
		size++;
	}
	else
	{
		noulNod->next = first;

		if (first != nullptr)
		{
			first->prev = noulNod;
		}

		first = noulNod;
		size++;
	}
}

template <typename DATA_TYPE>
void ListaDubla<DATA_TYPE>::pushBack(const DATA_TYPE& info)
{
	NodDublu<DATA_TYPE>* noulNod = new(std::nothrow) NodDublu<DATA_TYPE>(info);

	if (noulNod == nullptr)
	{
		return;
	}

	if (isEmptyList())
	{
		first = noulNod;
		last = noulNod;
		size++;
	}
	else
	{
		noulNod->prev = last;

		if (last != nullptr)
		{
			last->next = noulNod;
		}

		last = noulNod;
		size++;
	}
}

template <typename DATA_TYPE>
void ListaDubla<DATA_TYPE>::popFront()
{
	if (first == nullptr)
	{
		return;
	}

	NodDublu<DATA_TYPE>* nodDeSters = first;

	if (first == last)
	{
		delete nodDeSters;
		first = nullptr;
		last = nullptr;
		size--;
	}
	else
	{
		first = first->next;
		first->prev = nullptr;
		size--;
		delete nodDeSters;
	}
}

template<typename DATA_TYPE>
void ListaDubla<DATA_TYPE>::popBack()
{
	if (last == nullptr)
	{
		return;
	}

	NodDublu<DATA_TYPE>* nodDeSters = last;

	if (last == first)
	{
		delete nodDeSters;
		first = nullptr;
		last = nullptr;
		size--;
	}
	else
	{
		last = last->prev;
		last->next = nullptr;
		size--;
		delete nodDeSters;
	}
}

template<typename DATA_TYPE>
void ListaDubla<DATA_TYPE>::sort()
{
	if (first == nullptr || first->next == nullptr)
	{
		return;
	}

	NodDublu<DATA_TYPE>* current = nullptr;

	bool sorted = false;

	while (sorted == false)
	{
		sorted = true;

		current = first;

		while (current->next != nullptr)
		{
			if (current->info > current->next->info)
			{
				DATA_TYPE content = current->info;
				current->info = current->next->info;
				current->next->info = content;
				sorted = false;
			}

			current = current->next;
		}
	}
}

template<typename DATA_TYPE>
unsigned int ListaDubla<DATA_TYPE>::getSize() const
{
	return size;
}

template<typename DATA_TYPE>
bool ListaDubla<DATA_TYPE>::isEmptyList() const
{
	return (this->first == nullptr && this->last == nullptr);
}

template<typename DATA_TYPE>
void ListaDubla<DATA_TYPE>::showFirstNode(std::ostream& out) const
{
	if (first == nullptr)
	{
		out << "Primul nod al listei nu exista nu avem ce afisa!\n";
		return;
	}

	out << first->info << "\n\n";
}

template<typename DATA_TYPE>
void ListaDubla<DATA_TYPE>::showLastNode(std::ostream& out) const
{
	if (last == nullptr)
	{
		out << "Ultimul nod al listei nu exista nu avem ce afisa!\n";
		return;
	}

	out << last->info << "\n\n";
}

template<typename DATA_TYPE>
void ListaDubla<DATA_TYPE>::showListFromFirtsToLast(std::ostream& out) const
{
	if (isEmptyList())
	{
		out << "Lista este goala nu avem ce afisa!\n";
		return;
	}

	NodDublu<DATA_TYPE>* nodCurent = first;

	while (nodCurent != nullptr)
	{
		out << nodCurent->info << '\n';
		nodCurent = nodCurent->next;
	}
}

template<typename DATA_TYPE>
void ListaDubla<DATA_TYPE>::showListFromLastToFirst(std::ostream& out) const
{
	if (isEmptyList())
	{
		out << "Lista este goala nu avem ce afisa!\n";
		return;
	}

	NodDublu<DATA_TYPE>* nodCurent = last;

	while (nodCurent != nullptr)
	{
		out << nodCurent->info << '\n';
		nodCurent = nodCurent->prev;
	}
}

void TestLista()
{
	ListaDubla<int> listaIntregi;

	listaIntregi.pushBack(0);
	listaIntregi.pushFront(1);

	ListaDubla<int> copieListaIntregi = listaIntregi;
	copieListaIntregi = listaIntregi;

	listaIntregi.sort();

	listaIntregi.showListFromFirtsToLast(std::cout);
	listaIntregi.showListFromLastToFirst(std::cout);

	listaIntregi.getSize();

	listaIntregi.showFirstNode(std::cout);
	listaIntregi.showLastNode(std::cout);

	listaIntregi.popFront();
	listaIntregi.popBack();

	listaIntregi.showFirstNode(std::cout);
	listaIntregi.showLastNode(std::cout);

	// Lista double-uri

	ListaDubla<double> listaDouble;

	listaDouble.pushBack(0);
	listaDouble.pushFront(1);

	ListaDubla<double> copieListaDouble = listaDouble;
	copieListaDouble = listaDouble;

	listaDouble.sort();

	listaDouble.showListFromFirtsToLast(std::cout);
	listaDouble.showListFromLastToFirst(std::cout);

	listaDouble.getSize();

	listaDouble.showFirstNode(std::cout);
	listaDouble.showLastNode(std::cout);

	listaDouble.popFront();
	listaDouble.popBack();

	listaDouble.showFirstNode(std::cout);
	listaDouble.showLastNode(std::cout);

	// Lista Puncte

	ListaDubla<Punct> listaPuncte;

	listaPuncte.pushBack(Punct(4, 5));
	listaPuncte.pushFront(Punct(6, 3));

	ListaDubla<Punct> copieListaPuncte = listaPuncte;
	copieListaPuncte = listaPuncte;

	listaPuncte.sort();

	listaPuncte.showListFromFirtsToLast(std::cout);
	listaPuncte.showListFromLastToFirst(std::cout);

	listaPuncte.getSize();

	listaPuncte.showFirstNode(std::cout);
	listaPuncte.showLastNode(std::cout);

	listaPuncte.popFront();
	listaPuncte.popBack();

	listaPuncte.showFirstNode(std::cout);
	listaPuncte.showLastNode(std::cout);

	// Lista Dreptunghiuri

	ListaDubla<Dreptunghi> listaDreptunghiuri;

	listaDreptunghiuri.pushBack(Dreptunghi(3, 2));
	listaDreptunghiuri.pushFront(Dreptunghi(6, 4));

	ListaDubla<Dreptunghi> copieListaDreptunghiuri = listaDreptunghiuri;
	copieListaDreptunghiuri = listaDreptunghiuri;

	listaDreptunghiuri.sort();

	listaDreptunghiuri.showListFromFirtsToLast(std::cout);
	listaDreptunghiuri.showListFromLastToFirst(std::cout);

	listaDreptunghiuri.getSize();

	listaDreptunghiuri.showFirstNode(std::cout);
	listaDreptunghiuri.showLastNode(std::cout);

	listaDreptunghiuri.popFront();
	listaDreptunghiuri.popBack();

	listaDreptunghiuri.showFirstNode(std::cout);
	listaDreptunghiuri.showLastNode(std::cout);
}