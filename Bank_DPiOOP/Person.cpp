#include "stdafx.h"
#include "Person.h"

#include "DataBase.h"

Person::Person()
{
}

Person::~Person()
{
}

size_t Person::getId()
{
	return id;
}

PersonFactory::PersonFactory(){}

PersonFactory::~PersonFactory(){}

Person * PersonFactory::getNewPerson(size_t id)
{
	if (DataBase::get().isDataAcessType(id, DataBase::ADMIN)) { return new Admin(id); }//TODO:
	if (DataBase::get().isDataAcessType(id, DataBase::FIRM)) { return new Firm(id); }//TODO:
	if (DataBase::get().isDataAcessType(id, DataBase::STUDENT)) { return new Student(id); }//TODO:
	if (DataBase::get().isDataAcessType(id, DataBase::WORKER)) { return new Worker(id); }//TODO:
	return nullptr;
}

Admin::Admin(size_t t_id)
{
	type = 0;
}

Admin::~Admin(){}

void Admin::printHistory(){}

User::User(){}

User::~User(){}

Firm::Firm(size_t t_id)
{
	type = 3;
}

Firm::~Firm(){}

Civilian::Civilian(){}

Civilian::~Civilian(){}

void User::printHistory()
{
	//TODO:
}

Student::Student(size_t t_id)
{
	type = 2;
}

Student::~Student(){}

Worker::Worker(size_t t_id)
{
	type = 2;
}

Worker::~Worker(){}
