#include "ExampleModel.h"



ExampleModel::ExampleModel()
{
}


ExampleModel::~ExampleModel()
{
}

void ExampleModel::Migration()
{
	AddColumn("id", FieldType::INTEGER, true, true);
	AddColumn("name", FieldType::TEXT, 100);
}
