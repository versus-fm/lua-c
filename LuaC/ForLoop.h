#pragma once
#include "Statement.h"
#include "Expression.h"
#include "Assignment.h"
class ForLoop
	: public Statement
{
public:
	Assignment *assignment;
	Expression *bounds;
	Expression *step;
	Statement *body;

	ForLoop(Assignment *assignment, Expression *bounds, Statement *body, Expression *step = nullptr) 
		: assignment(assignment), bounds(bounds), body(body), step(step) {}

	BasicBlock* translate(BasicBlock *out)
	{
		auto translator = Translator::getInstance();
		auto exit = translator->newBlock(out);
		auto testBlock = translator->newBlock(out);
		auto bodyBlock = translator->newBlock(out);
		testBlock->fExit = exit;
		testBlock->tExit = bodyBlock;
		bodyBlock->tExit = testBlock;
		out->tExit = testBlock;

		assignment->translate(out);
		if (step == nullptr) {
			step = BinaryOperator::createAdd(new Variable(assignment->name), new Constant("number", "1"));
			step->name = assignment->name;
		}

		auto condition = BinaryOperator::createLesserEquals(new Variable(assignment->name), bounds);
		condition->translate(testBlock);
		auto inner = body->translate(bodyBlock);
		inner->tExit = testBlock;
		step->translate(inner);

		return exit;

		//this->cmpExpression->convert(out);
		//auto exit = new BBlock();
		//out->tExit = new BBlock();
		//auto t = trueStatement->convert(out->tExit);
		//t->tExit = exit;
		//if (falseStatement != nullptr)
		//{
		//	out->fExit = new BBlock();
		//	auto f = falseStatement->convert(out->fExit);
		//	f->tExit = exit;
		//}
		//return exit;
	}
	void plot(Plotter &plotter, PlotNode &parent)
	{
		auto node = plotter.newNode("For");
		plotter.map(parent, node);
		assignment->plot(plotter, node);
		bounds->plot(plotter, node);
		if(step != nullptr) step->plot(plotter, node);
		body->plot(plotter, node);
	}
};