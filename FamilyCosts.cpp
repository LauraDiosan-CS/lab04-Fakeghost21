
#include "FamilyCosts.h"

#include <cstddef>

#include <string.h>

#include <ostream>

#include <iostream>

using namespace std;



/*

	Default operator which sets the day and sum to 0 and type to NULL.

*/

Costs::Costs()

{

	this->day = 0;

	this->sum = 0;

	this->id = 0;

	this->type = NULL;

}



/*

	Operator which uses parameters to sets values for a new object.

*/

Costs::Costs(int day, int sum, int id, char* type)

{

	this->day = day;

	this->sum = sum;

	this->id = id;

	this->type = new char[strlen(type) + 1];

	strcpy_s(this->type, strlen(type) + 1, type);

}



/*

	Operator which uses another object of type Costs to sets the values of another new object of the same type.

*/

Costs::Costs(const Costs& c)

{

	this->day = c.day;

	this->sum = c.sum;

	this->id = c.id;

	this->type = new char[strlen(c.type) + 1];

	strcpy_s(this->type, strlen(c.type) + 1, c.type);

}



/*

	Destructor.

*/

Costs::~Costs()

{

	this->day = 0;

	this->sum = 0;

	this->id = 0;

	if (this->type != NULL)

	{

		delete[] this->type;

		this->type = NULL;

	}

}



int Costs::getDay()
{
	return this->day;
}



int Costs::getSum()
{
	return this->sum;
}

int Costs::getId()
{
	return this->id;
}


char* Costs::getType()
{
	return this->type;
}



void Costs::setDay(int day)
{
	this->day = day;
}



void Costs::setSum(int sum)
{
	this->sum = sum;
}

void Costs::setId(int id)
{
	this->id = id;
}

void Costs::setType(char* type)
{
	if (this->type != NULL)

	{

		delete[] this->type;

		this->type = NULL;

	}

	this->type = new char[strlen(type) + 1];

	strcpy_s(this->type, strlen(type) + 1, type);
}



/*

	The operator "=" assign all values of an object of a type Costs to another of the same type.

*/

Costs& Costs::operator=(const Costs& c)

{

	this->setDay(c.day);

	this->setSum(c.sum);

	this->setId(c.id);

	this->setType(c.type);

	return *this;

}



/*

	The operator "==" compare all the values of two object of a type Costs.

*/

bool Costs::operator==(const Costs& c)

{

	return (this->day == c.day) && (this->sum == c.sum) && (this->id == c.id) && (strcmp(this->type, c.type) == 0);

}

ostream& operator<<(ostream& os, const Costs& c)

{

	os <<"Id : "<< c.id<< endl << "Ziua: " << c.day << endl << "Suma: " << c.sum << endl << "Tipul: " << c.type << endl;

	return os;

}
