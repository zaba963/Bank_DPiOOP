#include "stdafx.h"
#include <iostream>
#include <string>

#include "BankGUI.h"
#include "DataBase.h"
#include "BankMainFrame.h"

BankGUI::BankGUI()
{
}

BankGUI::~BankGUI()
{
}

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

void BankGUI::addLoginMenuElemnt(GUIVisitor * cons)
{
	login_menu.push_back(cons);
}

void BankGUI::clearGUI()
{
	system("clc");
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

std::string BankGUI::getLineString()
{
	std::string temp;
	std::cin >> temp;
	return temp;
}

void BankGUI::printMainMenu()
{
	this->println("Main menu");
	this->println();
	for (size_t i = 0; i < main_menu.size(); i++)
		main_menu[i]->printMenu(this);
	//TODO : add cursor and way to interact
}

void BankGUI::printLoginMenu()
{
	this->println("Main menu");
	this->println();
	for (size_t i = 0; i < login_menu.size(); i++)
		login_menu[i]->printMenu(this);
	//TODO : add cursor and way to interact
}

GUIVisitor::GUIVisitor()
{
}

GUIVisitor::~GUIVisitor()
{
}

void GUIVisitor::visit(BankGUI * g, Person * p){}

void GUIVisitor::printMenu(BankGUI * g){}

GUILogin::GUILogin()
{
}

GUILogin::~GUILogin()
{
}

void GUILogin::visit(BankGUI * g, Person * p)
{
	g->clearGUI();
	bool corect = true;
	size_t t_id;
	do {
		if(!corect)
			g->println("password incorect - try again");
		g->println("pase id");
		t_id = g->getID();
		g->println("pass password");
		std::string t_pass = g->getLineString();
		corect = DataBase::get().isPassword(t_id, t_pass);
	} while (!corect);
	if (corect)
		BankMainFrame::get().setCurentClient(DataBase::get().getClient(t_id));
}

void GUILogin::printMenu(BankGUI * g)
{
	g->println("Loginn to your acaunt");
}

GUIMoveTime::GUIMoveTime()
{
}

GUIMoveTime::~GUIMoveTime()
{
}

void GUIMoveTime::visit(BankGUI * g, Person * p)
{
	g->clearGUI();
	g->println("pass amaunt time to pass");
	size_t temp = g->getID();
	BankMainFrame::get().passTime(temp);
}

void GUIMoveTime::printMenu(BankGUI * g)
{
	g->println("Time passing operation");
}
