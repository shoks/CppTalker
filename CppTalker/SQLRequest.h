#pragma once
#include <list>

class SQLRequest
{
	enum Operator
	{
		LIKE,
		IN,
		BETWEEN,
		OR,
		AND,
		ORAND,
		NOT,
		IS
	};
	typedef long long UUID_t;
public:
	SQLRequest();
	SQLRequest(const int& _PK);
	~SQLRequest();
	//SQLRequest* find(const int& _PK);
	static SQLRequest* Find(int _PK);
	std::list<std::string> GetAll();
	std::list<std::string> Get(const std::list<std::string>& _fields);

	SQLRequest* Where(const std::string& _column);
	SQLRequest* WhereNo(const std::string& _column);
	SQLRequest* Where(const std::string& _column, const std::string& value);
	SQLRequest* Where(const std::string& _column, const int& value);
	SQLRequest* Where(const std::string& _column, const double& value);
	SQLRequest* Where(const std::string& _column, const bool& value);
	SQLRequest* Where(const std::string& _column, const Operator& _operator ,const std::string& value);
	SQLRequest* Where(const std::string& _column, const Operator& _operator ,const int& value);
	SQLRequest* Where(const std::string& _column, const Operator& _operator ,const double& value);
	SQLRequest* Where(const std::string& _column, const Operator& _operator ,const bool& value);

private:

	//TODO for future implementation of other SQLDB

	//union PrimaryKey
	//{
	//	int I;
	//	UUID_t uuid;
	//};
	std::list<std::string> Fields;
	int PrimaryKey;
};

