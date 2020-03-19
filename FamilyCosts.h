#pragma once
#include <ostream>
using namespace std;

class Costs
{
private:
	int day;
	int sum;
	char* type;
public:
	Costs();
	Costs(int day, int sum, char* type);
	Costs(const Costs& c);
	~Costs();
	int getDay();
	int getSum();
	char* getType();
	void setDay(int day);
	void setSum(int sum);
	void setType(char* type);
	Costs& operator=(const Costs& c);
	bool operator==(const Costs& c);
	friend ostream& operator<<(ostream& os, const Costs& c);
};
