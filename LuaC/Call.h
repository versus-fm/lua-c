#pragma once
#include "Expression.h"
#include <list>
#include "ExpressionList.h"
class Call
	: public Expression
{
public:
	Expression *function;
	Expression *args;
	Call() {};
	~Call() {};
	std::string translate(BasicBlock *out)
	{
		auto func = function->translate(out);
		auto arg = dynamic_cast<ExpressionList*>(args);
		if (arg != nullptr) {
			for (auto &exp : arg->expressions)
			{
				name = Translator::getInstance()->newSymbolName();
				out->instructions.push_back(Instruction(name, OpCode::FuncCall, func, exp->translate(out)));
			}
		}
		else {
			name = Translator::getInstance()->newSymbolName();
			out->instructions.push_back(Instruction(name, OpCode::FuncCall, func, args->translate(out)));
		}
		return name;
	}
	void plot(Plotter &plotter, PlotNode &parent)
	{
		auto node = plotter.newNode("Call");
		plotter.map(parent, node);
		function->plot(plotter, node);
		if(args != nullptr) args->plot(plotter, node);
	}
};