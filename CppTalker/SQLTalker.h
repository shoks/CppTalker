#pragma once
//#include<SQLiteCpp/Database.h>
//#include <SQLiteCpp/Statement.h>
#include <list>
#include <algorithm>
#include <vector>
#include<map>
#include "SQLPrepare.h"

typedef std::map<std::string, std::string>  InsertMap;

struct SQLUpdateBag;
class SQLTalker;


class SQLTalker: public SQLPrepare
{
	enum Config
	{
		READ_ONLY,
		READ_WRITE,
		OPEN_CREATE,
		OPEN_URI		
	};


public:
	static SQLTalker* instance;
	static SQLTalker* GetDB();
	~SQLTalker();
	static  SQLPrepare* Prepare();

private:
	explicit SQLTalker(const std::string& dbname);
	static std::string DBNAME;

};