#pragma once
#include "Expression.h"
class ExpressionList 
	: public Expression
{
public:
	std::list<Expression*> expressions;
	ExpressionList()
	{
		expressions = std::list<Expression*>();
	}
	~ExpressionList()
	{
	}
	std::string translate(BasicBlock *out)
	{
		for (auto expression : expressions) {
			name = expression->translate(out);
		}
		return name;
	}
	void plot(Plotter &plotter, PlotNode &parent)
	{
		auto node = plotter.newNode("ExpressionList");
		plotter.map(parent, node);
		for (auto expression : expressions)
		{
			if(expression != nullptr) expression->plot(plotter, node);
		}
	}
};