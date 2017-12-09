#include "stdafx.h"
#include "OperationBase.h"


OperationBase::OperationBase()
{
}


OperationBase::~OperationBase()
{
}

void OperationBase::addData(_data * d)
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
