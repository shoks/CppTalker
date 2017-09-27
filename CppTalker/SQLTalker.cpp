#include "SQLTalker.h"
#include <cassert>
#include <iostream>
#include<map>
#include <string>


SQLTalker::SQLTalker(const std::string& DBNAME)
{
	//SQLite::Database    db(DBNAME, SQLite::OPEN_READWRITE);
}


SQLPrepare* SQLTalker::Prepare()
{
	return new SQLPrepare;
}