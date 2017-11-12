#pragma once
#include <string>
#include <vector>

class SQLTalker;
class SQLModel;

template<class TF, class TM>
class SQLRelation
{	
	using SQLRelationMdels = std::vector<TF>;

public:


protected:
	SQLRelation();
	~SQLRelation();


	SQLRelationMdels& HasOne(TF* foreign_model, const std::string& foreign_column, TM& model, const std::string& to_column = "id");

	SQLTalker& HasMany(TF* foreign_model, const std::string& foreign_column, TM& model, const std::string& to_column = "id");

	SQLTalker& BelongsToMany(TF* foreign_model, const std::string& foreign_column, TM& model, const std::string& to_column, const std::string& pivot_table);

	SQLTalker& BelongsToOne(TF* foreign_model, const std::string& foreign_column, TM& model, const std::string& to_column = "id");

private:
	SQLRelationMdels relation_models;

	class HasOne
	{
	public:
		explicit HasOne(TF* foreign_model, const std::string& foreign_column, const std::string& foreign_key);

		TF& operator ()();
		

	private:
		TF* foreign_model = nullptr;
		std::string foreign_column;
		std::string foreign_key;
		int relation_number = 0;
		SQLRelationMdels models;
	};
};





