#include "Service.h"
#include <cstddef>
#include <vector>
using namespace std;
/*
	Creates an object of Service type.
*/
Service::Service()
{
	this->n = 0;
}
/*
	Destroy an object of Service type.
*/
Service::~Service()
{
	this->n = 0;
}
/*
	Returns the size of the Costs vector.
*/
int Service::getSize()
{
	return repo.getSize();
}
/*
	Adds a new object of type Costs.
*/
void Service::add(Costs c)
{
	repo.add(c);
}
/*
	Deletes by id an object of type Costs.
*/
void Service::delZi(Costs result[], int& resultLen,int day)
{	
	int nr = this->getSize();
	for (int i = 0; i < nr; i++)
		if (this->show()[i].getDay() == day)
		{
			result[resultLen++] = this->show()[i];
		}
}
/*
	Find an object by id and it is updated with another Costs object.
*/
void Service::update(int id, Costs c2)
{
	repo.update(id, c2);
}
/*
	It returns all the Costs object.
*/
Costs* Service::show()
{
	return repo.show();
}

/*
	It deletes all the objects that have the value of the day parameter in between function parameters.
*/
void Service::delZile(int day1, int day2)
{	
	int nr = repo.getSize(),pos = 0;
	Costs *v = new Costs[nr];
	for (int i = 0; i < nr; i++)
		if (this->show()[i].getDay() >= day1 and this->show()[i].getDay() <= day2)
		{
			v[pos++] = this->show()[i];
		}
	if(v)
		for (int i = 0; i < pos; i++)
		{	
		repo.del(v[i]);
		}
	delete[]v;
}

/*
	It is used to delete 
*/
void Service::del(char* type,int g,int value,int day)
{
	Costs v[101];
	int vLen = 0;
	if (g == 1) this->obtTip(type, v, vLen);
	if (g == 0) this->obtNotType(type, v, vLen);
	if (g == 11) this->delNotEqualValue(type, v, vLen, value);
	if (g == -1) this->delGreaterAndEqualValue(type, v, vLen, value);
	if (g == 2) this->delZi(v, vLen, day);
	for (int i = 0; i < vLen; i++)
	{
		repo.del(v[i]);
	}
}

void Service::delNotEqualValue(char* type, Costs result[], int& resultLen, int value)
{
	int nr = repo.getSize();
	for (int i = 0; i < nr; i++)
		if (strcmp(this->show()[i].getType(), type) != 0 or this->show()[i].getSum() != value)
		{
			result[resultLen++] = this->show()[i];
		}
}

void Service::delGreaterAndEqualValue(char* type, Costs result[], int& resultLen,int value)
{
	int nr = repo.getSize();
	for (int i = 0; i < nr; i++)
		if (strcmp(this->show()[i].getType(), type) != 0 or this->show()[i].getSum() >= value)
		{
			result[resultLen++] = this->show()[i];
		}
}


int Service::sumaTip(char* type)
{
	int nr = repo.getSize(), pos = 0;
	int sum = 0;
	Costs v[101];
	int vLen = 0;
	this->obtTip(type, v, vLen);
	for (int i = 0; i < vLen; i++)
			sum += v[i].getSum();
	return sum;
}

void Service::sumeZi(int v[])
{
	int nr = repo.getSize();
	for (int i = 0; i < nr; i++)
	{
		v[this->show()[i].getDay()] += this->show()[i].getSum();
	}

}

void Service::ordonareDescrescatoare(int v[])
{
	int aux, i, j;
	for(i=1;i<31;i++)
		for(j = i+1;j<=31;j++)
			if(v[i]<v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
}

int Service::sortareMancare(char* type,int v[],int s)
{
	int nr = repo.getSize();
	for (int i = 0; i < nr; i++)
		if (strcmp(this->show()[i].getType(),type) == 0)
			v[s++] = this->show()[i].getSum();
	return s;
}

void Service::ordonareCrescatoare(int v[],int n)
{
	int aux, i, j;
	for (i = 0; i < n-1; i++)
		for (j = i + 1; j <= n-1; j++)
			if (v[i] > v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
}

void Service::obtTip(char* type,Costs v[],int& vLen)
{
	int nr = repo.getSize();
	for (int i = 0; i < nr; i++)
		if (strcmp(this->show()[i].getType(), type) == 0)
		{
			v[vLen++] = this->show()[i];
		}
}

void Service::obtNotType(char* type, Costs v[], int& vLen)
{
	int nr = repo.getSize();
	for (int i = 0; i < nr; i++)
		if (strcmp(this->show()[i].getType(), type) != 0)
		{
			v[vLen++] = this->show()[i];
		}
}

void Service::deleteNormal(Costs c)
{
	repo.del(c);
}

void Service::updateCosts(const vector<vector<Costs>>&v)
{
	repo.updateCosts(v);
}