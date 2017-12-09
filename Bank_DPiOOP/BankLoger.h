#pragma once
#include <string>
#include <vector>

class BankLoger
{
	BankLoger();
	BankLoger(BankLoger &);
	~BankLoger();

	std::string file;
public:
	static BankLoger & get();

	void loadData(std::string input_file, std::string output_data);
	void putData(std::vector<std::string> data);
};

