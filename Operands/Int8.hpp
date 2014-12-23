#ifndef INT8_H_
#define INT8_H_

#include "IOperand.hpp"

class Int8 : public IOperand
{
private:
	char	_value;
	std::string*  _toVal;
public:
	Int8(const std::string value);
	Int8(char);
	~Int8();
	
	//fonctions membres
	virtual std::string const & toString() const;

	virtual int getPrecision() const;
	virtual eOperandType getType() const;

	virtual IOperand * operator+(const IOperand &rhs) const;
	virtual IOperand * operator-(const IOperand &rhs) const;
	virtual IOperand * operator*(const IOperand &rhs) const;
	virtual IOperand * operator/(const IOperand &rhs) const;
	virtual IOperand * operator%(const IOperand &rhs) const;

	std::string		getValueInString() const;
	IOperand* 		otherDiv(const IOperand &rhs) const;
	IOperand* 		otherSub(const IOperand &rhs) const;
	IOperand* 		otherMod(const IOperand &rhs) const;

};

#endif