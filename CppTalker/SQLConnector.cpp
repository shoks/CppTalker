#include "SQLConnector.h"
#include "SQLGenerator.h"
#include <cstdarg>


SQLConnector::SQLConnector()
{
}

SQLConnector::SQLConnector(const DBServer& _serverType): serverType(_serverType)
{
}

SQLConnector::SQLConnector(const DBServer& _serverType, const std::string& _dbName): serverType(_serverType), dbName(_dbName)
{
}

SQLConnector::SQLConnector(const DBServer& _serverType, const std::string& _ipAddress, const std::_Uint8_t& _port, const std::string& _dbName) : serverType(_serverType), ipAddress(_ipAddress), port(_port), dbName(_dbName)
{
	
}

SQLConnector::SQLConnector(const DBServer& _serverType, const std::string& _ipAddress, const std::_Uint8_t& _port, const std::tuple<std::string, std::string, std::string>& _credentials) : serverType(_serverType), ipAddress(_ipAddress), port(_port)
{
	std::tie(dbName, user, password) = _credentials;
}


SQLConnector::~SQLConnector()
{
}

//HACK trying vriable parameter
//XXX It can be confusing
//TODO Reimplement it in a common way

SQLConnector* SQLConnector::Get(const DBServer& _serverType, ...)
{
	if (!instance)
	{
		va_list args;
		va_start(args, _serverType);
		instance = new SQLConnector(_serverType, args);
		va_end(args);
	}
	return instance;
}

SQLConnector* SQLConnector::Get()
{
	if (!instance)
	{
		instance = new SQLConnector();
	}
	return instance;
}



