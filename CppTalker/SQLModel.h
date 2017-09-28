#pragma once
#include "SQLTalker.h"

class SQLModel: public SQLTalker 
{
public:
	SQLModel();	
	virtual ~SQLModel();
	virtual void Migration() = 0;	
};

