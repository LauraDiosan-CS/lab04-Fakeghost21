

#pragma once

#include <ostream>

using namespace std;



class Costs

{

private:

	int day;

	int sum,id;

	char* type;

public:

	Costs();

	Costs(int day, int sum, int id,char* type);

	Costs(const Costs& c);

	~Costs();

	int getDay();

	int getSum();

	int getId();

	char* getType();

	void setDay(int day);

	void setSum(int sum);

	void setId(int id);

	void setType(char* type);

	Costs& operator=(const Costs& c);

	bool operator==(const Costs& c);

	friend ostream& operator<<(ostream& os, const Costs& c);

};