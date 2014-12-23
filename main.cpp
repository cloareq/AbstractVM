#include <iostream>
#include "Manager.hpp"
#include "IOperand.hpp"
#include "Parser.hpp"
#include "Stack.hpp"

int	main(int ac, char **av)
{
	Manager		*abstract;

	if (ac > 2) {
		std::cout << "Usage: ./abstract [*.avm]" << std::endl;
		return -1;
	}

	if (ac == 2)
		abstract = new Manager(new Parser(av[1]), new Stack);
	else if (ac == 1)
		abstract = new Manager(new Parser(""), new Stack);
	abstract->startLoop();
	return 0;
}