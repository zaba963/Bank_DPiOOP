#pragma once
class Person
{
protected:
	int type;
	size_t id;
public:
	Person();
	~Person();
	size_t getId();

	virtual void printHistory() = 0;
};

class Admin : public Person{
public:
	Admin(size_t t_id);
	~Admin();

	void printHistory();
};

class User : public Person {
public:
	User();
	~User();

	void printHistory();
};

class Firm : public User {
public:
	Firm(size_t t_id);
	~Firm();
};

class Civilian : public User {
public:
	Civilian();
	~Civilian();
};

class Student : public Civilian {
public:
	Student(size_t t_id);
	~Student();
};

class Worker : public Civilian {
public:
	Worker(size_t t_id);
	~Worker();
};

class PersonFactory {
public:
	PersonFactory();
	~PersonFactory();

	static Person * getNewPerson(size_t id);
};