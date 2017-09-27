#include "MYSQLWrapper.h"



MYSQLWrapper::MYSQLWrapper()
{
}


MYSQLWrapper::~MYSQLWrapper()
{
	Close();
}

bool MYSQLWrapper::Connect(const std::string& _ipAddress, const std::_Uint8_t& _port, const std::string& _dbName, const std::pair<std::string, std::string>& _credential)
{
}

void MYSQLWrapper::Execute(const std::string& _request)
{
}
