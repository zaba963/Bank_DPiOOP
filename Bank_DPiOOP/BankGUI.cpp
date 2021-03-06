#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <conio.h>

#include "BankGUI.h"
#include "DataBase.h"
#include "BankMainFrame.h"
#include "OperationBase.h"

BankGUI::BankGUI(){}

BankGUI::~BankGUI(){}

BankGUI & BankGUI::get()
{
	static BankGUI s;
	return s;
}

void BankGUI::accept(GUIVisitor & v, Person * p)
{
	v.visit(this, p);
}

void BankGUI::addMainMenuElement(GUIVisitor * cons)
{
	main_menu.push_back(cons);
}

void BankGUI::addLoginMenuElement(GUIVisitor * cons)
{
	login_menu.push_back(cons);
}

void BankGUI::clearGUI()
{
	system("cls");
}

void BankGUI::print(std::string str)
{
	std::cout << str;
}

void BankGUI::println(std::string str)
{
	std::cout << str << std::endl;
}

size_t BankGUI::getID()
{
	size_t temp;
	std::cin >> temp;
	return temp;
}

int BankGUI::getInt()
{
	int temp;
	std::cin >> temp;
	return temp;
}

std::string BankGUI::getLineString()
{
	std::string temp;
	std::cin >> temp;
	return temp;
}

void BankGUI::startGUI()
{
	menu_layer = 0;
	while (true) {
		switch (menu_layer)
		{
		case 0:
			printMainMenu();
			break;
		case 1:
			printLoginMenu();
			break;
		default:
			break;
		}
	}
}

void BankGUI::printMainMenu()
{
	GUI_posytion = 0;
	int temp;
	do{
		clearGUI();
		this->println("Log menu");
		this->println();
		for (size_t i = 0; i < main_menu.size(); i++) {
			if (GUI_posytion == i) {
				std::cout << "> ";
			}
			else {
				std::cout << "  ";
			}
			main_menu[i]->printMenu(this);
		}
		temp = getInputToGUI();
		if (temp >= main_menu.size() && temp >= 0)
			temp = main_menu.size() - 1;
		if (GUI_posytion >= login_menu.size())
			GUI_posytion == login_menu.size() - 1;
	}
	while (temp >= 0);
	main_menu[GUI_posytion]->visit(this, nullptr);
}

void BankGUI::printLoginMenu()
{
	GUI_posytion = 0;
	int temp;
	do{
		clearGUI();
		this->println("Main menu");
		this->println();
		for (size_t i = 0; i < login_menu.size(); i++) {
			if (GUI_posytion == i) {
				std::cout << "> ";
			}
			else {
				std::cout << "  ";
			}
			login_menu[i]->printMenu(this);
		}
		temp = getInputToGUI();
		if (temp >= login_menu.size() && temp >= 0)
			temp = login_menu.size() - 1;
		if (GUI_posytion >= login_menu.size())
			GUI_posytion == login_menu.size() - 1;
	}
	while (temp >= 0);
	login_menu[GUI_posytion]->visit(this, BankMainFrame::get().getCurentClient());
}

int BankGUI::getInputToGUI()
{
	bool done = false;
	do {
		char t = _getch();
		if (t == 's') {
			done = true;
			GUI_posytion++;
			return GUI_posytion;
		}
		if (t == 'w') {
			done = true;
			if (GUI_posytion == 0) {
				GUI_posytion = 0;
			}
			else {
				GUI_posytion--; 
			}
			return GUI_posytion;
		}
		if (t == '\r') {
			done = true;
			return -1;
		}
	} while (!done);
	return -1;
}

GUIVisitor::GUIVisitor(){}

GUIVisitor::~GUIVisitor(){}

GUILogin::GUILogin(){}

GUILogin::~GUILogin(){}

void GUILogin::visit(BankGUI * g, Person * p)
{
	g->clearGUI();
	bool corect = true;
	size_t t_id;
	do {
		if(!corect)
			g->println("password incorect - try again");
		g->println("pass id");
		t_id = g->getID();
		g->println("pass password");
		std::string t_pass = g->getLineString();
		corect = DataBase::get().isPassword(t_id, t_pass);
	} while (!corect);
	if (corect) {
		BankMainFrame::get().setCurentClient(DataBase::get().getClient(t_id));
		g->menu_layer++;
	}
}

void GUILogin::printMenu(BankGUI * g)
{
	g->println("Login to your account");
}

GUIMoveTime::GUIMoveTime(){}

GUIMoveTime::~GUIMoveTime(){}

void GUIMoveTime::visit(BankGUI * g, Person * p)
{
	g->clearGUI();
	g->println("how much time would you like to pass?");
	size_t temp = g->getID();
	BankMainFrame::get().passTime(temp);
}

void GUIMoveTime::printMenu(BankGUI * g)
{
	g->println("Time passing operation");
}

GUIHistory::GUIHistory(){}

GUIHistory::~GUIHistory(){}

void GUIHistory::visit(BankGUI * g, Person * p)
{
	g->clearGUI();
	g->println("History");
	g->println("");
	p->printHistory();
}

void GUIHistory::printMenu(BankGUI * g)
{
	g->println("History");
}

GUITransfer::GUITransfer(){}

GUITransfer::~GUITransfer(){}

void GUITransfer::visit(BankGUI * g, Person * p)
{
	g->clearGUI();
	g->println("Transfer to - client id");
	size_t temp = g->getID();
	g->println("Amount");
	int t_a = g->getInt();
	if(t_a > 0)
	if (DataBase::get().egzistPerson(temp)) {
		DataBase::get().subFunds(p->getId(), t_a);
		DataBase::get().addFunds(temp, t_a);
		OperationBase::get().addData(new OperationBase::_data(p->getId(), temp, t_a, OperationBase::TRANSFER));
	}
}

void GUITransfer::printMenu(BankGUI * g)
{
	g->println("Transfer");
}

GUILogout::GUILogout(){}

GUILogout::~GUILogout(){}

void GUILogout::visit(BankGUI * g, Person * p)
{
	BankMainFrame::get().setCurentClient(new Civilian());
	g->menu_layer = 0;
}

void GUILogout::printMenu(BankGUI * g)
{
	g->println("Logout");
}
