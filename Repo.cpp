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
void Repo::del(Costs c)
{
	int sum, pos, nr;
	char* type = new char[10];
	nr = this->getSize();
	for (int i = 0; i < nr; i++)
		if (this->show()[i] == c)
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

void Repo::updateCosts(const vector<vector<Costs>>& v)
{	
	if (v.size() > 1)
	{
		int nr = v[v.size() - 2].size();
		if (nr > this->n)
		{
			for (int i = 0; i < nr; i++)
				this->show()[i] = v[v.size() - 2][i];
			this->n = nr;
		}
		else this->n = nr;
	}
	else this->n = 0;
}
