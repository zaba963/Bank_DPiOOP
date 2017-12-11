#pragma once
#include <string>
#include <vector>
#include "Person.h"

class BankGUI;

class GUIVisitor {
public:
	GUIVisitor();
	~GUIVisitor();

	void visit(BankGUI * g, Person *p);
	void printMenu(BankGUI * g);
};

class BankGUI
{
	BankGUI();
	BankGUI(BankGUI &);
	~BankGUI();

	std::vector<GUIVisitor*> main_menu;
	std::vector<GUIVisitor*> login_menu;
public:
	static BankGUI & get();

	void accept(GUIVisitor &v, Person *p);

	void addMainMenuElement(GUIVisitor * cons);
	void addLoginMenuElemnt(GUIVisitor * cons);

	void clearGUI();
	void print(std::string str);
	void println(std::string str = "");
	size_t getID();
	std::string getLineString();

	void printMainMenu();
	void printLoginMenu();
};

class GUILogin : public GUIVisitor {
public:
	GUILogin();
	~GUILogin();

	static void visit(BankGUI * g, Person *p);
	void printMenu(BankGUI * g);
};

class GUIMoveTime : public GUIVisitor {
public:
	GUIMoveTime();
	~GUIMoveTime();

	static void visit(BankGUI * g, Person *p);
	void printMenu(BankGUI * g);
};