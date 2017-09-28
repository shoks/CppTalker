#pragma once
#include <exception>


class SQLException: public std::exception
{
	const char* _Message = "SQL error!";
};

class SQLConnectionException: public std::exception
{
	const char* _Message = "SQL connection error!";
};

class SQLMigrationException : public std::exception
{
	const char* _Message = "SQL migration error!";
};

class SQLMigrationTableNotExistException: public std::exception
{
	const char* _Message = "SQL migration table don't exist!";
};

