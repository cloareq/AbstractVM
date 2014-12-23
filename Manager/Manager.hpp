#ifndef MANAGER_H_
#define MANAGER_H_

#include <map>
#include "Parser.hpp"
#include "Stack.hpp"

class Manager
{
	Parser	*_myParser;
	Stack	*_myStack;
public:
	Manager(Parser *, Stack *);
	~Manager();
private:
	typedef	void	(Manager::*memberPtr)(const std::string&);
	std::map<std::string, memberPtr> _actionsList;

	void	push(const std::string&);
	void	pop(const std::string&);
	void	dump(const std::string&);
	void	assert(const std::string&);
	void	add(const std::string&);
	void	sub(const std::string&);
	void	mul(const std::string&);
	void	div(const std::string&);
	void	mod(const std::string&);
	void	print(const std::string&);
	void	exit(const std::string&);
	void	quit(const std::string&);

public:
	int		startLoop();
};

#endif