#include "UI.h"
#include <cstddef>
#include <iostream> 
#include <cstring>

UI::UI()
{
	this->n = 0;
}

UI::~UI()
{
	this->n = 0;
}

void UI::menu()
{
	cout << "1.ADD\n" 
		<< "2.DELETE\n" 
		<< "3.UPDATE\n"
		<< "4.SHOW\n"
		<< "x.Iesire\n";
}

void UI::showConsole()
{
	int option;

	while (true)
	{
		menu();
		cout << "Option : ", cin >> option;
		if (option == 1)
		{
			add();
		}
		else if (option == 2)
		{
			del();
		}
		else if (option == 3)
		{
			update();
		}
		else if (option == 4)
		{
			show();
		}
		else break;
	}
}

void UI::add()
{
	int day, sum, id;
	char* type;
	char another_type[100];
	cout << "id-ul : "; cin >> id;
	cout << "ziua : "; cin >> day;
	cout << "suma : "; cin >> sum;
	cout << "tipul : "; cin >> another_type;
	type = new char[strlen(another_type) + 1];
	strcpy_s(type, strlen(another_type) + 1, another_type);
	Costs c(day, sum, id, type);
	service.add(c);
}

void UI::del()
{
	char another_type[100];
	int day, sum, id;
	char* type;
	cout << "Costurile familie pe care doriti sa o stergeti : ";
	cout << "id-ul : "; cin >> id;
	service.del(id);
}

void UI::update()
{
	char* type1,*type2;
	char another_type1[100], another_type2[100];
	int day, sum, day2, sum2, id, id2;
	cout << " Cheltuiala pe care doriti sa o puneti la curent :\n ";
	cout << "id-ul : "; cin >> id;

	cout << "Noile date : \n";
	
	cout << "ziua : "; cin >> day2;
	cout << "suma : "; cin >> sum2;
	cout << "tipul : "; cin >> another_type2;
	type2 = new char[strlen(another_type2) + 1];
	strcpy_s(type2, strlen(another_type2) + 1, another_type2);
	Costs c2(day2, sum2, id, type2);
	service.update(id, c2);
	cout << "Cheltuiala pusa la curent!\n";
}

void UI::show()
{
	int nr = service.getSize();
	for (int i = 0; i < nr; i++)
		cout << service.show()[i] << endl;
}


