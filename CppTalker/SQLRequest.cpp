#include "SQLRequest.h"


SQLRequest::SQLRequest()
{
}

SQLRequest::SQLRequest(const int& _PK)
{
	PrimaryKey = _PK;
}


SQLRequest::~SQLRequest()
{
}


SQLRequest* SQLRequest::Find(int _PK)
{

	return new SQLRequest(_PK);
}

std::list<std::string> SQLRequest::GetAll()
{
}

std::list<std::string> SQLRequest::Get(const std::list<std::string>& _fields)
{
}

SQLRequest* SQLRequest::Where(const std::string& _column)
{
}

SQLRequest* SQLRequest::WhereNo(const std::string& _column)
{
}

SQLRequest* SQLRequest::Where(const std::string& _column, const std::string& value)
{
}

SQLRequest* SQLRequest::Where(const std::string& _column, const int& value)
{
}

SQLRequest* SQLRequest::Where(const std::string& _column, const double& value)
{
}

SQLRequest* SQLRequest::Where(const std::string& _column, const bool& value)
{
}

SQLRequest* SQLRequest::Where(const std::string& _column, const Operator& _operator, const std::string& value)
{
}

SQLRequest* SQLRequest::Where(const std::string& _column, const Operator& _operator, const int& value)
{
}

SQLRequest * SQLRequest::Where(const std::string & _column, const Operator& _operator, const double & value)
{
}

SQLRequest* SQLRequest::Where(const std::string& _column, const Operator& _operator, const bool& value)
{
}
