#pragma once
#include "SQLModel.h"

class ExampleModel :
	public SQLModel
{
public:
	ExampleModel();
	~ExampleModel();
	void Migration() override;

};

