#include "SQLShema.h"


SQLShema::~SQLShema()
{
}


TableDirector::~TableDirector()
{
}




TableDirector::TableDirector(std::string _name)
{
	name = _name;
}

void TableDirector::SetName(std::string _name)
{
	name = _name;
}

TableDirector* TableDirector::AddColumn(const int& _isPrimaryKey, const std::string& _name, const FieldType& _type, int _max = 255)
{
	TableField field;
	if (_isPrimaryKey && !primaryKeyLock)
	{
		field.isPrimary = _isPrimaryKey;
		primaryKeyLock = true;
	}
	field.name = _name;
	field.type = _type;
	field.max = _max;

	childFields.push_back(field);

	return this;
}

TableDirector* TableDirector::AddColumn(const std::string& _name, const FieldType& _type, const int& _max = 255, const bool& _isNull = false)
{
	TableField field;
	field.name = _name;
	field.type = _type;
	field.max = _max;

	childFields.push_back(field);

	return this;
}

TableDirector* TableDirector::AddColumn(const std::string& _name, const FieldType& _type, const int& _max = 255)
{
	TableField field;
	field.name = _name;
	field.type = _type;
	field.max = _max;

	childFields.push_back(field);

	return this;
}

TableDirector* TableDirector::AddColumn(const std::string& _name, const FieldType& _type)
{
	TableField field;
	field.name = _name;
	field.type = _type;

	childFields.push_back(field);

	return this;
}

TableDirector::TableDirector()
{
}

std::string TableField::ProcessType(const FieldType& _type)
{
	switch (_type)
	{
	case FieldType::STRING:
		return "VARCHAR";
	case FieldType::BOOLEAN:
		return "BOOLEAN";
	default:
		throw std::exception("Bad type of field!");
	}
}
