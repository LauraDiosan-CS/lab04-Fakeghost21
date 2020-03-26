#pragma once
#include "FamilyCosts.h"
#include "Service.h"

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
	void add();
	void del();
	void update();
	void show();

};