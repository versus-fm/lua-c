#pragma once
#include "Statement.h"
#include "Expression.h"
class UnimplementedStatement : public Statement
{
public:
	std::list<Statement*> statements;
	std::list<Expression*> expressions;
};