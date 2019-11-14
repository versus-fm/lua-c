#pragma once
#include <string>
#include <map>
#include "Value.h"
class Translator
{
public:
	~Translator()
	{
	}
	static void createInstance()
	{
		if (Translator::instance != nullptr)
		{
			delete Translator::instance;
		}
		Translator::instance = new Translator();
	}
	static Translator* getInstance()
	{
		return Translator::instance;
	}
	std::string newSymbolName()
	{
		return "_t" + std::to_string(symbolCount++);
	}
	std::string retSymbol()
	{
		return "_ret";
	}
	BasicBlock* newProcedure(std::string name)
	{
		auto block = new BasicBlock();
		block->name = name;
		block->num = 0;
		procedures.emplace(name, block);
		blockCounter++;
		return block;
	}
	BasicBlock* newBlock(BasicBlock *parent, std::string name = "")
	{
		auto block = new BasicBlock();
		if (parent != nullptr)
		{
			block->name = parent->name;
			block->num = blockCounter++;
		}
		else
		{
			block->name = name;
			block->num = 0;
		}
		return block;
	}
	std::list<BasicBlock*>* getProcedures()
	{
		auto list = new std::list<BasicBlock*>();
		for (auto &item : procedures)
		{
			list->push_back(item.second);
		}
		return list;
	}
private:
	static Translator *instance;
	int symbolCount;
	int blockCounter;
	std::map<std::string, BasicBlock*> procedures;
	Translator()
	{
		blockCounter = 0;
		symbolCount = 0;
		procedures = std::map<std::string, BasicBlock*>();
	}

};

