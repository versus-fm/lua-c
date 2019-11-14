#pragma once
#include "Statement.h"
#include "Expression.h"
#include "Assignment.h"
class Repeat
	: public Statement
{
public:
	Expression *condition;
	Statement *body;

	Repeat(Expression *condition, Statement *body)
		: condition(condition), body(body) {}

	BasicBlock* translate(BasicBlock *out)
	{
		auto translator = Translator::getInstance();
		auto exit = translator->newBlock(out);
		auto testBlock = translator->newBlock(out);
		auto bodyBlock = translator->newBlock(out);
		testBlock->fExit = bodyBlock;
		testBlock->tExit = exit;
		bodyBlock->tExit = testBlock;
		out->tExit = bodyBlock;

		condition->translate(testBlock);
		auto inner = body->translate(bodyBlock);
		if (inner != bodyBlock) {
			inner->tExit = testBlock;
		}

		return exit;
	}
	void plot(Plotter &plotter, PlotNode &parent)
	{
		auto node = plotter.newNode("Repeat");
		plotter.map(parent, node);
		body->plot(plotter, node);
		condition->plot(plotter, node);
	}
};