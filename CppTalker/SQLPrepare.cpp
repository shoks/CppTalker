#include "SQLPrepare.h"
#include <iostream>
#include <string>

SQLPrepare::SQLPrepare()
{
	preparedInserts = new InsertMap();
}

SQLPrepare* SQLPrepare::Add(const std::string& _key, const std::string& _value)
{
	try
	{
		auto found = (std::find(fields.begin(), fields.end(), _key) != fields.end());
		if (!found)
			throw std::exception("Add parameter assertion error!");
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}

	preparedInserts->insert(_key, _value);

	return this;
}

SQLPrepare* SQLPrepare::Add(const std::string& key, const int& value)
{
	Add(key, std::to_string(value));

	return this;
}

SQLPrepare* SQLPrepare::Add(const std::string& key, const double& value)
{
	Add(key, std::to_string(value));

	return this;
}

SQLPrepare* SQLPrepare::Update(const int& _PK, InsertMap* _fields)
{
	SQLUpdateBag* updatePack = new SQLUpdateBag(_PK, _fields);
	preparedUpdates.push_back(updatePack);

	return this;
}

SQLPrepare* SQLPrepare::Update(const std::map<int, InsertMap*>& _fields)
{

	for (auto it = _fields.begin(); _fields.end() != it; ++it)
	{
		Update(it->first, &(*it->second));
	}

	return this;
}

SQLPrepare* SQLPrepare::Delete(const int& _PK)
{
	preparatedDeletes.push_back(new int(_PK));

	return this;
}

SQLPrepare* SQLPrepare::Delete(const std::list<int>& _PKs)
{
	for (auto it = _PKs.begin(); _PKs.end() != it; ++it)
	{
		preparatedDeletes.push_back(new int(*it));
	}

	return this;
}

bool SQLPrepare::HasAnyInsert() const
{
	if (preparedInserts->size() > 0)
		return true;

	return false;
}

bool SQLPrepare::HasAnyUpdate() const
{
	if (preparedUpdates.size() > 0)
		return true;

	return false;
}

bool SQLPrepare::HasAnyDelete() const
{
	if (preparatedDeletes.size() > 0)
		return true;

	return false;
}

void SQLPrepare::Clear()
{
	preparedInserts->clear();
	preparedUpdates.remove_if(deleter<SQLUpdateBag*>);
	preparatedDeletes.remove_if(deleter<SQLUpdateBag*>);

	//while (!updateRequests.empty()) delete updateRequests.front(), updateRequests.pop_front();
	//while (!deleteRequests.empty()) delete deleteRequests.front(), deleteRequests.pop_front();
}

bool SQLPrepare::IsClean() const
{
	if (HasAnyInsert() && HasAnyUpdate() && HasAnyDelete())
		return true;

	return false;
}

bool SQLPrepare::Clear(SQLPrepare& _preparation)
{
	_preparation.Clear();

	return _preparation.IsClean();
}

InsertMap* SQLPrepare::GetInsertRequest() const
{
	return preparedInserts;
}

std::string SQLPrepare::GetTableName() const
{
	return table;
}

void SQLPrepare::SetAccessibleFields(const std::string& _field)
{
	fields.push_back(_field);
}

void SQLPrepare::SetAccessibleFields(const std::vector<std::string>& _fields)
{
	fields.sort();
	fields.assign(_fields.begin(), _fields.end());
}

void SQLPrepare::SetTableName(const std::string& _tableName)
{
	table = _tableName;
}

void SQLPrepare::SetPrimaryKey(const std::string& _PrimaryKey)
{
	primaryKeys = _PrimaryKey;
}

SQLUpdateBag::SQLUpdateBag(int _PK, InsertMap* _fields): count(0)
{
	primaryKey = _PK;
	updateFields.insert(_fields->begin(), _fields->end());
}

int SQLUpdateBag::size() const
{
	return count;
}

