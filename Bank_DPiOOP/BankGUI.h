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

	std::vector<void (*)(GUIVisitor &v, Person *p)> main_menu;
	std::vector<void(*)(GUIVisitor &v, Person *p)> login_menu;
public:
	static BankGUI & get();

	void accept(GUIVisitor &v, Person *p);

	void addMainMenuElement(void (*cons)(GUIVisitor &v, Person *p));
	void addLoginMenuElemnt(void(*cons)(GUIVisitor &v, Person *p));
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