#pragma once
#include <list>
#include <vector>
#include <map>
#include "SQLModel.h"

class SQLTalker;
class SQLRequest;
enum class ResultOrdering
{
	ASC,
	DESC,
};
enum class Operand
{
	MORET, //More than
	LESST, //Less than
	MOREQ, //More or Equal
	LESSQ, //Less or Equal
	EQUAL, //Equal
	NOTEQ, //Not Equal '<>'. For some SGBD
	LIKE,
	IN,
	NOTIN,
	BETWEEN,
	NOTBETWEEN,
	ISNULL,
	AND,
	OR,
};

struct ClauseBag
{
	enum OpType
	{
		TEXT,
		INTEGER,
		DOUBLE,
	};
	std::string column;
	Operand operand;
	Operand prepend;
	OpType type;
	bool wildcard;
	
	union elements
	{
		int i_value;
		std::string s_value;
		double d_value;
		std::pair<std::string, std::string> ps_values;
		std::vector<std::string> vs_values;
		std::pair<int, int> pi_values;
		std::vector<int> vi_values;
		std::pair<double, double> pd_values;
		std::vector<double> vd_values;
	};
};

class SQLRequest
{

	typedef long long UUID_t;
public:
	~SQLRequest();
	//SQLRequest* find(const int& _PK);
	static SQLTalker* Find(int _PK);

	//Compose the SELECT operand
	std::vector<std::map<std::string, std::string>> GetAll();
	std::vector<std::map<std::string, std::string>> Get(const int& _limit);
	std::vector<std::string> Get(const std::string _column, const int& _limit = 0);
	std::vector<std::map<std::string, std::string>> Get(const std::vector<std::string>& _columns, const int& _limit = 0);
	std::vector<std::string> GetUnique(const std::string _column);
	std::vector<std::map<std::string, std::string>> GetUnique(const std::vector<std::string>& _columns);

	//Compose the WHERE operand
	SQLTalker* Where(const std::string& _column);
	SQLTalker* Where(const std::string& _column, const std::string& value);
	SQLTalker* WhereAny(const std::string& _column, const std::string& value);
	SQLTalker* Where(const std::string& _column, const int& value);
	SQLTalker* Where(const std::string& _column, const double& value);
	SQLTalker* Where(const std::string& _column, const bool& value);
	SQLTalker* Where(const std::string& _column, const Operand& _operator ,const std::string& value);
	SQLTalker* Where(const std::string& _column, const Operand& _operator, const std::vector<std::string>& _values);
	SQLTalker* Where(const std::string& _column, const Operand& _operator, const std::pair<int, int>& _values);
	SQLTalker* Where(const std::string& _column, const Operand& _operator ,const int& value);
	SQLTalker* Where(const std::string& _column, const Operand& _operator ,const double& value);
	SQLTalker* Where(const std::string& _column, const Operand& _operator ,const bool& value);
	SQLTalker* WhereNo(const std::string& _column);

	//Compose the WHERE operand prepended with OR 
	SQLTalker* OrWhere(const std::string& _column);
	SQLTalker* OrWhere(const std::string& _column, const std::string& value);
	SQLTalker* OrWhere(const std::string& _column, const int& value);
	SQLTalker* OrWhere(const std::string& _column, const double& value);
	SQLTalker* OrWhere(const std::string& _column, const bool& value);
	SQLTalker* OrWhere(const std::string& _column, const Operand& _operator, const std::string& value);
	SQLTalker* OrWhere(const std::string& _column, const Operand& _operator, const std::vector<std::string>& _values);
	SQLTalker* OrWhere(const std::string& _column, const Operand& _operator, const int& value);
	SQLTalker* OrWhere(const std::string& _column, const Operand& _operator, const double& value);
	SQLTalker* OrWhere(const std::string& _column, const Operand& _operator, const bool& value);
	SQLTalker* OrWhereNo(const std::string& _column);

	//Compose the result order
	SQLTalker* GroupBy(const std::string& _column);
	SQLTalker* OrderBy(const std::string& _column);
	SQLTalker* OrderBy(std::pair<std::string, ResultOrdering>);
	SQLTalker* OrderBy(const std::vector<std::string>&);
	SQLTalker* OrderBy(const std::vector<std::pair<std::string, ResultOrdering>>&);

	//Aggregate functions: maximum, minimum, Average, count, sum value of column
	double Min(const std::string& _column);
	double Max(const std::string& _column);
	double Average(const std::string& _column);
	int Count();
	int Count(const std::string& _column);

	//Join a relationship with a model
	SQLTalker* Join(SQLModel* _model);

	//Implement HAVING COUNT
	SQLTalker* WithMoreThan(const int& _number);
	SQLTalker* WithLessThan(const int& _number);

	friend struct ClmauseBag;

private:

	//TODO for future implementation of other SQLDB

	//union PrimaryKey
	//{
	//	int I;
	//	UUID_t uuid;
	//};

	std::vector<std::pair<std::string, ResultOrdering>> Order;
	std::vector<ClauseBag> clauses;
	std::vector<std::string> columns;

	int PrimaryKey;

protected:
	SQLRequest(SQLTalker* _instance);
	SQLTalker* current_talker;
};

