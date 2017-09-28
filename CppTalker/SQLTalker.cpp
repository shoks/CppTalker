#include "SQLTalker.h"
#include <cassert>
#include <string>
#include "SQLModel.h"


SQLPrepare* SQLTalker::Prepare()
{
	return new SQLPrepare;
}

SQLTalker* SQLTalker::ModelRegister(SQLModel* _model)
{
	if (instance)
	{
		instance = new SQLTalker();
		instance->FindMigrationTablOrCreate();

	}
	models->push_back(std::move(_model));
	return instance;
}

void SQLTalker::RunMigrations()
{
	if (instance->FindMigrationTablOrCreate())
	{
		for (auto i : *models)
		{
			i->Migration();
		}
	}
}

bool SQLTalker::IsMigrationTableExist()
{
	return true;
}

bool SQLTalker::CreateMigrationTable()
{
	return true;
}

bool SQLTalker::FindMigrationTablOrCreate()
{
	if (!instance->IsMigrationTableExist())
	{
		instance->CreateMigrationTable();
	}
	return true;
}

SQLTalker::SQLTalker()
{
}
