#include "SQLConnector.h"



SQLConnector::SQLConnector()
{
	wrapper = new SQLWrapper();
	CallServer();
}

SQLConnector::SQLConnector(const DBServer& _serverType) : serverType(_serverType)
{
	SQLConnector();
}

SQLConnector::SQLConnector(const DBServer& _serverType, const std::string& _dbName): serverType(_serverType), dbName(_dbName)
{
	SQLConnector();
}

SQLConnector::SQLConnector(const DBServer& _serverType, const std::string& _ipAddress, const std::_Uint8_t& _port, const std::string& _dbName) : serverType(_serverType), ipAddress(_ipAddress), port(_port), dbName(_dbName)
{
	SQLConnector();
}

SQLConnector::SQLConnector(const DBServer& _serverType, const std::string& _ipAddress, const std::_Uint8_t& _port, const std::string& _dbName, const std::pair<std::string, std::string>& _credentials) : serverType(_serverType), ipAddress(_ipAddress), port(_port), credential(_credentials)
{
	SQLConnector();
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

bool SQLConnector::IsAlive() const
{
	return alive;
}

void SQLConnector::CallServer()
{

	switch (serverType)
	{
	case SQLITE:
		wrapper = new SQLiteWrapper();
		if (ConnectTo())
			throw(std::exception("Can't connect to SQLite Database!"));		
		break;
	case MYSQL:
		wrapper = new MYSQLWrapper();
		if (ConnectTo())
			throw(std::exception("Can't connect to MySQL Database!"));
		break;
	case PGSQL:
		wrapper = new PGSQLWrapper();
		if (ConnectTo())
			throw(std::exception("Can't connect to PostegreSQL Database!"));
		break;
	case MSQL: break;
	case NOSRV: break;	
	default: ;
	}	
}

bool SQLConnector::ConnectTo()
{
	if (!IsAlive() && serverType != NOSRV && serverType == SQLITE && dbName != "")
	{
		if (wrapper->Connect(dbName))
			return alive = true;		 
	}
	else if (!IsAlive() && serverType != NOSRV && serverType != SQLITE && ipAddress != "" && port > 0 && dbName != "" && credential.first != "")
	{
		if (wrapper->Connect(ipAddress, port, dbName, credential))
		{
			return alive = true;			
		}
	}
	return alive = false;
}
