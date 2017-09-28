#pragma once
//#include<SQLiteCpp/Database.h>
//#include <SQLiteCpp/Statement.h>
#include <list>
#include <algorithm>
#include <vector>
#include<map>



typedef std::map<std::string, std::string>  InsertMap;

struct SQLUpdateBag;

	template<typename  T>
	static bool deleter(T element) { delete element; return true; }

class SQLPrepare
{
public:
	SQLPrepare* Add(const std::string& _key, const std::string& value);
	SQLPrepare* Add(const std::string& _key, const int& _value);
	SQLPrepare* Add(const std::string& _key, const double& _value);
	SQLPrepare* Update(const int& _PK, InsertMap* _fields);
	SQLPrepare* Update(const std::map<int, InsertMap*>& _fields);
	SQLPrepare* Delete(const int& _PK);
	SQLPrepare* Delete(const std::list<int>& _PKs);
	bool HasAnyInsert() const;
	bool HasAnyUpdate() const;
	bool HasAnyDelete() const;
	void Clear();
	bool IsClean() const;
	static bool Clear(SQLPrepare& _preparation);
	InsertMap* GetInsertRequest() const;
	std::string GetTableName() const;

private:
	InsertMap* preparedInserts = nullptr;
	std::list<SQLUpdateBag*> preparedUpdates;
	std::list<int*> preparatedDeletes;

protected:
	SQLPrepare();
	void SetAccessibleFields(const std::string& _field);
	void SetAccessibleFields(const std::vector<std::string>& _fields);
	void SetTableName(const std::string& _tableName);
	void SetPrimaryKey(const std::string& _PrimaryKey);
	std::list<std::string> fields;
	std::string table;
	std::string primaryKeys = "id";

	friend class SQLTalker;
};

struct SQLUpdateBag
{
	SQLUpdateBag(int _PK, InsertMap* _fields);
	InsertMap updateFields;
	int primaryKey;
	int count;
	int size() const;
};