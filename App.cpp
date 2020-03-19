#include "Tests.h"
#include <iostream>
#include <string.h>
#include "Repo.h"
#include "FamilyCosts.h"
using namespace std;

int main()
{	
	testsCosts();
	testRepoCosts();
	string option;
	Repo repoCosts;
	char* type1 = new char[10];
	int ziua, suma, nr = 0;
	while (true)
	{
		cout << "1.ADD" << endl << "2.GET ALL" << endl << "3.GET SIZE" << endl << "x.Iesire"<<endl;
		cout << "optiunea : ";
		cin >> option;
		if (option == "1")
		{
			cout << "ziua : "; cin >> ziua;
			cout << "suma : "; cin >> suma;
			cout << "tipul : "; cin >> type1;
			Costs c(ziua, suma, type1);
			repoCosts.add(c);
		}
		else if (option == "2")
		{
			nr = repoCosts.getSize();
			for (int i = 0; i < nr; i++)
				cout << repoCosts.show()[i] << endl;
		}
		else if (option == "3")
		{
			cout << repoCosts.getSize() << endl;
		}
		else break;
	}
	return 0;
}
