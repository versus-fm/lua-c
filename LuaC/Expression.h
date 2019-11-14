#pragma once
#include <string>
#include "BasicBlock.h"
#include "Plotter.h"
#include "Translator.h"
class Expression
{
public:
	std::string name;
	Expression() : name("") {};
	Expression(std::string name) : name(name) {};
	~Expression()
	{

	}
	virtual std::string translate(BasicBlock *out)
	{

		return "";
	}
	virtual void plot(Plotter &plotter, PlotNode &parent)
	{

	}
};

