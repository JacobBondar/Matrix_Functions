#pragma once
#include <vector>
#include <string>
#include "iostream"

class Help
{
public:
	Help();
	void showHelp() const;

private:
	std::vector<std::string> m_help;
};