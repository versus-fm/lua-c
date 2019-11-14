#pragma warning(disable:4996)
#include <iostream>
#include "binary.tab.hh"
#include <stack>
#include <fstream>
#include <map>
#include "UnaryOperator.h"
#include "BinaryOperator.h"
#include "Sequence.h"
#include <sstream>
#include "Compiler.h"
#include <algorithm>

extern unsigned int total;
extern Sequence *root;
extern FILE * yyin;

void dump(BasicBlock*, std::string&);

void yy::parser::error(std::string const&err)
{
	std::cout << "It's one of the bad ones... " << err << std::endl;
}

int main(int argc, char **argv)
{
	//std::list<std::string> testcases;
	//testcases.push_back("testcase1.lua");
	//testcases.push_back("testcase2.lua");
	//testcases.push_back("testcase3.lua");
	//testcases.push_back("testcase4.lua");
	//testcases.push_back("testcase5.lua");
	//testcases.push_back("testcase6.lua");
	//int j = testcases.size();
	//for (int i = 0; i < j; i++)
	//{
	//	auto testcase = testcases.front();
	//	testcases.pop_front();

	//	FILE *file = fopen(testcase.c_str(), "r");
	//	if (!file) {
	//		std::cout << "Invalid file " << testcase << std::endl;
	//		return -1;
	//	}
	//	yyin = file;

	//	yy::parser parser;
	//	if (!parser.parse())
	//	{
	//		Plotter plotter;
	//		PlotNode node;
	//		root->plot(plotter, node);
	//		plotter.write("result-" + testcase + ".dot");

	//		std::cout << "===========" << testcase << "===========" << std::endl << std::endl;

	//		Translator::createInstance();
	//		auto block = Translator::getInstance()->newProcedure("main");
	//		root->translate(block);
	//		std::string result = "digraph {\n";
	//		auto procedures = Translator::getInstance()->getProcedures();
	//		for (auto &procedure : *procedures)
	//		{
	//			dump(procedure, result);
	//		}
	//		result += "}";

	//		std::ofstream out("cfg-" + testcase + ".dot");
	//		out << result;
	//		out.close();


	//		Compiler compiler = Compiler(Translator::getInstance());
	//		for (auto &procedure : *procedures)
	//		{
	//			compiler.createFunction(procedure);
	//			compiler.compileBlock();
	//			compiler.buildFunction();
	//		}
	//		auto code = compiler.build();

	//		std::ofstream outcode("target-" + testcase + ".cc");
	//		outcode << code;
	//		outcode.close();


	//		std::cout << "===================================" 
	//			<< std::endl << "###################################" << std::endl;
	//	}
	//}
	auto testcase = argv[1];

	FILE *file = fopen(testcase, "r");
	if (!file) {
		std::cout << "Invalid file " << testcase << std::endl;
		return -1;
	}
	yyin = file;

	yy::parser parser;
	if (!parser.parse())
	{
		Plotter plotter;
		PlotNode node;
		root->plot(plotter, node);
		plotter.write("tree.dot");

		Translator::createInstance();
		auto block = Translator::getInstance()->newProcedure("main");
		root->translate(block);
		std::string result = "digraph {\n";
		auto procedures = Translator::getInstance()->getProcedures();
		for (auto &procedure : *procedures)
		{
			dump(procedure, result);
		}
		result += "}";

		std::ofstream out("cfg.dot");
		out << result;
		out.close();


		Compiler compiler = Compiler(Translator::getInstance());
		for (auto &procedure : *procedures)
		{
			compiler.createFunction(procedure);
			compiler.compileBlock();
			compiler.buildFunction();
		}
		auto code = compiler.build();

		std::ofstream outcode("target.cc");
		outcode << code;
		outcode.close();
	}

}

void dump(BasicBlock *start, std::string &result)
{
	std::set<BasicBlock *> done, todo;
	todo.insert(start);
	while (todo.size()>0)
	{
		auto first = todo.begin();
		BasicBlock *next = *first;
		todo.erase(first);
		std::stringstream adr;
		adr << next;
		std::string dump = next->dump();
		dump.erase(remove(dump.begin(), dump.end(), '\"'), dump.end());
		result += "\"" + adr.str() + "\" [label=\"" + dump + "\"]\n";
		done.insert(next);
		if (next->tExit != nullptr && done.find(next->tExit) == done.end())
		{
			std::stringstream adr2;
			adr2 << next->tExit;
			result += "\"" + adr.str() + "\" -> \"" + adr2.str() + "\"\n";
			todo.insert(next->tExit);
		}
		else if (next->tExit != nullptr) {
			std::stringstream adr2;
			adr2 << next->tExit;
			result += "\"" + adr.str() + "\" -> \"" + adr2.str() + "\"\n";
		}
			
		if (next->fExit != nullptr && done.find(next->fExit) == done.end())
		{
			std::stringstream adr2;
			adr2 << next->fExit;
			result += "\"" + adr.str() + "\" -> \"" + adr2.str() + "\"\n";
			todo.insert(next->fExit);
		}
		else if (next->fExit != nullptr) {
			std::stringstream adr2;
			adr2 << next->fExit;
			result += "\"" + adr.str() + "\" -> \"" + adr2.str() + "\"\n";
		}
			
	}
}

Translator *Translator::instance = nullptr;

std::map<UnaryOperator::UnaryType, std::string> UnaryOperator::opNames =
{
	{ UnaryOperator::Count, "#" },
	{ UnaryOperator::Neg, "-" },
	{ UnaryOperator::Not, "!" },
};

std::map<BinaryOperator::BinaryType, std::string> BinaryOperator::opNames =
{
	{ BinaryOperator::Add, "+" },
	{ BinaryOperator::Sub, "-" },
	{ BinaryOperator::Mul, "*" },
	{ BinaryOperator::Div, "/" },
	{ BinaryOperator::Mod, "%" },
	{ BinaryOperator::Pow, "pow" },
	{ BinaryOperator::Greater, ">" },
	{ BinaryOperator::Lesser, "<" },
	{ BinaryOperator::GreaterEquals, ">=" },
	{ BinaryOperator::LesserEquals, "<=" },
	{ BinaryOperator::Equals, "==" },
	{ BinaryOperator::NotEquals, "!=" },
	{ BinaryOperator::Concat, ".." },
	{ BinaryOperator::And, "&&" },
	{ BinaryOperator::Or, "||" },
};

std::map<OpCode, std::string> Instruction::opNames = {
	{ OpCode::Add, "+" },
	{ OpCode::Mul, "*" },
	{ OpCode::Sub, "-" },
	{ OpCode::Div, "/" },
	{ OpCode::Pow, "pow" },
	{ OpCode::AssignArray, "=[]" },
	{ OpCode::FuncCall, "call" },
	{ OpCode::FuncReturn, "return" },
	{ OpCode::Assign, "=" },
	{ OpCode::LesserEquals, "<=" },
	{ OpCode::Mod, "%" },
	{ OpCode::Equals, "==" },
	{ OpCode::ArrayCount, "#" },
	{ OpCode::ArrAccess, "[]" },
	{ OpCode::Greater, ">" },
	{ OpCode::Lesser, "<" },
	{ OpCode::Arg, "arg" },
};