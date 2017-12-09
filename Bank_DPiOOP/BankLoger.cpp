#include "stdafx.h"
#include "BankLoger.h"
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "DataBase.h"
#include "OperationBase.h"

BankLoger::BankLoger()
{
}

BankLoger::~BankLoger()
{
}

BankLoger & BankLoger::get()
{
	static BankLoger s;
	return s;
}

void cut(std::string * to_cut, const std::string sort) {}//TODO: redundant

void loadPerson(std::vector<std::string> * data) {}//TODO:

void loadOperation(std::vector<std::string> * data) {
	size_t id_from;
	bool get_id_from = false;
	size_t id_to;
	bool get_id_to = false;
	int funds;
	bool get_funds = false;
	OperationBase::_data_operation_type type;
	bool get_type = false;

	for (size_t i = 1; i < data->size(); i++) {
		if (data->at(i).find("<id_from>") < data->at(i).size()) {
			cut(&data->at(i), "id_from");
			id_from = atoi(data->at(i).c_str());
			get_id_from = true;
		}
		if (data->at(i).find("<id_to>") < data->at(i).size()) {
			cut(&data->at(i), "id_to");
			id_to = atoi(data->at(i).c_str());
			get_id_to = true;
		}
		if (data->at(i).find("<funds>") < data->at(i).size()) {
			cut(&data->at(i), "funds");
			funds = atoi(data->at(i).c_str());
			get_funds = true;
		}
		if (data->at(i).find("<type>") < data->at(i).size()) {
			cut(&data->at(i), "type");
			if (data->at(i).find("TRANSFER") < data->at(i).size())
				type = OperationBase::TRANSFER;
			if (data->at(i).find("CHECK") < data->at(i).size())
				type = OperationBase::CHECK;
			if (data->at(i).find("LOAN") < data->at(i).size())
				type = OperationBase::LOAN;
			if (data->at(i).find("INVESTMENT") < data->at(i).size())
				type = OperationBase::INVESTMENT;
			get_funds = true;
		}
	}
	if (get_id_from && get_id_to && get_funds && get_type)
		OperationBase::get().addData(new OperationBase::_data(id_from, id_to, funds, type));
}

void BankLoger::loadData(std::string input_file, std::string output_data)
{
	this->file = output_data;
	std::ofstream f_out;
	f_out.open(output_data);
	std::ifstream f_in;
	f_in.open(input_file);
	if (!f_in.is_open())
		return;
	std::string temp;
	std::vector<std::string> temp_d;
	bool gathering_p = false;
	bool gathering_o = false;
	while (!f_in.eof()) {
		std::getline(f_in, temp);
		if (temp.find("<person>") < temp.size()) {
			gathering_p = true;
		}
		if (temp.find("<operation>") < temp.size()) {
			gathering_o = true;
		}
		if (gathering_p)
			temp_d.push_back(temp);
		if (gathering_o)
			temp_d.push_back(temp);
		if (temp.find("</person>") < temp.size()) {
			gathering_p = false;
			loadPerson(&temp_d);
			temp_d.clear();
		}
		if (temp.find("</operation>") < temp.size()) {
			gathering_o = false;
			loadOperation(&temp_d);
			temp_d.clear();
		}
	}
}

void BankLoger::putData(std::vector<std::string> data)
{
	std::ofstream f_out;
	f_out.open(file, std::ios::app);
	for (size_t i = 0; i < data.size(); i++)
		f_out << data[i] << std::endl;
	f_out.close();
}
