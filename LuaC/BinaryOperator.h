#pragma once
#include "Expression.h"
#include <map>
class BinaryOperator : public Expression
{
public:
	enum BinaryType {
		Add, Sub, Mul, Div, Mod, Pow, Greater, 
		Lesser, GreaterEquals, LesserEquals, 
		Equals, NotEquals, Concat, And, Or
	};
	static std::map<BinaryType, std::string> opNames;
	Expression* lhs;
	Expression* rhs;
	BinaryType optype;
	static BinaryOperator* createAdd(Expression* lhs, Expression* rhs)
	{
		return new BinaryOperator(lhs, rhs, BinaryType::Add);
	}
	static BinaryOperator* createSub(Expression* lhs, Expression* rhs)
	{
		return new BinaryOperator(lhs, rhs, BinaryType::Sub);
	}
	static BinaryOperator* createMul(Expression* lhs, Expression* rhs)
	{
		return new BinaryOperator(lhs, rhs, BinaryType::Mul);
	}
	static BinaryOperator* createDiv(Expression* lhs, Expression* rhs)
	{
		return new BinaryOperator(lhs, rhs, BinaryType::Div);
	}
	static BinaryOperator* createMod(Expression* lhs, Expression* rhs)
	{
		return new BinaryOperator(lhs, rhs, BinaryType::Mod);
	}
	static BinaryOperator* createPow(Expression* lhs, Expression* rhs)
	{
		return new BinaryOperator(lhs, rhs, BinaryType::Pow);
	}
	static BinaryOperator* createGreater(Expression* lhs, Expression* rhs)
	{
		return new BinaryOperator(lhs, rhs, BinaryType::Greater);
	}
	static BinaryOperator* createLesser(Expression* lhs, Expression* rhs)
	{
		return new BinaryOperator(lhs, rhs, BinaryType::Lesser);
	}
	static BinaryOperator* createGreaterEquals(Expression* lhs, Expression* rhs)
	{
		return new BinaryOperator(lhs, rhs, BinaryType::GreaterEquals);
	}
	static BinaryOperator* createLesserEquals(Expression* lhs, Expression* rhs)
	{
		return new BinaryOperator(lhs, rhs, BinaryType::LesserEquals);
	}
	static BinaryOperator* createEquals(Expression* lhs, Expression* rhs)
	{
		return new BinaryOperator(lhs, rhs, BinaryType::Equals);
	}
	static BinaryOperator* createNotEquals(Expression* lhs, Expression* rhs)
	{
		return new BinaryOperator(lhs, rhs, BinaryType::NotEquals);
	}
	static BinaryOperator* createConcat(Expression* lhs, Expression* rhs)
	{
		return new BinaryOperator(lhs, rhs, BinaryType::Concat);
	}
	static BinaryOperator* createAnd(Expression* lhs, Expression* rhs)
	{
		return new BinaryOperator(lhs, rhs, BinaryType::And);
	}
	static BinaryOperator* createOr(Expression* lhs, Expression* rhs)
	{
		return new BinaryOperator(lhs, rhs, BinaryType::Or);
	}
	BinaryOperator(Expression* lhs, Expression* rhs, BinaryType optype) : lhs(lhs), rhs(rhs), optype(optype) {};
	~BinaryOperator() {};

	std::string translate(BasicBlock *out)
	{
		if(name == "") name = Translator::getInstance()->newSymbolName();
		auto left = lhs->translate(out);
		auto right = rhs->translate(out);
		switch (optype)
		{
		case Add:
			out->instructions.push_back(Instruction(name, OpCode::Add, left, right));
			break;
		case Mul:
			out->instructions.push_back(Instruction(name, OpCode::Mul, left, right));
			break;
		case Sub:
			out->instructions.push_back(Instruction(name, OpCode::Sub, left, right));
			break;
		case Div:
			out->instructions.push_back(Instruction(name, OpCode::Div, left, right));
			break;
		case Pow:
			out->instructions.push_back(Instruction(name, OpCode::Pow, left, right));
			break;
		case Mod:
			out->instructions.push_back(Instruction(name, OpCode::Mod, left, right));
			break;
		case Equals:
			out->instructions.push_back(Instruction(name, OpCode::Equals, left, right));
			break;
		case Greater:
			out->instructions.push_back(Instruction(name, OpCode::Greater, left, right));
			break;
		case Lesser:
			out->instructions.push_back(Instruction(name, OpCode::Lesser, left, right));
			break;
		case LesserEquals:
			out->instructions.push_back(Instruction(name, OpCode::LesserEquals, left, right));
		}

		return name;
	}

	void plot(Plotter &plotter, PlotNode &parent)
	{
		auto node = plotter.newNode(opNames[optype]);
		plotter.map(parent, node);
		lhs->plot(plotter, node);
		rhs->plot(plotter, node);
	}
};


