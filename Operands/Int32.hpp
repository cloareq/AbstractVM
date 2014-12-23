#ifndef INT32_H_
#define INT32_H_

#include "IOperand.hpp"

class Int32 : public IOperand
{
private:
	int		_value;
	std::string*  _toVal;
public:
	Int32(const std::string value);
	Int32(int);
	~Int32();

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