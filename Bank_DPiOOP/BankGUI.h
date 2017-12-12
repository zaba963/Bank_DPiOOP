#pragma once
#include <string>
#include <vector>
#include "Person.h"

class BankGUI;

class GUIVisitor {
public:
	GUIVisitor();
	~GUIVisitor();

	virtual void visit(BankGUI * g, Person *p) = 0;
	virtual void printMenu(BankGUI * g) = 0;

};

class BankGUI
{
	BankGUI();
	BankGUI(BankGUI &);
	~BankGUI();

	std::vector<GUIVisitor*> main_menu;
	std::vector<GUIVisitor*> login_menu;

	int GUI_posytion;
public:
	int menu_layer;

	static BankGUI & get();

	void accept(GUIVisitor &v, Person *p);

	void addMainMenuElement(GUIVisitor * cons);
	void addLoginMenuElement(GUIVisitor * cons);

	void clearGUI();
	void print(std::string str);
	void println(std::string str = "");
	size_t getID();
	int getInt();
	std::string getLineString();

	void startGUI();
	void printMainMenu();
	void printLoginMenu();

	int getInputToGUI();
};

class GUILogin : public GUIVisitor {
public:
	GUILogin();
	~GUILogin();

	void visit(BankGUI * g, Person *p);
	void printMenu(BankGUI * g);
};

class GUIMoveTime : public GUIVisitor {
public:
	GUIMoveTime();
	~GUIMoveTime();

	void visit(BankGUI * g, Person *p);
	void printMenu(BankGUI * g);
};

class GUIHistory : public GUIVisitor {
public:
	GUIHistory();
	~GUIHistory();

	void visit(BankGUI * g, Person *p);
	void printMenu(BankGUI * g);
};

class GUITransfer : public GUIVisitor {
public:
	GUITransfer();
	~GUITransfer();

	void visit(BankGUI * g, Person *p);
	void printMenu(BankGUI * g);
};

class GUILogout : public GUIVisitor {
public:
	GUILogout();
	~GUILogout();

	void visit(BankGUI * g, Person *p);
	void printMenu(BankGUI * g);
};