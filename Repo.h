#pragma once
#include "FamilyCosts.h"

class Repo
{
private:
	Costs cost[101];
	int n;
public:
	Repo();
	~Repo();
	void add(Costs c);
	void del(int id);
	void update(int c1, Costs c2);
	Costs* show();
	int getSize();
};
