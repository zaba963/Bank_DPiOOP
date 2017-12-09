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

GUIVisitor::GUIVisitor()
{
}

GUIVisitor::~GUIVisitor()
{
}
