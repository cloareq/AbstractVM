#include <iostream>
#include "Stack.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"

Stack::Stack()
{
	this->_createList.insert(std::pair<const std::string, eOperandType>("int8", INT8));
	this->_createList.insert(std::pair<const std::string, eOperandType>("int16", INT16));
	this->_createList.insert(std::pair<const std::string, eOperandType>("int32", INT32));
	this->_createList.insert(std::pair<const std::string, eOperandType>("float", FLOAT));
	this->_createList.insert(std::pair<const std::string, eOperandType>("double", DOUBLE));

	this->_myTab[0] = &Stack::createInt8;
	this->_myTab[1] = &Stack::createInt16;
	this->_myTab[2] = &Stack::createInt32;
	this->_myTab[3] = &Stack::createFloat;
	this->_myTab[4] = &Stack::createDouble;
}

Stack::~Stack()
{
	
}

void		Stack::printStack()
{
	std::list<IOperand*>::const_iterator 
	lit(this->_stack.begin()), 
	lend(this->_stack.end()); 
	for(;lit!=lend;++lit) std::cout << (*lit)->getValueInString() << std::endl;
}

void		Stack::push(std::pair<std::string, std::string>  value)
{
	if (this->_createList.find(value.first) == this->_createList.end()) {
		throw "Syntax error";
	}
	this->_stack.push_back(createOperand(this->_createList[value.first], value.second));
}

void		Stack::push(IOperand *value)
{
	this->_stack.push_back(value);
}

IOperand	*Stack::pop()
{
	if (this->_stack.size()) {
		IOperand	*tmp;
		tmp = this->_stack.back();
		this->_stack.pop_back();
		return tmp;
	}
	throw "Pop on a empty stack";
	return NULL;
}

IOperand 	*Stack::createOperand(eOperandType type, const std::string & value)
{
	return ((this->*_myTab[type])(value));
}

IOperand 	*Stack::createInt8(const std::string & value)
{
	return (new Int8(value));
}

IOperand 	*Stack::createInt16(const std::string & value)
{
	return (new Int16(value));
}

IOperand 	*Stack::createInt32(const std::string & value)
{
	return (new Int32(value));
}

IOperand 	*Stack::createFloat(const std::string & value)
{
	return (new Float(value));
}

IOperand 	*Stack::createDouble(const std::string & value)
{
	return (new Double(value));
}