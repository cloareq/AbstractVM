#include "Int32.hpp"
#include <sstream>

Int32::Int32(const std::string value)
{
	int		save;
	long long tmp;
	std::istringstream	over(value);
	std::istringstream	convert(value);
	over >> tmp;
	if (tmp > 2147483647 || tmp < -2147483648)
		throw "Overflow";
	convert >> save;
	this->_value = save;
	_toVal = new std::string  ("int32(" + value + ")");
}

Int32::Int32(int val) : _value(val)
{
	int	save;

	std::string	result;
	std::ostringstream convert;

	save = val;
	convert << save;
	result = convert.str();
	_toVal = new std::string  ("int32(" + result + ")");
}

Int32::~Int32() {}

//fonctions membres

std::string const&	Int32::toString() const
{
	return (*_toVal);
}

std::string		Int32::getValueInString() const
{
	int	save;

	std::string	result;
	std::ostringstream convert;

	save = this->_value;
	convert << save;
	result = convert.str();
	return (result);
}

int		Int32::getPrecision() const
{
	return INT32;
}

eOperandType Int32::getType() const
{
	return INT32;
}

//CALC

IOperand* Int32::operator+(const IOperand &rhs) const
{
	int	save;
	long long tmp;

	if (rhs.getPrecision() > this->getPrecision()) {
		return (rhs + *this);
	}
	std::istringstream	over(rhs.getValueInString());
	std::istringstream	convert(rhs.getValueInString());
	over >> tmp;
	if (tmp+_value > 2147483647 || tmp-_value < -2147483648)
		throw "Overflow";
	convert >> save;
	return (new Int32(this->_value + save));
}

IOperand* Int32::operator*(const IOperand &rhs) const
{
	int	save;

	if (rhs.getPrecision() > this->getPrecision()) {
		return (rhs * *this);
	}
	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	return (new Int32(this->_value * save));
}

IOperand* Int32::operator-(const IOperand &rhs) const
{
	int	save;

	if (rhs.getPrecision() > this->getPrecision()) {
		return (rhs.otherSub(*this));
	}
	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	return (new Int32(this->_value - save));
}

IOperand* Int32::operator/(const IOperand &rhs) const
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
	return (new Int32(this->_value / save));
}

IOperand* Int32::operator%(const IOperand &rhs) const
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
	return (new Int32(this->_value % save));
}

//OTHER CALC

IOperand* Int32::otherDiv(const IOperand &rhs) const
{
	int	save;

	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	if (save == 0) {
		throw "Division by Zero";
	}
	return (new Int32(save / this->_value));
}

IOperand* Int32::otherSub(const IOperand &rhs) const
{
	int	save;

	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	return (new Int32(save - this->_value));
}

IOperand* Int32::otherMod(const IOperand &rhs) const
{
	int	save;

	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	if (save == 0) {
		throw "Modulo by Zero";
	}
	return (new Int32(save % this->_value));
}