#include "SQLPrepare.h"
#include <iostream>
#include <string>

SQLPrepare::SQLPrepare()
{
	insertRequests = new InsertMap();
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

	insertRequests->insert(_key, _value);

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

	updateRequests.push_back(updatePack);

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
	deleteRequests.push_back(new int(_PK));

	return this;
}

SQLPrepare* SQLPrepare::Delete(const std::list<int>& _PKs)
{
	for (auto it = _PKs.begin(); _PKs.end() != it; ++it)
	{
		deleteRequests.push_back(new int(*it));
	}

	return this;
}

bool SQLPrepare::HasAnyInsert() const
{
	if (insertRequests->size() > 0)
		return true;
	return false;
}

bool SQLPrepare::HasAnyUpdate() const
{
	if (updateRequests.size() > 0)
		return true;
	return false;
}

bool SQLPrepare::HasAnyDelete() const
{
	if (deleteRequests.size() > 0)
		return true;
	return false;
}

void SQLPrepare::Clear()
{
	insertRequests->clear();
	updateRequests.remove_if(deleter<SQLUpdateBag*>);
	deleteRequests.remove_if(deleter<SQLUpdateBag*>);

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
	return insertRequests;
}

std::string SQLPrepare::GetTableName() const
{
	return table;
}

void SQLPrepare::setAccessibleFields(const std::string& _field)
{
	fields.push_back(_field);
}

void SQLPrepare::setAccessibleFields(const std::vector<std::string>& _fields)
{
	fields.sort();
	fields.assign(_fields.begin(), _fields.end());
}

SQLUpdateBag::SQLUpdateBag(int _PK, InsertMap* _fields)
{
	primaryKey = _PK;
	updateFields.insert(_fields->begin(), _fields->end());
}

int SQLUpdateBag::size() const
{
	return count;
}