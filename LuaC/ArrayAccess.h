#pragma once
#include "Expression.h"
#include "Variable.h"
class ArrayAccess
	: public Expression
{
public:
	Expression * exp;
	Expression *index;
	ArrayAccess(Expression *exp, Expression *index) : exp(exp), index(index) 
	{

	}
	std::string translate(BasicBlock *out)
	{
		this->name = Translator::getInstance()->newSymbolName();
		auto arr = exp->translate(out);
		auto i = index->translate(out);
		out->instructions.push_back(Instruction(name, OpCode::ArrAccess, arr, i));
		return name;
	}
	void plot(Plotter &plotter, PlotNode &parent)
	{
		auto node = plotter.newNode("ArrayAccess");
		plotter.map(parent, node);
		exp->plot(plotter, node);
		index->plot(plotter, node);
	}
};
