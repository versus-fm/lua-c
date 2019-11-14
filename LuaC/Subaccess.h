#pragma once
#include "Expression.h"
#include "Variable.h"
class Subaccess
	: public Expression
{
public:
	Expression *exp;
	Variable *last;
	Subaccess(Expression *exp, Variable *last) : Expression(name), exp(exp), last(last) {};
	std::string translate(BasicBlock *out)
	{
		return exp->translate(out) + "." + last->translate(out);
	}
	void plot(Plotter &plotter, PlotNode &parent)
	{
		auto node = plotter.newNode("SubAccess");
		plotter.map(parent, node);
		exp->plot(plotter, node);
		last->plot(plotter, node);
	}
};