#pragma once
#include "Translator.h"
#include <list>
#include <sstream>
#include "BasicBlock.h"
#include <algorithm>
#include <iostream>
#include <vector>
class FunctionCall
{
public:
	int line;
	std::string name;
	std::string target;
	std::string arg;
	FunctionCall()
	{
		line = 0;
		name = "";
		target = "";
		arg = "";
	}
};
class CVar
{
public:
	std::string type;
	std::string name;
	std::string value;
};
class CArray
{
public:
	std::string type;
	std::string name;
	int size;
};
class CFunction
{
public:
	std::string name;
	std::string returnType;
	std::list<CVar*> args;
	std::list<CVar*> vars;
	std::list<CArray*> arrays;
	std::vector<std::string> body;
	std::list<FunctionCall*> functionCalls;
	CFunction()
	{
		name = "";
		returnType = "void";
	}
	CVar *getVar(std::string name)
	{
		CVar *result = nullptr;
		for (auto arg : vars)
		{
			if (arg->name == name)
			{
				result = arg;
			}
		}
		return result;
	}
	CVar *getArg(std::string name)
	{
		CVar *result = nullptr;
		for (auto arg : args)
		{
			if (arg->name == name)
			{
				result = arg;
			}
		}
		return result;
	}
	CArray *getArray(std::string name)
	{
		CArray *result = nullptr;
		for (auto arg : arrays)
		{
			if (arg->name == name)
			{
				result = arg;
			}
		}
		return result;
	}
	std::string build()
	{
		std::stringstream out;
		out << functionHeader() << std::endl;
		out << "{" << std::endl;
		for (auto &arr : arrays)
		{
			out << "    " << arr->type << " *" << arr->name << " = new " << arr->type << "[" << arr->size << "]" << ";" << std::endl;
		}
		for (auto &var : vars)
		{
			if (var->value == "") out << "    " << var->type << " " << var->name << ";" << std::endl;
			else out << "    " << var->type << " " << var->name << " = " << var->value << ";" << std::endl;
		}
		for (auto &line : body)
		{
			out << "    " << line << std::endl;
		}
		out << "}" << std::endl;
		return out.str();
	}
	std::string functionHeader()
	{
		std::stringstream out;
		out << returnType << " " << name << "(";
		bool first = true;
		for (auto &arg : args)
		{
			if (!first)
			{
				out << ", ";
			}
			first = false;
			out << arg->type << " " << arg->name;
		}
		out << ")";
		return out.str();
	}
	void createArg(std::string name, std::string type = "")
	{
		if (type == "")
		{
			type = "double";
		}
		auto arg = new CVar();
		arg->name = name;
		arg->type = type;
		args.push_back(arg);
	}
	bool isArg(std::string name)
	{
		for (auto arg : args)
		{
			if (arg->name == name)
			{
				return true;
			}
		}
		return false;
	}
	void changeArgType(std::string name, std::string type)
	{
		bool changed = false;
		for (auto &arg : args)
		{
			if (arg->name == name)
			{
				arg->type = type;
				changed = true;
			}
		}
		if (!changed)
		{
			createArg(name, type);
		}
	}
	void createVar(std::string name, std::string type, std::string val = "")
	{
		auto var = new CVar();
		var->name = name;
		var->type = type;
		var->value = val;
		vars.push_back(var);
	}
	void tryCreateVar(std::string name, std::string type, std::string val = "")
	{
		if (type == "void") return;
		bool found = false;
		for (auto &var : vars)
		{
			if (var->name == name)
			{
				found = true;
			}
		}
		if (!found)
		{
			createVar(name, type, val);
		}
	}
	void tryCreateArray(std::string name, std::string type, int size)
	{
		if (type == "void") return;
		bool found = false;
		for (auto &arr : arrays)
		{
			if (arr->name == name)
			{
				if (arr->size < size) arr->size = size;
				found = true;
			}
		}
		if (!found)
		{
			createArray(name, type, size);
		}
	}
	void changeArraySize(std::string name, int size)
	{
		for (auto &arr : arrays)
		{
			if (arr->name == name)
			{
				arr->size = size;
			}
		}
	}
	void createArray(std::string name, std::string type, int size)
	{
		auto var = new CArray();
		var->name = name;
		var->type = type;
		var->size = size;
		arrays.push_back(var);
	}
};
class Compiler
{
public:
	BasicBlock * block;
	CFunction * currentFunction;
	std::stringstream output;
	std::stringstream header;
	std::map<std::string, std::string> returnTypes;
	std::list<CFunction*> functions;
	Translator *translatorInstance;
	Compiler(Translator *translatorInstance) : translatorInstance(translatorInstance)
	{
		header << "#include <iostream>" << std::endl;
		header << "#include <cmath>" << std::endl;
		header << "#include <string>" << std::endl;


		header << std::endl 
			   << "void print(std::string text);" << std::endl;
		header << "void print(double val);" << std::endl;
		header << "void iowrite(std::string text);" << std::endl;
		header << "void iowrite(double val);" << std::endl;
		header << "double ioread(std::string text);" << std::endl;


		returnTypes.emplace("print", "void");
		returnTypes.emplace("ioread", "double");
		returnTypes.emplace("iowrite", "void");
	}
	void createFunction(BasicBlock *func)
	{
		functions.push_back(new CFunction());
		currentFunction = functions.back();
		currentFunction->name = func->name;
		if (func->name == "main") {
			currentFunction->returnType = "int";
		}
		block = func;
	}
	void buildFunction()
	{
		if (currentFunction->name != "main") header << currentFunction->functionHeader() << ";" << std::endl;
	}
	std::string resolveReturnType(std::string function)
	{
		if (returnTypes.find(function) == returnTypes.end()) return "void";
		else return returnTypes[function];
	}
	bool isFunctionActive()
	{
		return currentFunction != nullptr;
	}
	std::string build()
	{
		std::map<std::string, std::string> varsToCreate;
		for (auto f : functions)
		{
			for (auto fcall : f->functionCalls)
			{
				auto returnType = resolveReturnType(fcall->name);
				if (returnType == "void")
				{
					f->body[fcall->line] = fcall->name + "(" + fcall->arg + ");";
				}
				else
				{
					varsToCreate.emplace(fcall->target, returnType);
					f->body[fcall->line] = fcall->target + " = " + fcall->name + "(" + fcall->arg + ");";
				}
			}
			for (auto &keyval : varsToCreate)
			{
				f->createVar(keyval.first, keyval.second);
			}
			output << f->build();
		}
		output << "void print(std::string text)" << std::endl <<
			"{" << std::endl <<
			"    std::cout << text << std::endl;" << std::endl <<
			"}" << std::endl;
		output << "void print(double val)" << std::endl <<
			"{" << std::endl <<
			"    std::cout << val << std::endl;" << std::endl <<
			"}" << std::endl;

		output << "void iowrite(std::string text)" << std::endl <<
			"{" << std::endl <<
			"    std::cout << text;" << std::endl <<
			"}" << std::endl;
		output << "void iowrite(double val)" << std::endl <<
			"{" << std::endl <<
			"    std::cout << val;" << std::endl <<
			"}" << std::endl;

		output << "double ioread(std::string text)" << std::endl <<
			"{" << std::endl <<
			"    double d;" << std::endl <<
			"    std::cin >> d;" << std::endl <<
			"    std::cin.clear();" << std::endl <<
			"    return d;" << std::endl <<
			"}" << std::endl;
		return header.str() + output.str();
	}
	void compileBlock()
	{
		if (isFunctionActive())
		{
			std::set<BasicBlock *> done, todo;
			todo.insert(block);
			while (todo.size() > 0)
			{
				auto first = todo.begin();
				BasicBlock *next = *first;
				todo.erase(first);
				currentFunction->body.push_back(next->getFullName() + ":");
				for (auto &i : next->instructions)
				{
					currentFunction->body.push_back(compileInstruction(i));
				}
				done.insert(next);
				if (next->tExit != nullptr && done.find(next->tExit) == done.end())
				{
					if (next->fExit != nullptr)
					{
						auto last = next->instructions.back();
						currentFunction->body.push_back("if(" + last.name + ") goto " + next->tExit->getFullName() + ";");
					}
					else currentFunction->body.push_back("goto " + next->tExit->getFullName() + ";");
					todo.insert(next->tExit);
				}
				else if (next->tExit != nullptr)
				{

					if (next->fExit != nullptr)
					{
						auto last = next->instructions.back();
						currentFunction->body.push_back("if(" + last.name + ") goto " + next->tExit->getFullName() + ";");
					}
					else currentFunction->body.push_back("goto " + next->tExit->getFullName() + ";");
				}

				if (next->fExit != nullptr && done.find(next->fExit) == done.end())
				{
					auto last = next->instructions.back();
					currentFunction->body.push_back("if(!" + last.name + ") goto " + next->fExit->getFullName() + ";");
					todo.insert(next->fExit);
				}
				else if (next->fExit != nullptr)
				{
					auto last = next->instructions.back();
					currentFunction->body.push_back("if(!" + last.name + ") goto " + next->fExit->getFullName() + ";");
				}

				if (next->fExit == nullptr && next->tExit == nullptr)
				{
					if (currentFunction->returnType == "void") currentFunction->body.push_back("return;");
					else currentFunction->body.push_back("return " + currentFunction->returnType + "();");
				}

			}
		}
	}
	std::string getTypeForVal(std::string val)
	{
		auto var = currentFunction->getVar(val);
		if (var != nullptr) return var->type;

		auto arg = currentFunction->getArg(val);
		if (arg != nullptr) return arg->type;

		if (val == "true" || val == "false") return "bool";

		double d;
		if ((std::istringstream(val) >> d >> std::ws).eof())
		{
			return "double";
		}
		else
		{
			return "std::string";
		}
	}
	std::string compileInstruction(Instruction &i)
	{
		std::stringstream out;
		if (i.op == Add) {
			currentFunction->tryCreateVar(i.name, "double");
			out << i.name << " = " << i.lhs << " + " << i.rhs << ";";
			if (currentFunction->isArg(i.lhs)) currentFunction->changeArgType(i.lhs, "double");
			if (currentFunction->isArg(i.rhs)) currentFunction->changeArgType(i.rhs, "double");
		}
		if (i.op == Sub) {
			currentFunction->tryCreateVar(i.name, "double");
			out << i.name << " = " << i.lhs << " - " << i.rhs << ";";
			if (currentFunction->isArg(i.lhs)) currentFunction->changeArgType(i.lhs, "double");
			if (currentFunction->isArg(i.rhs)) currentFunction->changeArgType(i.rhs, "double");
		}
		if (i.op == Mul) {
			currentFunction->tryCreateVar(i.name, "double");
			out << i.name << " = " << i.lhs << " * " << i.rhs << ";";
			if (currentFunction->isArg(i.lhs)) currentFunction->changeArgType(i.lhs, "double");
			if (currentFunction->isArg(i.rhs)) currentFunction->changeArgType(i.rhs, "double");
		}
		if (i.op == Div) {
			currentFunction->tryCreateVar(i.name, "double");
			out << i.name << " = " << i.lhs << " / " << i.rhs << ";";
			if (currentFunction->isArg(i.lhs)) currentFunction->changeArgType(i.lhs, "double");
			if (currentFunction->isArg(i.rhs)) currentFunction->changeArgType(i.rhs, "double");
		}
		if (i.op == Pow) {
			currentFunction->tryCreateVar(i.name, "double");
			out << i.name << " = pow(" << i.lhs << ", " << i.rhs << ");";
			if (currentFunction->isArg(i.lhs)) currentFunction->changeArgType(i.lhs, "double");
			if (currentFunction->isArg(i.rhs)) currentFunction->changeArgType(i.rhs, "double");
		}
		if (i.op == Mod) {
			currentFunction->tryCreateVar(i.name, "double");
			out << i.name << " = std::fmod(" << i.lhs << ", " << i.rhs << ");";
			if (currentFunction->isArg(i.lhs)) currentFunction->changeArgType(i.lhs, "double");
			if (currentFunction->isArg(i.rhs)) currentFunction->changeArgType(i.rhs, "double");
		}
		if (i.op == Assign) {
			std::string assignType = getTypeForVal(i.lhs);
			currentFunction->tryCreateVar(i.name, assignType);
			out << i.name << " = " << i.lhs << ";";
		}
		if (i.op == Greater) {
			currentFunction->tryCreateVar(i.name, "bool");
			out << i.name << " = " << i.lhs << ">" << i.rhs << ";";
			if (currentFunction->isArg(i.lhs)) currentFunction->changeArgType(i.lhs, "double");
			if (currentFunction->isArg(i.rhs)) currentFunction->changeArgType(i.rhs, "double");
		}
		if (i.op == Lesser) {
			currentFunction->tryCreateVar(i.name, "bool");
			out << i.name << " = " << i.lhs << "<" << i.rhs << ";";
			if (currentFunction->isArg(i.lhs)) currentFunction->changeArgType(i.lhs, "double");
			if (currentFunction->isArg(i.rhs)) currentFunction->changeArgType(i.rhs, "double");
		}
		if (i.op == LesserEquals) {
			currentFunction->tryCreateVar(i.name, "bool");
			out << i.name << " = " << i.lhs << "<=" << i.rhs << ";";
			if (currentFunction->isArg(i.lhs)) currentFunction->changeArgType(i.lhs, "double");
			if (currentFunction->isArg(i.rhs)) currentFunction->changeArgType(i.rhs, "double");
		}
		if (i.op == Equals) {
			currentFunction->tryCreateVar(i.name, "bool");
			out << i.name << " = " << i.lhs << "==" << i.rhs << ";";
		}
		if (i.op == FuncCall) {
			std::string name = i.lhs;
			name.erase(remove(name.begin(), name.end(), '.'),name.end());
			auto returnType = resolveReturnType(name);
			if (returnType == "void")
			{
				auto fcall = new FunctionCall();
				fcall->line = currentFunction->body.size();
				fcall->arg = i.rhs;
				fcall->name = name;
				fcall->target = i.name;
				currentFunction->functionCalls.push_back(fcall);
			}
			else
			{
				currentFunction->tryCreateVar(i.name, returnType);
				out << i.name << " = " << name << "(" << i.rhs << ");";
			}
		}
		if (i.op == Arg) {
			currentFunction->createArg(i.name);
		}
		if (i.op == FuncReturn) {
			auto returnType = getTypeForVal(i.lhs);
			currentFunction->returnType = returnType;
			returnTypes.emplace(currentFunction->name, returnType);
			out << "return " << i.lhs << ";";
		}
		if (i.op == AssignArray) {
			auto type = getTypeForVal(i.lhs);
			if((i.rhs.find_first_not_of("0123456789") == std::string::npos)) currentFunction->tryCreateArray(i.name, type, std::stoi(i.rhs) + 1);
			out << i.name << "[(int)(" << i.rhs << ")] = " << i.lhs << ";";
		}
		if (i.op == ArrAccess) {
			auto arr = currentFunction->getArray(i.lhs);
			currentFunction->tryCreateVar(i.name, arr->type);
			out << i.name << " = " << arr->name << "[(int)(" << i.rhs << ")];";
		}
		if (i.op == ArrayCount)
		{
			auto arr = currentFunction->getArray(i.lhs);
			currentFunction->tryCreateVar(i.name, "double");
			out << i.name << " = " << std::to_string(arr->size - 1) << ";";
		}

		return out.str();
	}
};