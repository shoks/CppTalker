#pragma once
#include <list>


struct TableField;
class TableDirector;

enum FieldType
{
	STRING,
	TEXT,
	INTEGER,
	DOUBLE,
	BIGINTEGER,
	BOOLEAN,
	TIMESTAMP
};


struct TableField
{
	static std::string ProcessType(const FieldType& _type);
	TableDirector* parentTable;
	bool isPrimary = false;
	bool isAuto = false;
	std::string name;
	FieldType type;
	unsigned int max;
	bool isNull = false;
};


class TableDirector
{
protected:
	virtual ~TableDirector();
	explicit TableDirector(std::string _name);
	void SetName(std::string _name);
	TableDirector* AddColumn(const std::string& _name, const FieldType& _type, const bool& _isPrimaryKey, const bool& _isAuto);
	TableDirector* AddColumn(const std::string& _name, const FieldType& _type, const int& _max = 255, const bool& _isNull = false);
	TableDirector* AddColumn(const std::string& _name, const FieldType& _type, const bool& _isNull = false);
	//TableDirector* AddColumn(const std::string& _name, const FieldType& _type);
	bool primaryKeyLock = false;
	std::list<TableField> childFields;
	std::string name;
	bool defaultTimeFields = true;
	//random value of migration version to change manually after each new update
	int migrationVersion;


	TableDirector();
};


class SQLSchema: protected TableDirector
{
public:
	SQLSchema();
	~SQLSchema();
};
