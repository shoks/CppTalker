#pragma once
#include "SQLTalker.h"
class ExampleModel :
	public SQLTalker
{
public:
	ExampleModel();
	~ExampleModel();


	void Migration();
private:

	std::list<std::string> fields = {"id", "name"};
};

