#pragma once
#include "Statement.h"
class Sequence :
	public Statement
{
public:
	std::list<Statement*> statements;
	Sequence() 
	{
		statements = std::list<Statement*>();
	}
	~Sequence() 
	{
	}
	BasicBlock* translate(BasicBlock *out)
	{
		auto control = out;
		for (auto &statement : statements)
		{
			control = statement->translate(control);
		}
		return control;
	}
	void plot(Plotter &plotter, PlotNode &parent)
	{
		auto node = plotter.newNode("Sequence");
		plotter.map(parent, node);
		for (auto &statement : statements)
		{
			if(statement != nullptr) statement->plot(plotter, node);
		}
	}
};

