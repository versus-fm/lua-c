#pragma once
#include <list>
#include <set>
#include "Instruction.h"
#include <sstream>
class BasicBlock
{
public:
	std::string name;
	int num;
	std::list<Instruction> instructions;
	BasicBlock *tExit;
	BasicBlock *fExit;

	BasicBlock() : tExit(nullptr), fExit(nullptr)
	{
		name = "";
		num = 0;
	}
	~BasicBlock()
	{

	}

	std::string getFullName()
	{
		return name + "_" + std::to_string(num);
	}
	
	std::string dump()
	{
		std::stringstream ss;
		ss << "[" << getFullName() << "]" << "\\l";
		for (auto i : instructions)
			ss << i.dump();
		if (tExit != nullptr) ss << "True:  " << tExit->getFullName() << "\\l";
		if (fExit != nullptr) ss << "False: " << fExit->getFullName() << "\\l";
		return ss.str();
	}
};

