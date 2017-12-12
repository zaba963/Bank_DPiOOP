#include "stdafx.h"
#include "Person.h"

#include "DataBase.h"

Person::Person()
{
}

Person::~Person()
{
}

PersonFactory::PersonFactory(){}

PersonFactory::~PersonFactory(){}

Person * PersonFactory::getNewPerson(size_t id)
{
	if (DataBase::get().isDataAcessType(id, DataBase::ADMIN)) { return new Admin(); }//TODO:
	if (DataBase::get().isDataAcessType(id, DataBase::FIRM)) { return new Firm(); }//TODO:
	if (DataBase::get().isDataAcessType(id, DataBase::STUDENT)) { return new Student(); }//TODO:
	if (DataBase::get().isDataAcessType(id, DataBase::WORKER)) { return new Worker(); }//TODO:
	return nullptr;
}
