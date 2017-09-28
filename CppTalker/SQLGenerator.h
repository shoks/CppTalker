#pragma once
#include <map>
#include "SQLTalker.h"


typedef std::map<std::string, std::string>  InsertMap;

class SQLGenerator
{
public:

	explicit SQLGenerator(SQLPrepare& _prepared);
	~SQLGenerator();
	bool ProcessRequests(SQLPrepare& _prepared);

private:
	void Start();
	std::string requestString;
	SQLPrepare& prepared;
	std::pair<std::list<std::string>, std::list<std::string>> ProcessInsert(InsertMap*);
	std::string InsertFormatter(std::pair<std::list<std::string>, std::list<std::string>> _insertLine);

};

