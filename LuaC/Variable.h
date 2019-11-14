#pragma once
#include "Expression.h"
class Variable
	: public Expression
{
public:
	Variable(std::string name) : Expression(name) {};
	std::string translate(BasicBlock *out)
	{
		return name;
	}
	void plot(Plotter &plotter, PlotNode &parent)
	{
		auto node = plotter.newNode(name);
		plotter.map(parent, node);
	}
};