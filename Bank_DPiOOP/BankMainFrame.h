#pragma once
class BankMainFrame
{
	BankMainFrame();
	BankMainFrame(BankMainFrame&);
	~BankMainFrame();

	size_t bank_time;

public:
	BankMainFrame & get();

	void startBank();
};

