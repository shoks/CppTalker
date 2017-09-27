#pragma once
#include <string>
#include <algorithm>
#include <atomic>
#include <tuple>

class SQLConnector
{
	enum Config
	{
		READ_ONLY,
		READ_WRITE,
		OPEN_CREATE,
		OPEN_URI
	};

	enum DBServer
	{
		SQLITE,
		MYSQL,
		PGSQL,
		MSQL,
		ORACLE,
	};


public:


	static SQLConnector* instance;
	static SQLConnector* Get(const DBServer& _serverType, ...);
	static SQLConnector* Get();



private:
	SQLConnector();
	SQLConnector(const DBServer& _serverType);
	SQLConnector(const DBServer& _serverType, const std::string& dbName);
	SQLConnector(const DBServer& _serverType, const std::string& _ipAddress, const std::_Uint8_t& _port, const std::string& _dbName);
	SQLConnector(const DBServer& _serverType, const std::string& _ipAddress, const std::_Uint8_t& _port, const std::tuple<std::string, std::string, std::string>& _credentials);
	~SQLConnector();

	DBServer serverType;
	std::string ipAddress = "";
	std::_Uint8_t port = 0;
	std::string dbName = "";
	std::string user;
	std::string password;
};
