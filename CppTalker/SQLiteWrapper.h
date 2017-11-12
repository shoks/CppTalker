/**
 * You can download the SQLite Driver at https://www.sqlite.org/download.html
 * and place it to driver directory.
 */
#pragma once
#include "SQLWrapper.h"
class SQLiteWrapper :
	public SQLWrapper
{
public:
	SQLiteWrapper();
	bool Connect(const std::string& _dbName) override;
	void Execute(const std::string& _request) override;
	std::map<std::string, std::string> ExecuteWithReturn(const std::string& _request) override;
	bool Close() override;
	~SQLiteWrapper();
private:


};

