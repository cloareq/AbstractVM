#ifndef STACK_H_
#define STACK_H_

#include <list>
#include <map>
#include <string>
#include "IOperand.hpp"

class Stack
{
	std::list<IOperand*>	_stack;
	typedef		IOperand*	(Stack::*createFunc)(const std::string & value);
	createFunc	_myTab[5];
public:
	Stack();
	~Stack();

	void	push(std::pair<std::string, std::string>  value);
	void	push(IOperand *value);
	IOperand	*pop();
	IOperand 	*createOperand(eOperandType type, const std::string & value);

	std::map<const std::string, eOperandType> _createList;

	IOperand 	*createInt8(const std::string & value);
	IOperand 	*createInt16(const std::string & value);
	IOperand 	*createInt32(const std::string & value);
	IOperand 	*createFloat(const std::string & value);
	IOperand 	*createDouble(const std::string & value);

	void		printStack();
};

#endif