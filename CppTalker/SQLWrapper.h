#pragma once
#include <string>
#include <map>
#include <atomic>

class SQLWrapper
{
public:

	virtual ~SQLWrapper();
	virtual bool Connect(const std::string& _dbName);
	virtual bool Connect(const std::string& _ipAddress, const std::_Uint8_t& _port, const std::string& _dbName, const std::pair<std::string, std::string>& _credential);
	virtual void Execute(const std::string& _request);
	virtual std::map<std::string, std::string> ExecuteWithReturn(const std::string& _request);
	virtual bool Close();
};

