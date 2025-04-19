#include <Calculator.h>
#include "Comp.h"
#include "Sub.h"
#include "Add.h"

Calculator::Calculator()
{
	creatingVectorFunctions();
	creatingDefaultMenu();
	creatingActions();
}

//-----------------------------------------------------------------------------

void Calculator::run()
{
	while (true)
	{
		std::cout << "List of available matrix operations:\n";
		printOperations();

		std::cout << "Enter command('help' for the list of available commands): ";
		checkCommand();
	}
}

//-----------------------------------------------------------------------------

void Calculator::printOperations()
{
	for (int index = 0; index < m_operations.size(); index++)
	{
		std::cout << index << ". ";
		m_operations[index]->print();
	}
}

//-----------------------------------------------------------------------------

void Calculator::checkCommand()
{
	std::shared_ptr<Action> actionPtr;
	std::string command;
	std::cin >> command;

	if (command == EVAL_COMMAND) evaluate(command);

	else if (command == EXIT_COMMAND) exitFunc();

	else if (command == HELP_COMMAND) helpFunc();

	else if (command == DEL_COMMAND) delFunc();

	else if (command == COMP_COMMAND)
	{
		actionPtr = m_actions[COMP];
		creatingNewCommand("->", actionPtr);
	}

	else if (command == SUB_COMMAND)
	{
		actionPtr = m_actions[MINUS];
		creatingNewCommand("-", actionPtr);
	}

	else if (command == ADD_COMMAND)
	{
		actionPtr = m_actions[PLUS];
		creatingNewCommand("+", actionPtr);
	}

	else if (command == SCAL_COMMAND) scalFunc(command);

	else std::cout << "Invalid command\n";

	std::cout << "\n---------------------------------------------------------\n";
	std::cout << "---------------------------------------------------------\n\n";
}

//-----------------------------------------------------------------------------

void Calculator::scalFunc(std::string command)
{
	std::string num;
	std::cin >> num;

	std::string newCommand = command + " " + num;
	float scal = convertStringToInt(num);

	m_operations.emplace_back(std::make_shared<BasicOperation>
									(newCommand, m_functions[SCAL], scal));
}

//-----------------------------------------------------------------------------

void Calculator::delFunc()
{
	int numCommand;
	std::cin >> numCommand;

	if (numCommand >= m_operations.size())
	{
		std::cout << "Index out of range\n";
		return;
	}

	m_operations.erase(m_operations.begin() + numCommand);
}

//-----------------------------------------------------------------------------

void Calculator::helpFunc()
{
	Help help;
	help.showHelp();
}

//-----------------------------------------------------------------------------

void Calculator::exitFunc()
{
	std::cout << "Goodbye!\n\n";
	exit(EXIT_SUCCESS);
}

//-----------------------------------------------------------------------------

void Calculator::evaluate(std::string command)
{
	int size, operation;
	std::cin >> operation >> size;
	if (invalidOperation(operation, size)) return;

	Matrix matrix(size);

	matrix = m_operations[operation]->calcFunc(size, matrix, false);
	std::cout << "\nThe answer for - '" << m_operations[operation]->getName()
										<< "' is: ";
	std::cout << matrix << std::endl;
}

//-----------------------------------------------------------------------------

bool Calculator::invalidOperation(int operation, int size)
{
	if (operation >= m_operations.size())
	{
		std::cout << "Index out of range\n";
		return true;
	}
	if (size < MIN_SIZE_MATRIX)
	{
		std::cout << "Invalid size\n";
		return true;
	}
	return false;
}

//-----------------------------------------------------------------------------

void Calculator::creatingNewCommand(std::string action, std::shared_ptr<Action> actionPtr)
{
	unsigned int firstActionNum, secondActionNum;
	std::cin >> firstActionNum >> secondActionNum;

	if (firstActionNum >= m_operations.size() || secondActionNum >= m_operations.size())
	{
		std::cout << "Index out of range\n";
		return;
	}

	insertNewCommand(firstActionNum, secondActionNum, action, actionPtr);
}

//-----------------------------------------------------------------------------

void Calculator::insertNewCommand(unsigned int firstActionNum, 
								  unsigned int secondActionNum, 
								  std::string action, std::shared_ptr<Action> actionPtr)
{
	std::string firstAction = m_operations[firstActionNum]->getName();
	std::string secondAction = m_operations[secondActionNum]->getName();

	std::shared_ptr<Operation> firstCommand = m_operations[firstActionNum];
	std::shared_ptr<Operation> secondCommand = m_operations[secondActionNum];

	std::string newCommand = "(" + firstAction + " " + action + " " + secondAction + ")";

	m_operations.emplace_back(std::make_shared<ComplexOperation>
						(newCommand, firstCommand, secondCommand, actionPtr));
}

//-----------------------------------------------------------------------------

float Calculator::convertStringToInt(std::string action)
{
	float actionInt;
	std::stringstream ss(action);
	ss >> actionInt;
	return actionInt;
}

//-----------------------------------------------------------------------------

void Calculator::creatingVectorFunctions()
{
	m_functions.emplace_back(std::make_shared<Id>());
	m_functions.emplace_back(std::make_shared<Tran>());
	m_functions.emplace_back(std::make_shared<Scal>());
}

//-----------------------------------------------------------------------------

void Calculator::creatingDefaultMenu()
{
	std::shared_ptr<Function> idOperation = m_functions[ID];
	std::shared_ptr<Function> tranOperation = m_functions[TRAN];

	m_operations.emplace_back(std::make_shared<BasicOperation>("id", idOperation, 0));
	m_operations.emplace_back(std::make_shared<BasicOperation>("tran", tranOperation, 0));
}

//-----------------------------------------------------------------------------

void Calculator::creatingActions()
{
	m_actions.emplace_back(std::make_shared<Sub>());
	m_actions.emplace_back(std::make_shared<Comp>());
	m_actions.emplace_back(std::make_shared<Add>());
}