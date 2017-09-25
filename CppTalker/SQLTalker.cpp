#include "SQLTalker.h"
#include <cassert>
#include <iostream>
#include<map>
#include <string>


SQLTalker::SQLTalker(const std::string& DBNAME)
{
	//SQLite::Database    db(DBNAME, SQLite::OPEN_READWRITE);
}



SQLTalker * SQLTalker::GetDB()
{
	if (!instance)
	{

		instance = new SQLTalker(DBNAME);
	}
	return instance;
}


SQLPrepare* SQLTalker::Prepare()
{
	return new SQLPrepare;
}