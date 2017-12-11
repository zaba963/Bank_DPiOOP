#include "stdafx.h"
#include "BankMainFrame.h"


BankMainFrame::BankMainFrame()
{
	bank_time = 0;
}


BankMainFrame::~BankMainFrame()
{
}

BankMainFrame & BankMainFrame::get()
{
	static BankMainFrame s;
	return s;
}

void BankMainFrame::startBank()
{
	//TODO: Bank start
}
