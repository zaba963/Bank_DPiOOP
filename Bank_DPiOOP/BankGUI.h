#pragma once
#include "Person.h"

class GUIVisitor {
public:
	GUIVisitor();
	~GUIVisitor();

	virtual void visit(BankGUI * g, Person *p) = 0;
};

class BankGUI
{
	BankGUI();
	BankGUI(BankGUI &);
	~BankGUI();
public:
	static BankGUI & get();

	void accept(GUIVisitor &v, Person *p);
};

