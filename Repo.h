#pragma once
#include "FamilyCosts.h"
#include <vector>
class Repo
{
private:
	Costs cost[101];
	int n;
public:
	Repo();
	~Repo();
	void add(Costs c);
	void del(Costs c);
	void update(int c1, Costs c2);
	Costs* show();
	int getSize();
	void updateCosts(const vector<vector<Costs>>&);
};
