#include "Manager.hpp"

Manager::Manager(Parser *myParser, Stack *myStack) : _myParser(myParser), _myStack(myStack)
{
	this->_actionsList.insert(std::pair<std::string, memberPtr>("push", &Manager::push));
	this->_actionsList.insert(std::pair<std::string, memberPtr>("pop", &Manager::pop));
	this->_actionsList.insert(std::pair<std::string, memberPtr>("dump", &Manager::dump));
	this->_actionsList.insert(std::pair<std::string, memberPtr>("assert", &Manager::assert));
	this->_actionsList.insert(std::pair<std::string, memberPtr>("add", &Manager::add));
	this->_actionsList.insert(std::pair<std::string, memberPtr>("sub", &Manager::sub));
	this->_actionsList.insert(std::pair<std::string, memberPtr>("mul", &Manager::mul));
	this->_actionsList.insert(std::pair<std::string, memberPtr>("div", &Manager::div));
	this->_actionsList.insert(std::pair<std::string, memberPtr>("mod", &Manager::mod));
	this->_actionsList.insert(std::pair<std::string, memberPtr>("print", &Manager::print));
	this->_actionsList.insert(std::pair<std::string, memberPtr>("exit", &Manager::exit));
	this->_actionsList.insert(std::pair<std::string, memberPtr>(";;", &Manager::quit));
}

Manager::~Manager()
{}

int		Manager::startLoop()
{
	std::pair<std::string, std::string>  commande;
	try {
		while (42) {
			if(_myParser->getTmp() != "")
				commande = _myParser->newLine();
			else
				commande = _myParser->newLineCin();
			if (this->_actionsList.find(commande.first) == this->_actionsList.end()) {
				throw "Syntax error, unknown instruction";
			}
			((this->*(this->_actionsList[commande.first]))(commande.second));
		}
	} catch(std::string error) {
		std::cout << error << std::endl;
	} catch(const char *bug) {
		std::cout << bug << std::endl;
	} catch(int end) {
		return end;
	}
	return -1;
}

void	Manager::push(const std::string& value)
{
	this->_myParser->convertOperand(value);
	this->_myStack->push(this->_myParser->convertOperand(value));
}

void	Manager::pop(const std::string&)
{
	this->_myStack->pop();
}

void	Manager::dump(const std::string&)
{
	this->_myStack->printStack();
}

void	Manager::assert(const std::string& value)
{
	IOperand	*tmp = this->_myStack->pop();
	if  (tmp->toString() != value)
		throw "Assert : values are different";
}

void	Manager::add(const std::string&)
{
	IOperand	*op1 = this->_myStack->pop();
	IOperand	*op2 = this->_myStack->pop();
	this->_myStack->push(*op1 + *op2);
}

void	Manager::sub(const std::string&)
{
	IOperand	*op1 = this->_myStack->pop();
	IOperand	*op2 = this->_myStack->pop();
	this->_myStack->push(*op1 - *op2);
}

void	Manager::mul(const std::string&)
{
	IOperand	*op1 = this->_myStack->pop();
	IOperand	*op2 = this->_myStack->pop();
	this->_myStack->push(*op1 * *op2);
}

void	Manager::div(const std::string&)
{
	IOperand	*op1 = this->_myStack->pop();
	IOperand	*op2 = this->_myStack->pop();
	this->_myStack->push(*op1 / *op2);
}

void	Manager::mod(const std::string&)
{
	IOperand	*op1 = this->_myStack->pop();
	IOperand	*op2 = this->_myStack->pop();
	this->_myStack->push(*op1 % *op2);
}

void	Manager::print(const std::string&)
{
	IOperand	*tmp = this->_myStack->pop();
	if (tmp->getType() != INT8) {
		throw "Top value is not an Int8";
	}
	std::cout << tmp->getValueInString() << std::endl;
	this->_myStack->push(tmp);
}

void	Manager::exit(const std::string&)
{
	if (_myParser->getTmp() != "")
		throw 0;
}

void	Manager::quit(const std::string&)
{
	if (_myParser->getTmp() == "")
		throw 0;
}