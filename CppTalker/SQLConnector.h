#pragma once
#include <string>
#include <algorithm>
#include <atomic>
#include <tuple>
#include "SQLWrapper.h"
#include "SQLGenerator.h"
#include <cstdarg>
#include "SQLiteWrapper.h"
#include <memory>
#include "MYSQLWrapper.h"
#include "PGSQLWrapper.h"

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
		NOSRV,
		SQLITE,
		MYSQL,
		PGSQL,
		MSQL,
	};


public:


	static SQLConnector* instance;
	static SQLConnector* Get(const DBServer& _serverType, ...);
	static SQLConnector* Get();

	bool IsAlive() const;

private:
	

	void CallServer();
	bool ConnectTo();

	SQLWrapper* wrapper = nullptr;
	DBServer serverType = NOSRV;
	std::string ipAddress = "";
	std::_Uint8_t port = 0;
	std::string dbName = "";
	std::pair<std::string, std::string> credential = {"", ""};
	bool alive = false;
protected:
	SQLConnector();
	SQLConnector(const DBServer& _serverType);
	SQLConnector(const DBServer& _serverType, const std::string& dbName);
	SQLConnector(const DBServer& _serverType, const std::string& _ipAddress, const std::_Uint8_t& _port, const std::string& _dbName);
	SQLConnector(const DBServer& _serverType, const std::string& _ipAddress, const std::_Uint8_t& _port, const std::string& _dbName, const std::pair<std::string, std::string>& _credentials);
	~SQLConnector();

};
