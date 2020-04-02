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
	repoCosts.del(c2);
	assert(repoCosts.getSize() == 1);
	repoCosts.update(31233, c2);
	assert(repoCosts.show()[0] == c2);
	cout << "Tests for Repo Costs are ok!" << endl;
}

void testServiceCosts()
{
	char* type1 = new char[10];
	char* type2 = new char[10];
	char* type3 = new char[10];
	char* type4 = new char[10];
	char* type5 = new char[10];
	char* type6 = new char[10];
	char* type7 = new char[10];
	char* type8 = new char[10];
	char* type9 = new char[10];
	strcpy_s(type1, strlen("Menaj") + 1, "Menaj");
	strcpy_s(type2, strlen("Carti") + 1, "Carti");
	strcpy_s(type3, strlen("Mancare") + 1, "Mancare");
	strcpy_s(type4, strlen("Curent") + 1, "Curent");
	strcpy_s(type5, strlen("Mancare") + 1, "Mancare");
	strcpy_s(type6, strlen("Haine") + 1, "Haine");
	strcpy_s(type7, strlen("Transport") + 1, "Transport");
	strcpy_s(type8, strlen("Transport") + 1, "Transport");
	strcpy_s(type9, strlen("Mancare") + 1, "Mancare");
	Costs c1(10, 65, 123212, type1);
	Costs c2(2, 130, 3123, type2);
	Costs c3(31, 130, 12, type3);
	Costs c4(4, 13, 31, type4);
	Costs c5(4, 130, 312, type5);
	Costs c6(5, 320, 1, type6);
	Costs c7(5, 100, 3, type7);
	Costs c8(5, 65, 12321, type8);
	Costs c9(5, 13, 31230, type9);

	Repo repoCosts;
	Service service;
	service.add(c1);
	service.add(c2);
	service.add(c3);
	service.add(c4);
	service.add(c5);
	service.add(c6);
	service.add(c7);
	service.add(c8);
	service.add(c9);
	assert(service.getSize() == 9);
	assert(service.show()[0] == c1);
	assert(service.show()[1] == c2);
	assert(service.show()[2] == c3);
	assert(service.show()[3] == c4);
	assert(service.show()[4] == c5);
	assert(service.show()[5] == c6);
	assert(service.show()[6] == c7);
	assert(service.show()[7] == c8);
	assert(service.show()[8] == c9);

	assert(service.show()[1].getId() == 3123);
	assert(service.show()[1].getDay() == 2);
	assert(service.show()[1].getSum() == 130);
	assert(strcmp(service.show()[1].getType(),type2) == 0);

	service.del(type5, 1, 0, 0);
	assert(service.getSize() == 6);

	service.del(type7, 0, 0, 0);
	assert(service.getSize() == 2);
	assert(strcmp(service.show()[0].getType(),type7) == 0);
	assert(strcmp(service.show()[1].getType(), type7) == 0);

	service.add(c1);
	service.add(c2);
	service.add(c3);
	service.add(c4);
	service.add(c5);
	service.add(c6);
	service.del(type3, 11, 130, 0);
	assert(service.getSize() == 2);
	assert(strcmp(service.show()[0].getType(), type3) == 0);
	assert(strcmp(service.show()[1].getType(), type3) == 0);
	assert(service.show()[0].getSum() == 130);
	assert(service.show()[1].getSum() == 130);

	service.add(c6);
	service.add(c7);
	service.add(c8);
	service.add(c9);
	service.del(type7, -1, 100, 0);
	assert(service.getSize() == 1);
	assert(service.show()[0] == c8);

	service.add(c1);
	service.add(c2);
	service.add(c3);
	service.add(c4);
	service.add(c5);
	service.add(c6);
	service.add(c7);
	service.del(type1, 2, 0, 5);
	assert(service.getSize() == 5);
	assert(service.show()[0].getDay() != 5);
	assert(service.show()[1].getDay() != 5);
	assert(service.show()[2].getDay() != 5);
	assert(service.show()[3].getDay() != 5);
	assert(service.show()[4].getDay() != 5);

	service.add(c6);
	service.add(c7);
	service.add(c8);
	service.add(c9);
	assert(service.getSize() == 9);

	service.delZile(2, 9);
	assert(service.getSize() == 2);
	assert(service.show()[0] == c1);
	assert(service.show()[0].getDay() == 10);
	assert(service.show()[1] == c3);
	assert(service.show()[1].getDay() == 31);

	service.add(c4);
	service.add(c5);
	service.add(c6);
	service.add(c7);
	service.add(c8);
	service.add(c9);
	assert(service.sumaTip(type3) == 273);
	cout << "Tests for Service Costs are ok!" << endl;

}