#include "stdafx.h"
#include "BankGUI.h"

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

GUIVisitor::GUIVisitor()
{
}

GUIVisitor::~GUIVisitor()
{
}

void GUIVisitor::visit(BankGUI * g, Person * p){}

GUILogin::GUILogin()
{
}

GUILogin::~GUILogin()
{
}

void GUILogin::visit(BankGUI * g, Person * p)
{
	//TODO:
	//refresh gui
	//print "pase id"
	//waits for id
	//print "pass password"
	//waits for password
	//check if corect -> if corect set person to be login
	//if not corect repets login
}

GUIMoveTime::GUIMoveTime()
{
}

GUIMoveTime::~GUIMoveTime()
{
}

void GUIMoveTime::visit(BankGUI * g, Person * p)
{
	//TODO:
	//refresk GUI
	//prints "pass amaunt time to pass"
	//gets value of pass time
	//update bank timer
}
