#pragma once
#include <list>
#include "BasicBlock.h"
#include "Plotter.h"
#include "Translator.h"
class Statement
{
public:
	std::string name;
	Statement() {};
	~Statement() {};
	virtual BasicBlock* translate(BasicBlock *out)
	{
		return nullptr;
	}
	virtual void plot(Plotter &plotter, PlotNode &parent)
	{

	}
};

