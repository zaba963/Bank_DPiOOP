#pragma once
#include <string>
#include <functional>
#include <map>
#include <vector>

#include "Person.h"

const size_t password_size = 128;

class DataBase
{
public:
	enum _data_acess_type {CLIENT, ADMIN};

	class _data {
	public:
		size_t password;
		std::string ps_password;
		int funds;
		std::string name;
		std::string surname;
		size_t birth_date;
		_data_acess_type acess;

		_data(std::string t_password, int t_funds, std::string t_name, std::string t_surname, size_t t_birth_date, _data_acess_type t_acess = CLIENT) :
			funds(t_funds),
			name(t_name),
			surname(t_surname),
			birth_date(t_birth_date),
			acess(t_acess)
		{
			ps_password = "";
			if (t_password.size() > 128)
				t_password = t_password.substr(0, password_size - 1);
			if (t_password.size() < 128)
				while (t_password.size() < 128) {
					char t = rand() % 26 + 65;
					t_password += t;
					ps_password += t;
				}

			password = std::hash<std::string>{}(t_password);
		}

		_data(size_t t_password, std::string t_ps_password, int t_funds, std::string t_name, std::string t_surname, size_t t_birth_date, _data_acess_type t_acess = CLIENT) :
			password(t_password),
			ps_password(t_ps_password),
			funds(t_funds),
			name(t_name),
			surname(t_surname),
			birth_date(t_birth_date),
			acess(t_acess){}

	};
private:
	DataBase();
	DataBase(DataBase &);
	~DataBase();

	std::map<size_t, _data* > base;
	static size_t cur_id;
public:

	static DataBase & get();

	void addData(_data * d);
	void addDataFromFile(_data * d);

	size_t getHashPassword(size_t id);
	bool isPassword(size_t id, std::string pas);
	int getFunds(size_t id);
	std::string getName(size_t id);
	std::string getSurname(size_t id);
	size_t getBirthDate(size_t id);
	bool isDataAcessType(size_t id, _data_acess_type type);
	Person * getClient(size_t id);

	std::vector<std::string> printXML(_data * d);
};

