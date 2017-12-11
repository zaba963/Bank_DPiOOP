#pragma once
#include "Person.h"

class BankMainFrame
{
	BankMainFrame();
	BankMainFrame(BankMainFrame&);
	~BankMainFrame();

	size_t bank_time;
	Person * curent_client;

public:
	static BankMainFrame & get();

	void startBank();

	Person * getCurentClient();
	void setCurentClient(Person * c);
	size_t getCurentTime();
	void passTime(size_t t_time);
};

