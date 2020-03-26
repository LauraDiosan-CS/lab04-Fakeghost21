#pragma once
#include "FamilyCosts.h"
#include "Repo.h"

class Service
{
private:
	Costs c[101];
	Repo repo;
	int n;
public:
	Service();
	~Service();
	void add(Costs c);
	void del(int id);
	void update(int id, Costs c2);
	Costs* show();
	int getSize();
};