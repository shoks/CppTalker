#pragma once
#include "SQLWrapper.h"
#include <string>
class MYSQLWrapper :
	public SQLWrapper
{
public:
	MYSQLWrapper();
	virtual ~MYSQLWrapper();

private:
	
	bool Connect(std::string _dbName) override;
	bool Connect(std::string _ipAddress, std::_Uint8_t _port, std::string user, std::string pass) override;
	void Execute(std::string) override;
	std::map<std::string, std::string> ExecuteWithReturn(std::string) override;
	bool Close() override;
	
};

