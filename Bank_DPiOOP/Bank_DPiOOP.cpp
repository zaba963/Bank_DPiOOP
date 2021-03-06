// Bank_DPiOOP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>

#include "DataBase.h"
#include "BankGUI.h"
#include "BankLoger.h"

#include "BankMainFrame.h"

using namespace std;

int main()
{
	srand(time(NULL));
	BankLoger::get().loadData("test.xml", "bank_log.xml");
	BankGUI::get().addMainMenuElement(new GUILogin);
	BankGUI::get().addMainMenuElement(new GUIMoveTime);
	BankGUI::get().addLoginMenuElement(new GUIHistory);
	BankGUI::get().addLoginMenuElement(new GUITransfer);
	//BankGUI::get().addLoginMenuElement(new GUICheck);
	//BankGUI::get().addLoginMenuElement(new GUILoan);
	//BankGUI::get().addLoginMenuElement(new GUILoanAutent);
	//BankGUI::get().addLoginMenuElement(new GUIInvestment);
	//BankGUI::get().addLoginMenuElement(new GUICashPayment);
	BankGUI::get().addLoginMenuElement(new GUILogout);

	BankMainFrame::get().startBank();

	system("pause");
    return 0;
}

