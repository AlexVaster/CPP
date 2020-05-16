#pragma once
#include <iostream>

class Polynomial {
public:
	Polynomial();
	Polynomial(unsigned int size);
	Polynomial(const double*, unsigned int size);
	Polynomial(const Polynomial&);
	~Polynomial();

    unsigned int getDimension() const { return dimension; }
    double getCoeffs(const unsigned int index) const;
    double evaluate (double x) const;
    void setCoeffs(unsigned int i, double value);
    Polynomial& operator = (const Polynomial& poly2);
    friend Polynomial operator +(const Polynomial& poly1, const Polynomial& poly2);
    friend Polynomial operator -(const Polynomial& poly1, const Polynomial& poly2);
    Polynomial operator +() { return *this; }
    Polynomial operator -() const;
    friend Polynomial operator *(const Polynomial& poly1, const Polynomial& poly2);
    friend Polynomial operator /(const Polynomial& poly1, const Polynomial& poly2);
    friend Polynomial operator %(const Polynomial& poly1, const Polynomial& poly2);
	Polynomial& operator +=(const Polynomial&);
    Polynomial& operator -=(const Polynomial&);
	Polynomial& operator *=(const Polynomial&);
    Polynomial& operator /=(const Polynomial&);
    Polynomial& operator %=(const Polynomial&);
	double& operator [](const unsigned int index) const;
	double& at(const unsigned int index) const;

	friend std::istream& operator >>(std::istream& in, Polynomial& poly);
	friend std::ostream& operator <<(std::ostream& out, const Polynomial& poly);

private:
	double* coeffs;
	unsigned int dimension;

    void reduce();
    void reset(){ delete [] coeffs; }
};
