// Bank_DPiOOP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>

#include "DataBase.h"
#include "BankGUI.h"
#include "BankLoger.h"

using namespace std;

int main()
{
	srand(time(NULL));

	BankLoger::get().loadData("test.xml", "bank_log.xml");

	system("pause");
    return 0;
}

