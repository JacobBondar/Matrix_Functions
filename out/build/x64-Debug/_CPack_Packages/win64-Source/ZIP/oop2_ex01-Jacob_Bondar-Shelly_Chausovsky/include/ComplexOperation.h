#pragma once
#include "Operation.h"

class ComplexOperation : public Operation
{
public:
	ComplexOperation(std::string name, std::shared_ptr<Operation> firstCommand,
		std::shared_ptr<Operation> secondCommand, std::shared_ptr<Action> action)
		: m_name(name), m_action(action), m_operation1(firstCommand), m_operation2(secondCommand) {}
	~ComplexOperation() = default;

	virtual void print()  const override { std::cout << m_name << std::endl; };
	virtual std::string getName()  const override;
	virtual Matrix calcFunc(int size, Matrix& prevMatrix, bool comp)  const override;

private:
	std::shared_ptr<Action> m_action;
	std::string m_name;
	std::shared_ptr<Operation> m_operation1;
	std::shared_ptr<Operation> m_operation2;
};