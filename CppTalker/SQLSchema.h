#pragma once
#include <list>


struct TableField;
struct TableDirector;

enum FieldType
{
	STRING,
	TEXT,
	INTEGER,
	BIGINTEGER,
	BOOLEAN,
	TIMESTAMP
};


struct TableDirector
{
public:

	virtual ~TableDirector();
	explicit TableDirector(std::string _name);
	void SetName(std::string _name);
	TableDirector* AddColumn(const int& _isPrimaryKey, const std::string& _name, const FieldType& _type, int _max = 255);
	TableDirector* AddColumn(const std::string& _name, const FieldType& _type, const int& _max = 255, const bool& _isNull = false);
	TableDirector* AddColumn(const std::string& _name, const FieldType& _type, const int& _max = 255);
	TableDirector* AddColumn(const std::string& _name, const FieldType& _type);

private:

	TableDirector();

	bool primaryKeyLock = false;
	std::list<TableField> childFields;
	std::string name;
	bool defaultTimeFields = true;
};

struct TableField
{
	static std::string ProcessType(const FieldType& _type);
	TableDirector* parentTable;
	bool isPrimary = false;
	std::string name;
	FieldType type;
	unsigned int max;
	bool isNull = false;
};

class SQLSchema: public TableDirector
{
public:
	SQLSchema();
	~SQLSchema();
};
