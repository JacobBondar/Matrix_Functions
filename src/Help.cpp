#include <Help.h>

//-----------------------------------------------------------------------------

Help::Help()
{
	m_help.emplace_back("\nThe available commands are:");
	m_help.emplace_back("* eval(uate) num n - compute the result of operation #num on all "
                     "needed nªn matrices(that will be prompted)");
	m_help.emplace_back("* scal(ar) val - creates an operation that multiplies the "
                     "given matrix by scalar val");
	m_help.emplace_back("* add num1 num2 - creates an operation that is the addition "
                     "of the result of operation #num1 and the result of operation "
                     "#num2");
	m_help.emplace_back("* sub num1 num2 - creates an operation that is the "
                     "subtraction of the result of operation #num1 and the result "
                     "of operation #num2");
	m_help.emplace_back("* comp(osite) num1 num2 - creates an operation that is the "
                     "composition of operation #num1 and operation #num2");
	m_help.emplace_back("* del(ete) num - delete operation #num from the operation "
                     "list");
	m_help.emplace_back("* help - print this command list");
	m_help.emplace_back("* exit - exit the program\n");
}

//-----------------------------------------------------------------------------

void Help::showHelp() const
{
	for (int row = 0; row < m_help.size(); row++)
	{
		std::cout << m_help[row] << "\n";
	}
}