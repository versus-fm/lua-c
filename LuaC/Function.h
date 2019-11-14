#pragma once
#include "Statement.h"
#include "Expression.h"
class Function
	: public Statement
{
public:
	Expression * args;
	Statement * body;
	Function(Statement *body, Expression *args = nullptr) 
		: body(body), args(args) 
	{
	}
	BasicBlock* translate(BasicBlock *out)
	{
		auto translator = Translator::getInstance();
		auto newProc = translator->newProcedure(name);
		auto arg = args->translate(newProc);
		auto func = body->translate(newProc);
		func->instructions.push_back(Instruction(arg, OpCode::Arg, arg, arg));
		return out;
	}
	void plot(Plotter &plotter, PlotNode &parent)
	{
		auto node = plotter.newNode("Function");
		plotter.map(parent, node);
		if (args != nullptr) args->plot(plotter, node);
		body->plot(plotter, node);
	}
};