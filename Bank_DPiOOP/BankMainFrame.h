#pragma once
#include "Person.h"

class BankMainFrame
{
	BankMainFrame();
	BankMainFrame(BankMainFrame&);
	~BankMainFrame();

	size_t bank_time;
	Person * curentClient;

public:
	static BankMainFrame & get();

	void startBank();

	Person * getCurentClient();
	size_t getCurentTime();
	void passTime(size_t t_time);
};

