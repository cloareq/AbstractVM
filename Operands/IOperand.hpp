#ifndef IOPERAND_H_
#define IOPERAND_H_

#include <string>

enum eOperandType
{
	INT8,
	INT16,
	INT32,
	FLOAT,
	DOUBLE
};

class IOperand
{
public:

	virtual std::string const & toString() const = 0; // "Int8(42)"

	virtual int getPrecision() const = 0;
	virtual eOperandType getType() const = 0;

	virtual IOperand * operator+(const IOperand &rhs) const = 0;
	virtual IOperand * operator-(const IOperand &rhs) const = 0;
	virtual IOperand * operator*(const IOperand &rhs) const = 0;
	virtual IOperand * operator/(const IOperand &rhs) const = 0;
	virtual IOperand * operator%(const IOperand &rhs) const = 0;

	virtual ~IOperand() {}

	virtual std::string		getValueInString() const = 0;
	virtual IOperand* 		otherDiv(const IOperand &rhs) const = 0;
	virtual IOperand* 		otherSub(const IOperand &rhs) const = 0;
	virtual IOperand* 		otherMod(const IOperand &rhs) const = 0;
};

#endif