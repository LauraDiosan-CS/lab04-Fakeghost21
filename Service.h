#pragma once
#include "FamilyCosts.h"
#include "Repo.h"
#include <map>
#include <vector>
using namespace std;

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
	void obtTip(char* type,Costs result[],int &resultLen);
	void obtNotType(char* type, Costs result[], int& resultLen);
	void delZi(Costs result[], int& resultLen,int day);
	void delZile(int day1, int day2);
	void del(char* type,int g,int value,int day);
	void delNotEqualValue(char* type, Costs result[], int& resultLen,int value);
	void delGreaterAndEqualValue(char* type, Costs result[], int& resultLen,int value);
	void deleteNormal(Costs c);
	void update(int id, Costs c2);
	int sumaTip(char* type);
	Costs* show();
	int getSize();
	void sumeZi(int v[]);
	void ordonareDescrescatoare(int v[]);
	void ordonareCrescatoare(int v[],int n);
	int sortareMancare(char* type,int v[],int n);
	void updateCosts(const vector<vector<Costs>>&);
};