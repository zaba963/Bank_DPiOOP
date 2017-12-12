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

void cut(std::string * to_cut, const std::string sort) {
	std::string a = "<" + sort + ">";
	std::string b = "</" + sort + ">";
	if (to_cut->find(a) < to_cut->size())
		to_cut->assign(to_cut->substr(to_cut->find(a) + a.size(), to_cut->size()));
	if (to_cut->find(b) < to_cut->size())
		to_cut->assign(to_cut->substr(0, to_cut->find(b)));
}

void loadPerson(std::vector<std::string> * data) {
	size_t password;
	std::string ps_password;
	int funds;
	std::string name;
	std::string surname;
	size_t birth_date;
	DataBase::_data_acess_type acess = DataBase::STUDENT;
	bool get_password = false;
	bool get_ps_password = false;
	bool get_funds = false;
	bool get_name = false;
	bool get_surname = false;
	bool get_birth_date = false;
	bool get_acess = false;

	for (size_t i = 1; i < data->size(); i++) {
		if (data->at(i).find("<password_hash>") < data->at(i).size()) {
			cut(&data->at(i), "password_hash");
			password = atoi(data->at(i).c_str());
			get_password = true;
		}
		if (data->at(i).find("<password_ps>") < data->at(i).size()) {
			cut(&data->at(i), "password_ps");
			ps_password.assign(data->at(i));
			get_ps_password = true;
		}
		if (data->at(i).find("<funds>") < data->at(i).size()) {
			cut(&data->at(i), "funds");
			funds = atoi(data->at(i).c_str());
			get_funds = true;
		}
		if (data->at(i).find("<name>") < data->at(i).size()) {
			cut(&data->at(i), "name");
			name.assign(data->at(i));
			get_name = true;
		}
		if (data->at(i).find("<surname>") < data->at(i).size()) {
			cut(&data->at(i), "surname");
			surname.assign(data->at(i));
			get_surname = true;
		}
		if (data->at(i).find("<birthdate>") < data->at(i).size()) {
			cut(&data->at(i), "birthdate");
			birth_date = atoi(data->at(i).c_str());
			get_birth_date = true;
		}
		if (data->at(i).find("<acess>") < data->at(i).size()) {
			cut(&data->at(i), "acess");
			if (data->at(i).find("FIRM") < data->at(i).size())
				acess = DataBase::FIRM;
			if (data->at(i).find("STUDENT") < data->at(i).size())
				acess = DataBase::STUDENT;
			if (data->at(i).find("WORKER") < data->at(i).size())
				acess = DataBase::WORKER;
			if (data->at(i).find("ADMIN") < data->at(i).size())
				acess = DataBase::ADMIN;
			get_acess = true;
		}
	}
	if (get_password && get_ps_password && get_funds && get_name && get_surname && get_birth_date && get_acess) {
		DataBase::get().addDataFromFile(new DataBase::_data(password, ps_password, funds, name, surname, birth_date, acess));
	}
}

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
			get_type = true;
		}
	}
	if (get_id_from && get_id_to && get_funds && get_type) {
		OperationBase::get().addDataFromFile(new OperationBase::_data(id_from, id_to, funds, type));
	}
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
		f_out << temp << std::endl;
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
