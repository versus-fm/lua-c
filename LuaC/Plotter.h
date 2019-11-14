#pragma once
#include <string>
#include <list>
#include <fstream>
class PlotNode
{
public:
	std::string name;
	std::string content;

	bool operator ==(PlotNode &other)
	{
		return name == other.name && content == other.content;
	}
};
class Plotter
{
public:
	std::list<std::string> graph;
	int count = 0;
	Plotter() 
	{ 
		graph.push_back("digraph {");
	};
	~Plotter() { };
	PlotNode newNode(std::string content)
	{
		PlotNode node;
		node.content = content;
		node.name = std::to_string(count++);
		graph.push_back("  " + node.name + "[label=\"" + node.content + "\"];");
		return node;
	}
	void map(PlotNode &from, PlotNode &to)
	{
		auto def = PlotNode();
		if (from == def || to == def) return;
		graph.push_back("  " + from.name + " -> " + to.name);
	}
	void write(std::string path)
	{
		graph.push_back("}"); 
		std::ofstream out(path);
		for (auto line : graph)
		{
			out << line << std::endl;
		}
		out.close();
	}
};