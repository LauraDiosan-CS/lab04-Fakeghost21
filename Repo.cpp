#include "Repo.h"
#include <cstddef>
/*
	Constructor.
*/
Repo::Repo()
{
	this->n = 0;
}
/*
	Destructor.
*/
Repo::~Repo()
{
	this->n = 0;
}

int Repo::getSize()
{
	return this->n;
}
void Repo::add(Costs c)
{
	this->cost[this->n++] = c;
}
Costs* Repo::show()
{
	return this->cost;
}
void Repo::del(int id)
{
	int day, sum, pos, nr;
	char* type = new char[10];
	nr = this->getSize();
	for (int i = 0; i < nr; i++)
		if (this->show()[i].getId() == id)
		{
			pos = i;
			break;
		}
	for (int i = pos; i < nr - 1; i++)
		this->show()[i] = this->show()[i + 1];
	this->n--;
}

void Repo::update(int id, Costs c2)
{
	for (int i = 0; i < this->getSize(); i++)
		if (this->show()[i].getId() == id)
		{

			this->show()[i] = c2;
			break;
		}
}
