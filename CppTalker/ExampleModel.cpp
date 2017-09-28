#include "ExampleModel.h"



ExampleModel::ExampleModel()
{
	table = "users";
	primaryKeys = "id";
	fields = { "id", "name" };
}

ExampleModel::~ExampleModel()
{
}

void ExampleModel::Migration()
{
	AddColumn("id", FieldType::INTEGER, true, true);
	AddColumn("username", FieldType::TEXT, 100);
	AddColumn("password", FieldType::TEXT, 100);

	//random value of migration version to change manually after each new update
	//TODO Automatic methode that check for new migration from the database at each initialization
	migrationVersion = 165416546545646847;
}
