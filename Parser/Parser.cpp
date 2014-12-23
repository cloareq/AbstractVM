#include <fstream>
#include "Parser.hpp"

Parser::Parser(const std::string& file)
: _file(new std::ifstream (file.c_str())), _tmp(file)
{}

Parser::~Parser(){}

std::pair<std::string, std::string>
Parser::newLine()
{
	std::string line;
	std::string action;
	std::string parameters;

	if (_tmp != "")
	{
		if (!std::getline(*_file, line, '\n'))
			throw "Unexpected end of file";

		if (line.find_first_of(";") != std::string::npos) {
			line=line.substr(0, line.find_first_of(";"));
		}
		if (line.find_first_not_of("\t ") == std::string::npos) {
			return newLine();
		}
		line=line.substr(line.find_first_not_of("\t "), line.size());
		action=line.substr(0, line.find_first_of("\t "));
		if (line.find_first_not_of("\t ", action.size()) == std::string::npos)
			return std::make_pair(action, "");
		parameters = line.substr(line.find_first_not_of("\t ", action.size()), line.find_first_of(" \t", line.find_first_not_of("\t ", action.size())));
	}
	else
		throw 0;
	return std::make_pair(action, parameters);
}

std::pair<std::string, std::string>
Parser::newLineCin()
{
	std::string line;

	std::getline(std::cin, line, '\n');
	if (line.find_first_of(";") != std::string::npos) {
		line=line.substr(0, line.find_first_of(";"));
	}
	if (line.find_first_not_of("\t ") == std::string::npos) {
		return newLine();
	}
	line=line.substr(line.find_first_not_of("\t "), line.size());
	std::string action;
	action=line.substr(0, line.find_first_of("\t "));
	if (line.find_first_not_of("\t ", action.size()) == std::string::npos)
		return std::make_pair(action, "");
	std::string parameters = line.substr(line.find_first_not_of("\t ", action.size()), line.find_first_of(" \t", line.find_first_not_of("\t ", action.size())));
	return std::make_pair(action, parameters);
}

std::pair<std::string, std::string>
Parser::convertOperand(std::string parameters)
{
	std::string type;
	std::string value;

	if (parameters.find_first_of("(") == std::string::npos || parameters.find_first_of(")") == std::string::npos)
		throw "Missing ( or )";
	type=parameters.substr(0, parameters.find_first_of("("));
	value=parameters.substr(parameters.find_first_of("(") + 1, parameters.find_first_of(")"));
	return std::make_pair(type, value);
}

std::string Parser::getTmp() const
{
	return _tmp;
}