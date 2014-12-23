#include "Float.hpp"
#include <sstream>

Float::Float(const std::string value)
{
	float		save;

	std::istringstream	convert(value);
	convert >> save;
	this->_value = save;
	_toVal = new std::string  ("float(" + value + ")");
}

Float::Float(float val) : _value(val)
{
	float	save;

	std::string	result;
	std::ostringstream convert;

	save = val;
	convert << save;
	result = convert.str();
	_toVal = new std::string  ("float(" + result + ")");
}

Float::~Float() {}

//fonctions membres

std::string const&	Float::toString() const
{
	return (*_toVal);
}

std::string		Float::getValueInString() const
{
	float save;

	std::string	result;
	std::ostringstream convert;

	save = this->_value;
	convert << save;
	result = convert.str();
	return (result);
}

int		Float::getPrecision() const
{
	return FLOAT;
}

eOperandType Float::getType() const
{
	return FLOAT;
}

//CALC

IOperand* Float::operator+(const IOperand &rhs) const
{
	float save;

	if (rhs.getPrecision() > this->getPrecision()) {
		return (rhs + *this);
	}
	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	return (new Float(this->_value + save));
}

IOperand* Float::operator*(const IOperand &rhs) const
{
	float save;

	if (rhs.getPrecision() > this->getPrecision()) {
		return (rhs * *this);
	}
	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	return (new Float(this->_value * save));
}

IOperand* Float::operator-(const IOperand &rhs) const
{
	float save;

	if (rhs.getPrecision() > this->getPrecision()) {
		return (rhs.otherSub(*this));
	}
	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	return (new Float(this->_value - save));
}

IOperand* Float::operator/(const IOperand &rhs) const
{
	float save;

	if (rhs.getPrecision() > this->getPrecision()) {
		return (rhs.otherDiv(*this));
	}
	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	if (save == 0.00) {
		throw "Division by Zero";
	}
	return (new Float(this->_value / save));
}

IOperand* Float::operator%(const IOperand &) const
{
	throw "Modulo by decimal";
}

//OTHER CALC

IOperand* Float::otherDiv(const IOperand &rhs) const
{
	float save;

	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	if (save == 0.00) {
		throw "Division by Zero";
	}
	return (new Float(save / this->_value));
}

IOperand* Float::otherSub(const IOperand &rhs) const
{
	float save;

	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	return (new Float(save - this->_value));
}

IOperand* Float::otherMod(const IOperand &) const
{
	throw "Modulo by decimal";
}