#include "stdafx.h"
#include "DataBase.h"
#include <functional>
#include <time.h>

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
