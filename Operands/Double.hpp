#ifndef DOUBLE_H_
#define DOUBLE_H_

#include "IOperand.hpp"

class Double : public IOperand
{
private:
	double	_value;
	std::string*  _toVal;
public:
	Double(const std::string value);
	Double(double);
	~Double();
	
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