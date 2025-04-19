#pragma once
#include "Operation.h"

class BasicOperation : public Operation
{
public:
	BasicOperation(std::string name, std::shared_ptr<Function> function, float num)
		: m_name(name), m_function(function), m_scalNum(num) {}
	~BasicOperation() = default;

	virtual void print() const override { std::cout << m_name << std::endl; };
	virtual std::string getName() const override ;
	virtual Matrix calcFunc(int size, Matrix& prevMatrix, bool comp) const override;

private:
	std::string m_name;
	std::shared_ptr<Function> m_function;
	float m_scalNum;
};