#include "SQLTalker.h"
#include <cassert>
#include <iostream>
#include<map>
#include <string>




SQLPrepare* SQLTalker::Prepare()
{
	return new SQLPrepare;
}

SQLTalker::SQLTalker()
{
}
