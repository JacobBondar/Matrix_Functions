#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <sstream>

#include "Operation.h"
#include "ComplexOperation.h"
#include "BasicOperation.h"
#include "Help.h"
#include "Function.h"
#include "Scal.h"
#include "Id.h"
#include "Tran.h"
#include "Matrix.h"

enum ActionType
{
	MINUS,
	COMP,
	PLUS
};

const std::string EVAL_COMMAND = "eval";
const std::string EXIT_COMMAND = "exit";
const std::string HELP_COMMAND = "help";
const std::string DEL_COMMAND = "del";
const std::string COMP_COMMAND = "comp";
const std::string SUB_COMMAND = "sub";
const std::string ADD_COMMAND = "add";
const std::string SCAL_COMMAND = "scal";
const std::string PLUS_SIGN = "+";
const std::string MINUS_SIGN = "-";
const std::string COMP_SIGN = "->";
const int MIN_SIZE_MATRIX = 1;

class Calculator
{
public:
	Calculator();
	void run();

private:
	std::vector<std::shared_ptr<Operation>> m_operations;
	std::vector<std::shared_ptr<Function>> m_functions;
	std::vector<std::shared_ptr<Action>> m_actions;

	void creatingActions();
	void checkCommand();
	void creatingVectorFunctions();
	void creatingDefaultMenu();
	void creatingNewCommand(std::string action, std::shared_ptr<Action> actionPtr);
	void evaluate(std::string command);
	void printOperations();
	void exitFunc();
	void helpFunc();
	void delFunc();
	void scalFunc(std::string command);
	float convertStringToInt(std::string action);
	bool invalidOperation(int operation, int size);
	void insertNewCommand(unsigned int firstActionNum,
						  unsigned int secondActionNum,
						  std::string action, std::shared_ptr<Action> actionPtr);
};