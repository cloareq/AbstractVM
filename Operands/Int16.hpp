#ifndef INT16_H_
#define INT16_H_

#include "IOperand.hpp"

class Int16 : public IOperand
{
private:
	short	_value;
	std::string*  _toVal;
public:
	Int16(const std::string value);
	Int16(short);
	~Int16();
	
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