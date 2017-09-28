#pragma once
#include <vector>
#include "SQLPrepare.h"
#include "SQLConnector.h"
#include "SQLSchema.h"


class SQLModel;

class SQLTalker: public SQLPrepare, public SQLConnector, public SQLSchema
{
public:
	~SQLTalker();
	static SQLPrepare* Prepare();
	static std::vector<SQLModel*> *models;
	static SQLTalker* ModelRegister(SQLModel* _model);
	static void RunMigrations();
private:
	static SQLTalker* instance;
	bool IsMigrationTableExist();
	bool CreateMigrationTable();
	bool FindMigrationTablOrCreate();

	SQLTalker();
protected:
	virtual void Migrations();
};
