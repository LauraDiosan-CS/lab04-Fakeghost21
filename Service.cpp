#include "Service.h"
#include <cstddef>
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
void Service::del(int id)
{
	repo.del(id);
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