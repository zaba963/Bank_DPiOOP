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

Person * BankMainFrame::getCurentClient()
{
	return curentClient;
}

size_t BankMainFrame::getCurentTime()
{
	return bank_time;
}

void BankMainFrame::passTime(size_t t_time)
{
	bank_time += t_time;
}
