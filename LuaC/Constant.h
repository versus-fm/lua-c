#pragma once
#include "Expression.h"
#include <string>
class Constant :
	public Expression
{
public:
	std::string type;
	std::string value;
	Constant(std::string type, std::string value) : type(type), value(value) {};
	~Constant() {};
	std::string translate(BasicBlock *out)
	{
		if (type == "string") {
			return "\"" + value + "\"";
		}
		else if (type == "number") {
			double val = std::stod(value.c_str());
			return std::to_string(val);
		}
		else {
			return value;
		}
	}
	void plot(Plotter &plotter, PlotNode &parent)
	{
		auto node = plotter.newNode("Constant: " + value);
		plotter.map(parent, node);
	}
};

