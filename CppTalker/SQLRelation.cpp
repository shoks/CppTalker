#include "SQLRelation.h"



template <class TF, class TM>
SQLRelation<TF, TM>::SQLRelation()
{
}

template <class TF, class TM>
std::vector<TF>& SQLRelation<TF, TM>::HasOne(TF* foreign_model, const std::string& foreign_column, TM& model, const std::string& to_column)
{
	std::string foreign_key = model.getID();
	return HasOne(foreign_model, foreign_column, foreign_key)();
}

template <class TF, class TM>
SQLTalker& SQLRelation<TF, TM>::HasMany(TF* foreign_model, const std::string& foreign_column, TM& model, const std::string& to_column)
{
}

template <class TF, class TM>
SQLRelation<TF, TM>::HasOne::HasOne(TF* foreign_model, const std::string& foreign_column, const std::string& foreign_key): foreign_model(foreign_model), foreign_column(foreign_column)
{
}

template <class TF, class TM>
TF& SQLRelation<TF, TM>::HasOne::operator()()
{

}

