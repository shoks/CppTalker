#include "SQLRequest.h"



SQLRequest::~SQLRequest()
{
}

SQLRequest::SQLRequest(SQLTalker* _instance)
{
	current_talker = _instance;
}

