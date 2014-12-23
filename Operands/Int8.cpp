#include "Int8.hpp"
#include <sstream>
#include <iostream>

Int8::Int8(const std::string value)
{
	int		save;
	long long tmp;

	std::istringstream	over(value);
	std::istringstream	convert(value);
	over >> tmp;
	if (tmp > 127 || tmp < -128)
		throw "Overflow";
	convert >> save;
	this->_value = save;
	_toVal = new std::string  ("int8(" + value + ")");
}

Int8::Int8(char val) : _value(val)
{
	int	save;

	std::string	result;
	std::ostringstream convert;

	save = val;
	convert << save;
	result = convert.str();
	_toVal = new std::string  ("int8(" + result + ")");
}

Int8::~Int8() {}

//fonctions membres

std::string const&	Int8::toString() const
{
	return (*_toVal);
}

std::string		Int8::getValueInString() const
{
	int	save;

	std::string	result;
	std::ostringstream convert;

	save = this->_value;
	convert << save;
	result = convert.str();
	return (result);
}

int		Int8::getPrecision() const
{
	return INT8;
}

eOperandType Int8::getType() const
{
	return INT8;
}

//CALC

IOperand* Int8::operator+(const IOperand &rhs) const
{
	int	save;
	long long tmp;
	if (rhs.getPrecision() > this->getPrecision()) {
		return (rhs + *this);
	}
	std::istringstream	over(rhs.getValueInString());
	std::istringstream	convert(rhs.getValueInString());
	over >> tmp;
	if ((tmp + _value) > 127 || (tmp + _value) < -128)
		throw "Overflow";
	convert >> save;
	return (new Int8(this->_value + save));
}

IOperand* Int8::operator*(const IOperand &rhs) const
{
	int	save;
	long long tmp;
	if (rhs.getPrecision() > this->getPrecision()) {
		return (rhs * *this);
	}
	std::istringstream	over(rhs.getValueInString());
	std::istringstream	convert(rhs.getValueInString());
	over>>tmp;
	if ((tmp*_value) > 127 || (tmp*_value) < -128)
		throw "Overflow";
	convert >> save;
	return (new Int8(this->_value * save));
}

IOperand* Int8::operator-(const IOperand &rhs) const
{
	int	save;

	if (rhs.getPrecision() > this->getPrecision()) {
		return (rhs.otherSub(*this));
	}
	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	return (new Int8(this->_value - save));
}

IOperand* Int8::operator/(const IOperand &rhs) const
{
	int	save;

	if (rhs.getPrecision() > this->getPrecision()) {
		return (rhs.otherDiv(*this));
	}
	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	if (save == 0) {
		throw "Division by Zero";
	}
	return (new Int8(this->_value / save));
}

IOperand* Int8::operator%(const IOperand &rhs) const
{
	int	save;

	if (rhs.getPrecision() > this->getPrecision()) {
		return (rhs.otherMod(*this));
	}
	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	if (save == 0) {
		throw "Modulo by Zero";
	}
	return (new Int8(this->_value % save));
}

//OTHER CALC

IOperand* Int8::otherDiv(const IOperand &rhs) const
{
	int	save;

	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	if (save == 0) {
		throw "Division by Zero";
	}
	return (new Int8(save / this->_value));
}

IOperand* Int8::otherSub(const IOperand &rhs) const
{
	int	save;

	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	return (new Int8(save - this->_value));
}

IOperand* Int8::otherMod(const IOperand &rhs) const
{
	int	save;

	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	if (save == 0) {
		throw "Modulo by Zero";
	}
	return (new Int8(save % this->_value));
}