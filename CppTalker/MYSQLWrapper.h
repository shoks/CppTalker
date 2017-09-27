#pragma once
#include "SQLWrapper.h"
#include <string>

class MYSQLWrapper :
	public SQLWrapper
{
public:
	MYSQLWrapper();
	virtual ~MYSQLWrapper();

	bool Connect(const std::string& _ipAddress, const std::_Uint8_t& _port, const std::string& _dbName, const std::pair<std::string, std::string>& _credential) override;
	void Execute(const std::string&) override;
	std::map<std::string, std::string> ExecuteWithReturn(const std::string&) override;
	bool Close() override;

private:

	std::string ipAddress;
	std::_Uint8_t port;
	std::string dbName;
	std::string user;
	std::string password;

};
