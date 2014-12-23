#ifndef FLOAT_H_
#define FLOAT_H_

#include "IOperand.hpp"

class Float : public IOperand
{
private:
	float	_value;
	std::string*  _toVal;
public:
	Float(const std::string value);
	Float(float);
	~Float();
	
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