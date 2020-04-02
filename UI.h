#pragma once
#include "FamilyCosts.h"
#include "Service.h"
#include <vector>

class UI {
private:
	Costs cost[101];
	Service service;
	int n;
public:
	UI();
	~UI();
	void showConsole();
	void menu();
	void add(string cmd);
	void del(string cmd);
	void update();
	void show(string cmd);
	void sumaTip(string cmd);
	void filtrare(string cmd);
	void save(const vector<Costs>&);
};