#pragma once
//#include<SQLiteCpp/Database.h>
//#include <SQLiteCpp/Statement.h>
#include <list>
#include <algorithm>
#include <vector>
#include<map>
#include "SQLPrepare.h"
#include "SQLConnector.h"
#include "SQLSchema.h"

typedef std::map<std::string, std::string>  InsertMap;

struct SQLUpdateBag;
class SQLTalker;


class SQLTalker: public SQLPrepare, public SQLConnector, public SQLSchema
{
public:
	~SQLTalker() = 0;
	static  SQLPrepare* Prepare();

protected:
	SQLTalker();
	virtual void Migrations() = 0;


};