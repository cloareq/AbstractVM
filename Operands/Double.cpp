#include "Double.hpp"
#include <sstream>

Double::Double(const std::string value)
{
	double save;

	std::istringstream	convert(value);
	convert >> save;
	this->_value = save;
	_toVal = new std::string  ("double(" + value + ")");
}

Double::Double(double val) : _value(val)
{
	double	save;

	std::string	result;
	std::ostringstream convert;

	save = val;
	convert << save;
	result = convert.str();
	_toVal = new std::string  ("double(" + result + ")");
}

Double::~Double() {}

//fonctions membres

std::string const&	Double::toString() const
{
	return (*_toVal);
}

std::string		Double::getValueInString() const
{
	double save;

	std::string	result;
	std::ostringstream convert;

	save = this->_value;
	convert << save;
	result = convert.str();
	return (result);
}

int		Double::getPrecision() const
{
	return DOUBLE;
}

eOperandType Double::getType() const
{
	return DOUBLE;
}

//CALC

IOperand* Double::operator+(const IOperand &rhs) const
{
	double save;

	if (rhs.getPrecision() > this->getPrecision()) {
		return (rhs + *this);
	}
	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	return (new Double(this->_value + save));
}

IOperand* Double::operator*(const IOperand &rhs) const
{
	double save;

	if (rhs.getPrecision() > this->getPrecision()) {
		return (rhs * *this);
	}
	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	return (new Double(this->_value * save));
}

IOperand* Double::operator-(const IOperand &rhs) const
{
	double save;

	if (rhs.getPrecision() > this->getPrecision()) {
		return (rhs.otherSub(*this));
	}
	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	return (new Double(this->_value - save));
}

IOperand* Double::operator/(const IOperand &rhs) const
{
	double save;

	if (rhs.getPrecision() > this->getPrecision()) {
		return (rhs.otherDiv(*this));
	}
	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	if (save == 0.00) {
		throw "Division by Zero";
	}
	return (new Double(this->_value / save));
}

IOperand* Double::operator%(const IOperand &) const
{
	throw "Modulo by decimal";
}

//OTHER CALC

IOperand* Double::otherDiv(const IOperand &rhs) const
{
	double save;

	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	if (save == 0.00) {
		throw "Division by Zero";
	}
	return (new Double(save / this->_value));
}

IOperand* Double::otherSub(const IOperand &rhs) const
{
	double save;

	std::istringstream	convert(rhs.getValueInString());
	convert >> save;
	return (new Double(save - this->_value));
}

IOperand* Double::otherMod(const IOperand &) const
{
	throw "Modulo by decimal";
}