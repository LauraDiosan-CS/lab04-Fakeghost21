#include "UI.h"
#include <cstddef>
#include <iostream> 
#include <cstring>
#include <string.h>
#include <string>
#include <ctime>
#include <map>
#include <vector>

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
	cout << "1.Scrie \"add {id} {tip} {suma} {zi - optional} \"pentru a adauga un cost de familie.\n" 
		<< "2.Pentru a sterge unul sau mai multe costuri de familie : \n"
		<< "		Scrie \"elimina {zi} \" pentru a elimina cheltuielile dintr-o zi. \n"
		<< "		Scrie \"elimina {zi1 la zi2}\" pentru a elimina cheltuielile dintr-un interval de zile. \n"
		<< "		Scrie \"elimina {tip}\" pentru a elimina cheltuielile pentru {tip}. \n"
		<< "3.Pentru a lista anumite costuri : \n"
		<< "		Scrie \"listeaza\" pentru a afisa toate cheltuielile.\n"
		<< "		Scrie \"listeaza {tip}\" pentru a afisa doar cheltuielile pentru {tip}.\n"
		<< "		Scrie \"listeaza {tip} {>,=} {valoare}\" pentru a afisa cheltuielile pentru {tip} cu valoarea {>,=} {valoare}."
		<< "4.Obtinerea unor proprietati : \n"
		<< "		Scrie \"suma {tip}\" pentru a afisa suma tuturor cheltuielior din categoria {tip}.\n"
		<< "		Scrie \"max zi\" pentru a afisa ziua cu cele mai mari cheltuieli.\n"
		<< "		Scrie \"sortare zi\" pentru a afisa sumele cheltuite zilnic in ordine descrescatoare.\n"
		<< "		Scrie \"sortare {tip}\" pentru a afisa sumele cheltuite pentru {tip},in ordine crescatoare.\n"
		<< "5.Filtrarea listei de cheltuieli : \n"
		<< "		Scrie \"filtrare {tip}\" pentru a pastra cheltuielile doar pentru {tip}. \n"
		<< "		Scrie \"filtrare {tip} {<,=} {valoare}\" pentru a pastra doar cheltuielile care indeplinesc conditia. \n"
		<< "u.Scrie\"u\"pentru a reveni inate de ultima actiune.\n"
		<< "x.Scrie \"x\"pentru a iesi din program.\n";
}

void UI::showConsole()
{
	int option;
	string cmd;
	vector <vector <Costs>> undo;
	while (true)
	{	
		menu();
		getline(cin, cmd);
		vector <Costs> v;
		if (cmd.find("add") != string::npos)
		{
			add(cmd);
			int nr = service.getSize();
			for (int i = 0; i < nr; i++)
			{
				v.push_back(service.show()[i]);
			}
			undo.push_back(v);
		}
		else if (cmd.find("elimina") != string::npos)
		{
			del(cmd);
			int nr = service.getSize();
			for (int i = 0; i < nr; i++)
			{
				v.push_back(service.show()[i]);
			}
			undo.push_back(v);
		}
		else if (cmd.find("listeaza") != string::npos)
		{
			show(cmd);
		}
		else if (cmd.find("suma") != string::npos)
		{
			sumaTip(cmd);
		}
		else if (cmd.find("max zi") != string::npos)
		{
			int v[32] = { 0 };
			service.sumeZi(v);
			int maxValue = 0,zi;
			for (int i = 1; i <= 31; i++)
			{
				if (v[i] > maxValue)
				{
					zi = i;
					maxValue = v[i];
				}
			}
			cout << zi << endl;
		}
		else if (cmd.find("sortare zi") != string::npos)
		{
			int v[32] = { 0 };
			service.sumeZi(v);
			service.ordonareDescrescatoare(v);
			for (int i = 0; i <= 31; i++)
				if (v[i] != 0)
					cout << " S-a cheltuit suma de : " << v[i] << endl;
		}
		else if (cmd.find("sortare") != string::npos)
		{

			string token, sep = " ";
			size_t pos = cmd.find(sep);

			cmd.erase(0, pos + sep.length());
			token = cmd.substr(0, pos);
			char* type = new char[token.length() + 1];
			strcpy_s(type, token.length() + 1, token.c_str());
			int nr = service.getSize(), n = 0;
			int v[32];
			n = service.sortareMancare(type, v, 0);
			cout << n << endl;
			service.ordonareCrescatoare(v, n);
			for (int i = 0; i < n; i++)
				cout << " S-a cheltuit suma de : " << v[i] << endl;
		}
		else if (cmd.find("filtrare") != string::npos)
		{
			filtrare(cmd);
			int nr = service.getSize();
			for (int i = 0; i < nr; i++)
			{
				v.push_back(service.show()[i]);
			}
			undo.push_back(v);
		}
		else if (cmd.find("u") != string::npos)
		{
			//int nr = v.size(),i;
			//cout << nr <<endl;
			//int inceput = nr - 2 * service.getSize() - (-1);
			//cout << inceput << endl;
			//cout << service.getSize() << endl;
			//for (i = inceput; i < inceput + service.getSize() - 1; i++)
			//	cout << v[i] << endl;
			//service.deleteNormal(v[i]);
			if (undo.size() > 1)
			{
				int nr = undo[undo.size() - 2].size();
				for (int i = 0; i < nr; i++)
					cout << undo[undo.size() - 2][i] << endl;
				cout << endl;
				service.updateCosts(undo);
				undo.pop_back();
			}
			else {
				undo.pop_back();
				service.updateCosts(undo);
				cout << "Nu mai exista costuri de familie!" << endl;
			}
		}
		else if (cmd.find("x") != string::npos)
		{
			cout << "Ati iesit din program!" << endl;
			break;
		}
		else cout << "Comanda gresita!"<<endl;
	}
}

void UI::add(string cmd)
{
	int day, sum, id, nr = 0;
	//char* type;
	//char another_type[100];

	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);

	string token, sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	if (pos != string::npos)
		nr++;
	id = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	if (pos != string::npos)
		nr++;
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	//cout << pos;
	token = cmd.substr(0, pos);
	if (pos != string::npos)
		nr++;
	sum = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	if (nr == 3)
		day = stoi(token);
	else day = newtime.tm_mday;

	Costs c(day, sum, id, type);
	service.add(c);
}

void UI::del(string cmd)
{
	int day1,day2,id,sum;
	string token,token2, sep = " ";
	size_t pos = cmd.find(sep);
	char* v = new char[2];
	strcpy_s(v, 2, " ");
	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	if (token[0] >= '0' and token[0] <= '9')
	{
		day1 = stoi(token);
		if(pos == string::npos)
			service.del(v,2,0,day1);
		else {
			cmd.erase(0, 3 + token.length());
			token2 = cmd.substr(0);
			day2 = stoi(token2);
			int* v = new int[service.getSize()];
			//for (int i = 0; i < service.getSize(); i++)
				//if (service.show()[i].getDay() >= day1 and service.show()[i].getDay() <= day2)
				//{
				//	cout << service.show()[i]<<endl;
				//}
			service.delZile(day1, day2);
		}
	}
	else {
		char* type = new char[token.length() + 1];
		strcpy_s(type, token.length() + 1, token.c_str());
		service.del(type,1,0,0);
	}
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

void UI::show(string cmd)
{	
	int day1, day2, id, sum;
	string token, token2, sep = " ",token3;
	size_t pos = cmd.find(sep);

	if (pos == string::npos)
	{
		int nr = service.getSize();
		for (int i = 0; i < nr; i++)
			cout << service.show()[i] << endl;
	}
	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	if (pos != string::npos)
	{
		cmd.erase(0, pos + sep.length());
		pos = cmd.find(sep);
		token2 = cmd.substr(0, pos);
		cout << pos <<" "<<token<< endl;
		if (pos != string::npos)
		{
			cmd.erase(0, pos + sep.length());
			pos = cmd.find(sep);
			token3 = cmd.substr(0, pos);
			sum = stoi(token3);
			char* type = new char[token.length() + 1];
			strcpy_s(type, token.length() + 1, token.c_str());
			if (token2 == ">")
			{
				int nr = service.getSize();
				for (int i = 0; i < nr; i++)
					if(service.show()[i].getSum() > sum and strcmp(service.show()[i].getType(),type) == 0)
						cout << service.show()[i] << endl;
			}
			else if (token2 == "=")
			{
				int nr = service.getSize();
				for (int i = 0; i < nr; i++)
					if (service.show()[i].getSum() == sum and strcmp(service.show()[i].getType(), type) == 0)
						cout << service.show()[i] << endl;
			}
		}
	}
	else {
		char* type = new char[token.length() + 1];
		strcpy_s(type, token.length() + 1, token.c_str());
		int nr = service.getSize();
		for (int i = 0; i < nr; i++)
			if (strcmp(service.show()[i].getType(), type) == 0)
				cout << service.show()[i] << endl;
	}
}

void UI::sumaTip(string cmd)
{
	string token, sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());
	cout << service.sumaTip(type) << endl;
}

void UI::filtrare(string cmd)
{
	int day, sum, id, nr = 0;
	string token, sep = " ",sign,value;
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());
	if (pos == string::npos)
		service.del(type, 0, 0,0);
	else{
		cmd.erase(0, pos + sep.length());
		pos = cmd.find(sep);
		sign = cmd.substr(0, pos);
		cmd.erase(0, pos + sep.length());
		pos = cmd.find(sep);
		value = cmd.substr(0, pos);
		sum = stoi(value);
		if (sign == "=")
		{
			service.del(type, 11, sum,0);
		}
		else if (sign == "<")
			service.del(type, -1, sum,0);
	}
}

void UI::save(const vector<Costs>& v)
{
	int nr = v.size();
	int inceput = nr - 2 * service.getSize() - (-1);
	int pos = 0;
	int nr2 = 0;
	for (int i = inceput; i < inceput + service.getSize() - 1; i++)
	{
		service.show()[pos] = v[i];
		nr2++;
	}
	this->n = nr2;
}
