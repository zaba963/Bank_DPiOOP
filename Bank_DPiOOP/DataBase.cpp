#include "stdafx.h"
#include "DataBase.h"
#include <functional>
#include <time.h>

#include "BankLoger.h"

size_t DataBase::cur_id = 0;

DataBase::DataBase()
{
}

DataBase::~DataBase()
{
}

DataBase & DataBase::get()
{
	static DataBase s;
	return s;
}

void DataBase::addData(_data * d)
{
	BankLoger::get().putData(printXML(d));
	base.insert(std::pair<size_t, _data*>(cur_id, d));
	cur_id++;
}

void DataBase::addDataFromFile(_data * d)
{
	base.insert(std::pair<size_t, _data*>(cur_id, d));
	cur_id++;
}

size_t DataBase::getHashPassword(size_t id)
{
	return base[id]->password;
}

bool DataBase::isPassword(size_t id, std::string pas)
{
	pas += base[id]->ps_password;
	if (base[id]->password == std::hash<std::string>{}(pas));
		return true;
	return false;
}

int DataBase::getFunds(size_t id)
{
	return base[id]->funds;
}

std::string DataBase::getName(size_t id)
{
	return base[id]->name;
}

std::string DataBase::getSurname(size_t id)
{
	return base[id]->surname;
}

size_t DataBase::getBirthDate(size_t id)
{
	return base[id]->birth_date;
}

bool DataBase::isDataAcessType(size_t id, _data_acess_type type)
{
	if (base[id]->acess == type)
		return true;
	return false;
}

Person * DataBase::getClient(size_t id)
{
	//TODO:
	//call clients factory to return corect client and preper his acaunt data
	return nullptr;
}

std::vector<std::string> DataBase::printXML(_data * d)
{
	std::vector<std::string> temp;
	temp.push_back("<person>");
	temp.push_back("\t<password_hash>" + std::to_string(d->password) + "</password_hash>");
	temp.push_back("\t<password_ps>" + d->ps_password + "</password_hash_ps>");
	temp.push_back("\t<funds>" + std::to_string(d->funds) + "</funds>");
	temp.push_back("\t<name>" + d->name + "</name>");
	temp.push_back("\t<surname>" + d->surname + "</surname>");
	temp.push_back("\t<birthdate>" + std::to_string(d->birth_date) + "</birthdate>");
	if(d->acess == CLIENT)
		temp.push_back("\t<acess>CLIENT</acess>");
	if (d->acess == ADMIN)
		temp.push_back("\t<acess>ADMIN</acess>");
	temp.push_back("</person>");
	return temp;
}
