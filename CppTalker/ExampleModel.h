#pragma once
#include "SQLTalker.h"
class ExampleModel :
	public SQLTalker
{
public:
	ExampleModel();
	~ExampleModel();

	void Migration();
};

