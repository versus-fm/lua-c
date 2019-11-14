#pragma once
#include "Statement.h"
#include "Call.h"
class CallStatement
	: public Statement
{
public:
	Call *call;
	CallStatement(Call *call) : call(call) {};
	BasicBlock* translate(BasicBlock *out)
	{
		call->translate(out);
		return out;
	}
	void plot(Plotter &plotter, PlotNode &parent)
	{
		auto node = plotter.newNode("CallStatement");
		plotter.map(parent, node);
		call->plot(plotter, node);
	}
};