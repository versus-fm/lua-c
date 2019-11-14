#pragma once
#include "Expression.h"
#include <map>
#include "Plotter.h"
#include <string>
class UnaryOperator :
	public Expression
{
public:
	enum UnaryType {
		Count, Neg, Not
	};
	static std::map<UnaryType, std::string> opNames;
	static UnaryOperator* createCount(Expression* rhs)
	{
		return new UnaryOperator(rhs, UnaryType::Count);
	}
	static UnaryOperator* createNeg(Expression* rhs)
	{
		return new UnaryOperator(rhs, UnaryType::Neg);
	}
	static UnaryOperator* createNot(Expression* rhs)
	{
		return new UnaryOperator(rhs, UnaryType::Not);
	}
	Expression* rhs;
	UnaryType optype;
	UnaryOperator(Expression* rhs, UnaryType optype) : optype(optype), rhs(rhs) {};
	~UnaryOperator() {};
	std::string translate(BasicBlock *out)
	{
		if (name == "") name = Translator::getInstance()->newSymbolName();
		auto right = rhs->translate(out);
		switch (optype)
		{
		case Count:
			out->instructions.push_back(Instruction(name, OpCode::ArrayCount, right, right));
			break;
		}
		return name;
	}
	void plot(Plotter &plotter, PlotNode &parent)
	{
		auto node = plotter.newNode(opNames[optype]);
		plotter.map(parent, node);
		rhs->plot(plotter, node);
	}
};

