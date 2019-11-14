#pragma once
#include "Statement.h"
#include "Expression.h"
class Return
	: public Statement
{
public:
	Expression *returnVal;
	Return(Expression *returnVal) : returnVal(returnVal) {};
	BasicBlock* translate(BasicBlock *out)
	{
		auto ret = returnVal->translate(out);
		out->instructions.push_back(Instruction(Translator::getInstance()->retSymbol(), OpCode::FuncReturn, ret, ret));
		return out;
	}
	void plot(Plotter &plotter, PlotNode &parent)
	{
		auto node = plotter.newNode("Return");
		plotter.map(parent, node);
		returnVal->plot(plotter, node);
	}
};