#include "stdafx.h"
#include "Person.h"
#include <iostream>

#include "DataBase.h"
#include "OperationBase.h"

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
	if (DataBase::get().isDataAcessType(id, DataBase::ADMIN)) { return new Admin(id); }
	if (DataBase::get().isDataAcessType(id, DataBase::FIRM)) { return new Firm(id); }
	if (DataBase::get().isDataAcessType(id, DataBase::STUDENT)) { return new Student(id); }
	if (DataBase::get().isDataAcessType(id, DataBase::WORKER)) { return new Worker(id); }
	return nullptr;
}

Admin::Admin(size_t t_id)
{
	id = t_id;
	type = 0;
}

Admin::~Admin(){}

void Admin::printHistory(){}

User::User(){}

User::~User(){}

Firm::Firm(size_t t_id)
{
	id = t_id;
	type = 3;
}

Firm::~Firm(){}

Civilian::Civilian(){}

Civilian::~Civilian(){}

void User::printHistory()
{
	for (size_t i = 0; i < OperationBase::get().getSize(); i++) {
		if (OperationBase::get().getIDFrom(i) == this->id) {
			std::cout << "Transfer to " << OperationBase::get().getIDTo(i) << " funds transfer " << -OperationBase::get().getFunds(i) << std::endl;
		}
		if (OperationBase::get().getIDTo(i) == this->id) {
			std::cout << "Transfer from " << OperationBase::get().getIDTo(i) << " funds transfer " << OperationBase::get().getFunds(i) << std::endl;
		}
	}
	system("pause");
}

Student::Student(size_t t_id)
{
	id = t_id;
	type = 2;
}

Student::~Student(){}

Worker::Worker(size_t t_id)
{
	id = t_id;
	type = 2;
}

Worker::~Worker(){}
