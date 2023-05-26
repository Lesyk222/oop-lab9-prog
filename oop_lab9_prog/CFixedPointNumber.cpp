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

CFixedPointNumber CFixedPointNumber::findSum(const CFixedPointNumber& value) const {
	int sumIntPart = this->intPart + value.intPart;
	int sumFractPart = this->fractPart + value.fractPart;

	if (sumFractPart >= 100) {
		sumIntPart++;
		sumFractPart -= 100;
	}

	return CFixedPointNumber(sumIntPart, sumFractPart);
}

CFixedPointNumber CFixedPointNumber::findSum(int value) const {
	int sumIntPart = this->intPart + value;
	int sumFractPart = this->fractPart;

	return CFixedPointNumber(sumIntPart, sumFractPart);
}

CFixedPointNumber CFixedPointNumber::findSubstraction(const CFixedPointNumber& value) const {
	int substractIntPart = this->intPart - value.intPart;
	int substractFractPart = this->fractPart - value.fractPart;

	if (substractFractPart < 100) {
		substractIntPart--;
		substractFractPart += 100;
	}

	return CFixedPointNumber(substractIntPart, substractFractPart);
}

CFixedPointNumber CFixedPointNumber::findSubstraction(int value) const {
	int substractIntPart = this->intPart - value;
	int substractFractPart = this->fractPart;
	return CFixedPointNumber(substractIntPart, substractFractPart);
}

CFixedPointNumber CFixedPointNumber::findMultiplication(const CFixedPointNumber& value) const {
	double a = ((double)(this->intPart) + (double)(this->fractPart) / 100);
	double b = ((double)(value.intPart) + (double)(value.fractPart) / 100);
	double multiply = a * b;
	int multiplyIntPart = (int)multiply;
	int multiplyFractPart = (int)(multiply - multiplyIntPart) * 100;

	return CFixedPointNumber(multiplyIntPart, multiplyFractPart);
}

CFixedPointNumber CFixedPointNumber::findMultiplication(int value) const {
	double a = ((double)(this->intPart) + (double)(this->fractPart) / 100);
	int b = value;
	double multiply = a * b;
	int multiplyIntPart = (int)multiply;
	int multiplyFractPart = (int)(multiply - multiplyIntPart) * 100;

	return CFixedPointNumber(multiplyIntPart, multiplyFractPart);
}

CFixedPointNumber CFixedPointNumber::findDivision(const CFixedPointNumber& value) const {
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

CFixedPointNumber CFixedPointNumber::findDivision(int value) const {
	double a = ((double)(this->intPart) + (double)(this->fractPart) / 100);
	int b = value;

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

CFixedPointNumber CFixedPointNumber::operator+(const CFixedPointNumber& value) const {
	int sumIntPart = this->intPart + value.intPart;
	int sumFractPart = this->fractPart + value.fractPart;

	if (sumFractPart >= 100) {
		sumIntPart++;
		sumFractPart -= 100;
	}

	return CFixedPointNumber(sumIntPart, sumFractPart);
}

CFixedPointNumber CFixedPointNumber::operator-(const CFixedPointNumber& value) const {
	int substractIntPart = this->intPart - value.intPart;
	int substractFractPart = this->fractPart - value.fractPart;

	if (substractFractPart < 100) {
		substractIntPart--;
		substractFractPart += 100;
	}

	return CFixedPointNumber(substractIntPart, substractFractPart);
}

CFixedPointNumber CFixedPointNumber::operator*(const CFixedPointNumber& value) const {
	double a = ((double)(this->intPart) + (double)(this->fractPart) / 100);
	double b = ((double)(value.intPart) + (double)(value.fractPart) / 100);
	double multiply = a * b;
	int multiplyIntPart = (int)multiply;
	int multiplyFractPart = (int)((multiply - multiplyIntPart) * 100);

	return CFixedPointNumber(multiplyIntPart, multiplyFractPart);
}

CFixedPointNumber CFixedPointNumber::operator/(const CFixedPointNumber& value) const {
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

CFixedPointNumber::operator double() const {
	return ((double)intPart + ((double)fractPart / 100));
}

std::istream& operator>> (std::istream& input, CFixedPointNumber value) {
	input >> value.intPart >> value.fractPart;
	return input;
}

std::ostream& operator<< (std::ostream& output, CFixedPointNumber value) {
	output << value.getDoubleValue();
	return output;
}

bool operator> (const CFixedPointNumber& value, const CFixedPointNumber& otherValue) {
	if (value.intPart > otherValue.intPart) {
		return true;
	}
	else if (value.intPart == otherValue.intPart && value.fractPart > otherValue.fractPart) {
		return true;
	}
	else {
		return false;
	}
}

bool operator< (const CFixedPointNumber& value, const CFixedPointNumber& otherValue) {
	if (value.intPart < otherValue.intPart) {
		return true;
	}
	else if (value.intPart == otherValue.intPart && value.fractPart < otherValue.fractPart) {
		return true;
	}
	else {
		return false;
	}
}

bool operator== (const CFixedPointNumber& value, const CFixedPointNumber& otherValue) {
	if (value.intPart == otherValue.intPart && value.fractPart == otherValue.fractPart) {
		return true;
	}
	else {
		return false;
	}
}