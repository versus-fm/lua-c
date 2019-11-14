#pragma once
#include <string>
#include <map>
#include <sstream>
#include <iostream>
enum OpCode 
{
	Add, Sub, Mul, Div, Pow, Assign, Mod, AssignArray, 
	FuncCall, Lesser, FuncReturn, LesserEquals, 
	Equals, ArrayCount, ArrAccess, Greater, Arg
};
class Instruction
{
private:
	static std::map<OpCode, std::string> opNames;
public:
	std::string name, lhs, rhs;
	OpCode op;

	Instruction(std::string name, OpCode op, std::string lhs, std::string rhs) :
		name(name), op(op), lhs(lhs), rhs(rhs)
	{
	}

	std::string dump()
	{
		std::stringstream ss;
		ss << name << " <- ";
		ss << lhs << " " << opNames[op] << " " << rhs << "\\l";
		return ss.str();
	}
};


