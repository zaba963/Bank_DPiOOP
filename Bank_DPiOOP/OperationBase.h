#pragma once
#include <vector>

class OperationBase
{
public:
	enum _data_operation_type {NONE, TRANSFER, CHECK, LOAN, INVESTMENT};

	class _data {
	public:
		size_t id_from;
		size_t id_to;
		int funds;
		_data_operation_type acess;

		_data(size_t t_id_from, size_t t_id_to, int t_funds, _data_operation_type t_type) :
			id_from(t_id_from),
			id_to(t_id_to),
			funds(t_funds),
			acess(t_type){}
	};
private:
	OperationBase();
	OperationBase(OperationBase &);
	~OperationBase();

	std::vector<_data* > base;
public:

	static OperationBase & get();

	void addData(_data * d);
	void addDataFromFile(_data * d);

	size_t getIDFrom(size_t element);
	size_t getIDTo(size_t element);
	int getFunds(size_t element);
	_data_operation_type getType(size_t element);
	bool isType(size_t element, _data_operation_type type);

	std::vector<std::string> printXML(_data * d);
};

