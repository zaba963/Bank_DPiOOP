#pragma once
class Person
{
public:
	Person();
	~Person();
};

class Admin : public Person{};

class User : public Person {};

class Firm : public User {};

class Civilian : public User {};

class Student : public Civilian {};

class Worker : public Civilian {};

class PersonFactory {
public:
	PersonFactory();
	~PersonFactory();

	static Person * getNewPerson(size_t id);
};