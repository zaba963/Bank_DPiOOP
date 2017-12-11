#pragma once
#include <vector>
#include "Person.h"

class BankGUI;

class GUIVisitor {
public:
	GUIVisitor();
	~GUIVisitor();

	static void visit(BankGUI * g, Person *p);
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
};

class GUILogin : public GUIVisitor {
public:
	GUILogin();
	~GUILogin();

	static void visit(BankGUI * g, Person *p);
};

class GUIMoveTime : public GUIVisitor {
public:
	GUIMoveTime();
	~GUIMoveTime();

	static void visit(BankGUI * g, Person *p);
};