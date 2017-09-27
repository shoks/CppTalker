#pragma once
#include <string>
#include <map>
#include <atomic>

class SQLWrapper
{
public:
	virtual ~SQLWrapper();

private:

	virtual bool Connect(std::string _dbName);
	virtual bool Connect(std::string _ipAddress, std::_Uint8_t _port, std::string user, std::string pass);
	virtual void Execute(std::string);
	virtual std::map<std::string, std::string> ExecuteWithReturn(std::string);
	virtual bool Close();

};

