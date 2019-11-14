#pragma once
#include "Statement.h"
#include "Expression.h"
#include "ExpressionList.h"
#include <string>
#include <stack>
#include "ArrayAccess.h"
class Assignment :
	public Statement
{
public:
	Expression *targetExpression;
	Expression *sourceExpression;
	Statement *sourceStatement;

	Assignment(Expression *target, Expression *source) : sourceExpression(source), targetExpression(target) {};
	Assignment(Expression *target, Statement *source) : sourceStatement(source), targetExpression(target) {};
	~Assignment() {};
	BasicBlock* translate(BasicBlock *out)
	{
		bool single;
		std::stack<std::string> targets;
		ExpressionList* targetList = dynamic_cast<ExpressionList*>(targetExpression);
		if (targetList != nullptr) {
			for (auto target : targetList->expressions) {
				targets.push(target->translate(out));
			}
			single = targets.size() == 1;
		}
		else {
			targets.push(targetExpression->translate(out));
			single = true;
		}
		if (sourceStatement != nullptr) {

		}
		else if (sourceExpression != nullptr) {
			std::stack<Expression*> sources;
			ExpressionList* sourceList = dynamic_cast<ExpressionList*>(sourceExpression);
			if (sourceList != nullptr) {
				for (auto source : sourceList->expressions) {
					sources.push(source);
				}
				int count = 0;
				int size = sources.size();
				while (!sources.empty()) {
					if ((size == 1 && single) || !single) {
						auto source = sources.top();
						auto target = targets.top();
						sources.pop();
						targets.pop();
						ArrayAccess* sourceArray = dynamic_cast<ArrayAccess*>(source);
						if (sourceArray != nullptr)
						{
							auto left = sourceArray->exp->translate(out);
							auto right = sourceArray->index->translate(out);

							out->instructions.push_back(Instruction(left, OpCode::AssignArray, target, right));
						}
						else {
							auto st = source->translate(out);
							out->instructions.push_back(Instruction(target, OpCode::Assign, st, st));
						}
						
						name = target;
					}
					else if (single) {
						auto target = targets.top();
						auto source = sources.top();
						sources.pop();
						auto st = source->translate(out);
						out->instructions.push_back(Instruction(target, OpCode::AssignArray, st, std::to_string(size - count)));
						name = target;
						count++;
					}
				}
			}
			else {
				auto source = sourceExpression->translate(out);
				auto target = targets.top();
				out->instructions.push_back(Instruction(target, OpCode::Assign, source, source));
				name = target;
			}
		}
		return out;
	}
	void plot(Plotter &plotter, PlotNode &parent)
	{
		auto node = plotter.newNode("Assignment");
		plotter.map(parent, node);
		targetExpression->plot(plotter, node);
		if (sourceExpression != nullptr) sourceExpression->plot(plotter, node);
		if (sourceStatement != nullptr) sourceStatement->plot(plotter, node);
	}
};

