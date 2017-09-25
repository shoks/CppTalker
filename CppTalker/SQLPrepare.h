#pragma once
//#include<SQLiteCpp/Database.h>
//#include <SQLiteCpp/Statement.h>
#include <list>
#include <algorithm>
#include <vector>
#include<map>

typedef std::map<std::string, std::string>  InsertMap;

struct SQLUpdateBag;

class SQLPrepare
{
public:

	template<typename  T>
	static bool deleter(T element) { delete element; return true; }

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
	InsertMap* insertRequests = nullptr;
	std::list<SQLUpdateBag*> updateRequests;
	std::list<int*> deleteRequests;

protected:

	SQLPrepare();
	void setAccessibleFields(const std::string& _field);
	void setAccessibleFields(const std::vector<std::string>& _fields);
	std::string table;
	std::list<std::string> fields;
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