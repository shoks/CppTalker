#pragma once
#include "SQLWrapper.h"
class PGSQLWrapper :
	public SQLWrapper
{
public:
	PGSQLWrapper();
	~PGSQLWrapper();
};

