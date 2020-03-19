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
	Costs* show();
	int getSize();
};
