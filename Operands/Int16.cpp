#include "Int16.hpp"
#include <sstream>

Int16::Int16(const std::string value)
{
	short		save;
	long long tmp;

	std::istringstream	over(value);
	std::istringstream	convert(value);
	convert >> save;
	over >> tmp;
	if (tmp > 32767 || tmp < -32768)
		throw "Overflow";
	this->_value = save;
	_toVal = new std::string  ("int16(" + value + ")");
}

Int16::Int16(short val) : _value(val)
{
	short	save;

	std::string	result;
	std::ostringstream convert;

	save = val;
	convert << save;
	result = convert.str();
	_toVal = new std::string  ("int16(" + result + ")");
}

Int16::~Int16() {}


std::string const&	Int16::toString() const
{
	return (*_toVal);
}

std::string		Int16::getValueInString() const
{
	int	save;

	std::string	result;
	std::ostringstream convert;

	save = this->_value;
	convert << save;
	result = convert.str();
	return (result);
}

int		Int16::getPrecision() const
{
	return INT16;
}

eOperandType Int16::getType() const
{
	return INT16;
}

//CALC

IOperand* Int16::operator+(const IOperand &rhs) const
{
	int	save;
	long long tmp;

	if (rhs.getPrecision() > this->getPrecision()) {
		return (rhs + *this);
	}
	std::istringstream	over(rhs.getValueInString());
	over >> tmp;
	if (tmp+_value > 32767 || tmp+_value < -32768)
		throw "Overflow";
	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	return (new Int16(this->_value + save));
}

IOperand* Int16::operator*(const IOperand &rhs) const
{
	int	save;
	long long tmp;

	if (rhs.getPrecision() > this->getPrecision()) {
		return (rhs * *this);
	}
	std::istringstream	over(rhs.getValueInString());
	over >> tmp;
	if (tmp*_value > 32767 || tmp*_value < -32768)
		throw "Overflow";
	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	return (new Int16(this->_value * save));
}

IOperand* Int16::operator-(const IOperand &rhs) const
{
	int	save;

	if (rhs.getPrecision() > this->getPrecision()) {
		return (rhs.otherSub(*this));
	}
	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	return (new Int16(this->_value - save));
}

IOperand* Int16::operator/(const IOperand &rhs) const
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
	return (new Int16(this->_value / save));
}

IOperand* Int16::operator%(const IOperand &rhs) const
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
	return (new Int16(this->_value % save));
}

//OTHER CALC

IOperand* Int16::otherDiv(const IOperand &rhs) const
{
	int	save;

	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	if (save == 0) {
		throw "Division by Zero";
	}
	return (new Int16(save / this->_value));
}

IOperand* Int16::otherSub(const IOperand &rhs) const
{
	int	save;

	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	return (new Int16(save - this->_value));
}

IOperand* Int16::otherMod(const IOperand &rhs) const
{
	int	save;

	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	if (save == 0) {
		throw "Modulo by Zero";
	}
	return (new Int16(save % this->_value));
}