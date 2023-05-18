#include "CFixedPointNumber.h"

CFixedPointNumber::CFixedPointNumber(int intPart, int fractPart) {
	setIntPart(intPart);
	setFractPart(fractPart);
}


void CFixedPointNumber::setIntPart(int intPart) {
	this->intPart = intPart;
}
void CFixedPointNumber::setFractPart(int fractPart) {
	this->fractPart = fractPart;
}
void CFixedPointNumber::setDoubleValue(double value) {
	this->intPart = (int)value;
	this->fractPart = (int)((value - intPart) * 100);
}

int CFixedPointNumber::getIntPart() const {
	return intPart;
}
int CFixedPointNumber::getFractPart() const {
	return fractPart;
}
double CFixedPointNumber::getDoubleValue() const {
	return ((double)intPart + ((double)fractPart / 100));
}

CFixedPointNumber CFixedPointNumber::findSum(const CFixedPointNumber& value) {
	int sumIntPart = this->intPart + value.intPart;
	int sumFractPart = this->fractPart + value.fractPart;

	if (sumFractPart >= 100) {
		sumIntPart++;
		sumFractPart -= 100;
	}

	return CFixedPointNumber(sumIntPart, sumFractPart);
}
CFixedPointNumber CFixedPointNumber::findSubstraction(const CFixedPointNumber& value) {
	int substractIntPart = this->intPart - value.intPart;
	int substractFractPart = this->fractPart - value.fractPart;

	if (substractFractPart < 100) {
		substractIntPart--;
		substractFractPart += 100;
	}

	return CFixedPointNumber(substractIntPart, substractFractPart);
}
CFixedPointNumber CFixedPointNumber::findMultiplication(const CFixedPointNumber& value) {
	int a = this->intPart * 100 + this->fractPart;
	int b = value.intPart * 100 + value.fractPart;
	int multiply = a * b;
	double multiplyDouble = multiply;
	multiplyDouble /= 10000;
	int multiplyIntPart = (int)multiplyDouble;
	int multiplyFractPart = (int)((multiplyDouble - multiplyIntPart) * 100);
	return CFixedPointNumber(multiplyIntPart, multiplyFractPart);
}
CFixedPointNumber CFixedPointNumber::findDivision(const CFixedPointNumber& value) {
	double a = ((double)(this->intPart) + (double)(this->fractPart) / 100);
	double b = ((double)(value.intPart) + (double)(value.fractPart) / 100);

	int divisionIntPart = 0;
	int divisionFractpart = 0;

	if (b != 0) {
		double division = a / b;
		divisionIntPart = (int)division;
		divisionFractpart = (int)((division - divisionIntPart) * 100);
	}
	else {
		divisionIntPart = 0;
		divisionFractpart = 0;
	}


	return CFixedPointNumber(divisionIntPart, divisionFractpart);
}