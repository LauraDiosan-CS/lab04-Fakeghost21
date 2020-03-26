#include "Tests.h"
#include "FamilyCosts.h"
#include "Repo.h"
#include "Service.h"
#include <string.h>
#include <cassert>
#include <iostream>

void testsCosts()
{
	char* type1 = new char[10];
	char* type2 = new char[10];
	strcpy_s(type1, strlen("Transport") + 1, "Transport");
	strcpy_s(type2, strlen("Mancare") + 1, "Mancare");
	Costs c1(15, 1000, 2100, type1);
	Costs c2(28, 4100, 31499, type2);
	assert(c1.getDay() == 15);
	assert(c2.getSum() == 4100);
	assert(strcmp(c1.getType(), "Transport") == 0);
	c1.setId(100);
	c1.setDay(10);
	c2.setType(type1);
	c2.setSum(33);
	assert(c1.getId() == 100);
	assert(c1.getDay() == 10);
	assert(strcmp(c2.getType(), type1) == 0);
	assert(c2.getSum() == 33);
	cout << "Tests for Costs are ok!" << endl;
}

void testRepoCosts()
{
	char* type1 = new char[10];
	char* type2 = new char[10];
	strcpy_s(type1, strlen("Menaj") + 1, "Menaj");
	strcpy_s(type2, strlen("Carti") + 1, "Carti");
	Costs c1(5, 65, 31233, type1);
	Costs c2(12, 13, 213335, type2);
	Repo repoCosts;
	repoCosts.add(c1);
	repoCosts.add(c2);
	assert(repoCosts.getSize() == 2);
	assert(repoCosts.show()[0] == c1);
	assert(repoCosts.show()[1] == c2);
	repoCosts.del(213335);
	assert(repoCosts.getSize() == 1);
	repoCosts.update(31233, c2);
	assert(repoCosts.show()[0] == c2);
	cout << "Tests for Repo Costs are ok!" << endl;
}

void testServiceCosts()
{
	char* type1 = new char[10];
	char* type2 = new char[10];
	strcpy_s(type1, strlen("Menaj") + 1, "Menaj");
	strcpy_s(type2, strlen("Carti") + 1, "Carti");
	Costs c1(5, 65, 123212, type1);
	Costs c2(12, 13, 3123, type2);
	Repo repoCosts;
	Service service;
	service.add(c1);
	service.add(c2);
	assert(service.getSize() == 2);
	assert(service.show()[0] == c1);
	assert(service.show()[1] == c2);
	service.del(3123);
	assert(service.getSize() == 1);
	service.update(123212, c2);
	assert(service.show()[0] == c2);
	cout << "Tests for Service Costs are ok!" << endl;
}