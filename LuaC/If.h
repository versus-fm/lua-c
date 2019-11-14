#pragma once
#include "Statement.h"
#include "Expression.h"
class If
	: public Statement
{
public:
	Expression *condition;
	Statement *trueStatement;
	Statement *falseStatement;
	If(Expression *condition, Statement *trueStatement, Statement *falseStatement = nullptr)
		: condition(condition), trueStatement(trueStatement), falseStatement(falseStatement) {}
	BasicBlock* translate(BasicBlock *out)
	{
		auto translator = Translator::getInstance();
		condition->translate(out);
		auto exit = translator->newBlock(out);
		out->tExit = translator->newBlock(out);
		auto t = trueStatement->translate(out->tExit);
		t->tExit = exit;
		if (falseStatement != nullptr)
		{
			out->fExit = translator->newBlock(out);
			auto f = falseStatement->translate(out->fExit);
			f->tExit = exit;
		}
		else {
			out->fExit = exit;
		}
		return exit;
	}
	void plot(Plotter &plotter, PlotNode &parent)
	{
		auto node = plotter.newNode("If");
		plotter.map(parent, node);
		condition->plot(plotter, node);
		trueStatement->plot(plotter, node);
		if(falseStatement != nullptr) falseStatement->plot(plotter, node);
	}
};