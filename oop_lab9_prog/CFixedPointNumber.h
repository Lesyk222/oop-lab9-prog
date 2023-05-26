#include <iostream>
#include <cmath>

class CFixedPointNumber {
private:
	int intPart;;
	int fractPart;

public:
	CFixedPointNumber(int intPart = 0, int fractPart = 0);

	void setIntPart(int intPart);
	void setFractPart(int fractPart);
	void setDoubleValue(double value);

	int getIntPart() const;
	int getFractPart() const;
	double getDoubleValue() const;

	CFixedPointNumber findSum(const CFixedPointNumber& value) const;
	CFixedPointNumber findSum(int value) const;
	CFixedPointNumber findSubstraction(const CFixedPointNumber& value) const;
	CFixedPointNumber findSubstraction(int value) const;
	CFixedPointNumber findMultiplication(const CFixedPointNumber& value) const;
	CFixedPointNumber findMultiplication(int value) const;
	CFixedPointNumber findDivision(const CFixedPointNumber& value) const;
	CFixedPointNumber findDivision(int value) const;

	CFixedPointNumber operator+(const CFixedPointNumber& value) const;
	CFixedPointNumber operator-(const CFixedPointNumber& value) const;
	CFixedPointNumber operator*(const CFixedPointNumber& value) const;
	CFixedPointNumber operator/(const CFixedPointNumber& value) const;
	operator double() const;

	friend std::istream& operator>> (std::istream& input, CFixedPointNumber value);
	friend std::ostream& operator<< (std::ostream& output, CFixedPointNumber value);
	friend bool operator> (const CFixedPointNumber& value, const CFixedPointNumber& otherValue);
	friend bool operator< (const CFixedPointNumber& value, const CFixedPointNumber& otherValue);
	friend bool operator== (const CFixedPointNumber& value, const CFixedPointNumber& otherValue);
};