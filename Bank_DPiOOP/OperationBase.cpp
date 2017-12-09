#include "stdafx.h"
#include "OperationBase.h"

#include "BankLoger.h"

OperationBase::OperationBase()
{
}


OperationBase::~OperationBase()
{
}

OperationBase & OperationBase::get()
{
	static OperationBase s;
	return s;
}

void OperationBase::addData(_data * d)
{
	BankLoger::get().putData(printXML(d));
	base.push_back(d);
}

void OperationBase::addDataFromFile(_data * d)
{
	base.push_back(d);
}

size_t OperationBase::getIDFrom(size_t element)
{
	if (element < base.size())
		return base[element]->id_from;
	return NULL;
}

size_t OperationBase::getIDTo(size_t element)
{
	if (element < base.size())
		return base[element]->id_to;
	return NULL;
}

int OperationBase::getFunds(size_t element)
{
	if (element < base.size())
		return base[element]->funds;
	return NULL;
}

OperationBase::_data_operation_type OperationBase::getType(size_t element)
{
	if (element < base.size())
		return base[element]->acess;
	return NONE;
}

bool OperationBase::isType(size_t element, _data_operation_type type)
{
	if (element < base.size())
		if (base[element]->acess == type)
			return true;
	return false;
}

std::vector<std::string> OperationBase::printXML(_data * d)
{
	std::vector<std::string> temp;
	temp.push_back("<operation>");
	temp.push_back("<id_from>" + std::to_string(d->id_from) + "</id_from>");
	temp.push_back("<id_to>" + std::to_string(d->id_to) + "</id_to>");
	temp.push_back("<funds>" + std::to_string(d->funds) + "</funds>");
	if(d->acess == TRANSFER)
	temp.push_back("<type>TRANSFER</type>");
	if (d->acess == CHECK)
		temp.push_back("<type>CHECK</type>");
	if (d->acess == LOAN)
		temp.push_back("<type>LOAN</type>");
	if (d->acess == INVESTMENT)
		temp.push_back("<type>INVESTMENT</type>");
	temp.push_back("</operation>");
	return temp;
}
