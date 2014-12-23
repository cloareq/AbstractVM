#ifndef PARSER_HPP__
#define PARSER_HPP__

#include <iostream>
#include <fstream>
#include <utility>
#include <map>
#include <string>

class Parser
{
private:
	std::ifstream *_file;
	std::string _tmp;
public:
	Parser(const std::string& file);
	~Parser();
	std::pair<std::string, std::string>
	newLine();
	std::pair<std::string, std::string>
	newLineCin();
	std::pair<std::string, std::string>
	convertOperand(std::string param);
	std::string getTmp() const;
};

#endif