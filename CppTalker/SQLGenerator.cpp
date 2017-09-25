#include "SQLGenerator.h"



SQLGenerator::SQLGenerator(SQLPrepare& _prepared) : prepared(_prepared)
{
	Start();
}


SQLGenerator::~SQLGenerator()
{
}


void SQLGenerator::Start()
{
	if (prepared.HasAnyInsert())
	{
		auto processResult = ProcessInsert(prepared.GetInsertRequest());
		auto InsertSQLQuery = InsertFormatter(processResult);
	}
	
}

std::pair<std::list<std::string>, std::list<std::string>> SQLGenerator::ProcessInsert(InsertMap* _insertRequest)
{
	std::list<std::string> columns;
	std::list<std::string> values;

	for(auto it = _insertRequest->begin(); it != _insertRequest->end(); ++it)
	{
		columns.push_back(it->first);
		values.push_back(it->second);
	}

	return std::pair<std::list<std::string>, std::list<std::string>>(columns, values);
}

std::string SQLGenerator::InsertFormatter(std::pair<std::list<std::string>, std::list<std::string>> _parameters)
{
	auto columns = _parameters.first;
	auto values = _parameters.second;
	std::stringstream sstream;

	sstream << "INSERT INTO " << prepared.GetTableName() << " (";

	for (auto it = columns.begin(); columns.end() != it; ++it)
	{
		sstream << *it;
		if(columns.end() != ++it)
			sstream << ", ";
	}

	sstream << " ) VALUES (";

	for (auto it = values.begin(); values.end() != it; ++it)
	{
		sstream << *it;
		if (values.end() != ++it)
			sstream << ", ";
	}
	sstream << " );";
	return sstream.str();
}

