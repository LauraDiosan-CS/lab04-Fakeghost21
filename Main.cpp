#include "UI.h"
#include "Tests.h"
#include <iostream>
#include <string.h>
#include "Repo.h"
#include "FamilyCosts.h"
#include "Service.h"
using namespace std;

int main()
{
	testsCosts();
	testRepoCosts();
	testServiceCosts();
	UI ui;
	ui.showConsole();
	return 0;
}
