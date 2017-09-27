#include "MYSQLWrapper.h"



MYSQLWrapper::MYSQLWrapper()
{
}


MYSQLWrapper::~MYSQLWrapper()
{
	Close();
}

bool MYSQLWrapper::Connect(std::string _dbName)
{
}

bool MYSQLWrapper::Connect(std::string _ipAddress, std::_Uint8_t _port, std::string user, std::string pass)
{
}

void MYSQLWrapper::Execute(std::string)
{
}

std::map<std::string, std::string> MYSQLWrapper::ExecuteWithReturn(std::string)
{
}

bool MYSQLWrapper::Close()
{
}
