#pragma once
#include "CppTalker/SQLModel.h"

class ExampleModel :
	public SQLModel
{
public:
	ExampleModel();
	~ExampleModel();
	void Migration() override;

};

