#include "Polynomial.h"
#include <cmath>
#include <stdexcept>

Polynomial::Polynomial() {
	this->coeffs = new double[1];
	this->coeffs[0] = 0;
	this->dimension = 0;
}
Polynomial::Polynomial(unsigned int size) {
    this->dimension = size - 1;
    this->coeffs = new double[size];
    for (unsigned int i = 0; i < size; i++) {
        this->coeffs[i] = 0;
    }
}
Polynomial::Polynomial(const double* coef, unsigned int size) {
    this->dimension = size - 1;
	this->coeffs = new double[size];
    for (unsigned int i = 0; i < size; i++) {
        this->coeffs[i] = coef[i];
    }
}
Polynomial::Polynomial(const Polynomial& poly) {
	this->dimension = poly.dimension;
	this->coeffs = new double[dimension + 1];
    for (unsigned int i = 0; i <= dimension; i++) {
        this->coeffs[i] = poly.coeffs[i];
    }
}
Polynomial::~Polynomial() {
    reset();
}
double Polynomial::getCoeffs(const unsigned int index) const{
    if (coeffs == 0) {
        return 0.0;
    } else {
        return coeffs[index];
    }
}
double Polynomial::evaluate (double x) const{
    double polyTotal = 0;
    for (int i = getDimension(); i >= 0; i--) {
        polyTotal += std::pow(x, i) * getCoeffs(i);
    }
    return polyTotal;
}
void Polynomial::setCoeffs(unsigned int k, double value){
    if (k <= getDimension()) {
        coeffs[k] = value;
    }
    if ( value != 0.0 && k > getDimension()) {
        Polynomial temp(k);
        for (unsigned int i = 0; i <= temp.getDimension(); i++) {
            if (i > getDimension()) {
                if (i == k) {
                    coeffs[i] = value;
                } else {
                    coeffs[i] = 0.0;
                }
            } else {
                coeffs[i] = getCoeffs(i);
            }
        }
        *this = temp;
    }
}
Polynomial& Polynomial::operator = (const Polynomial& poly2) {
    if (this == &poly2)
    {
        return *this;
    } else {
        this->dimension = poly2.getDimension();
        reset();
        this->coeffs = new double[getDimension() + 1];
        for (int i = 0; i <= getDimension(); i++) {
            this->coeffs[i] = poly2.coeffs[i];
        }
        reduce();
        return *this;
    }
}
void Polynomial::reduce() {
    int tdeg = dimension;
    for (int i = dimension; i >= 0; i--) {
        if (coeffs[i] != 0.0) {
            double* tempCoefs = new double[tdeg + 1];
            for (int i = 0; i <= tdeg; i++) {
                tempCoefs[i] = coeffs[i];
            }
            dimension = tdeg;
            coeffs = tempCoefs;
            break;
        } else {
            tdeg--;
        }
    }
    if (tdeg == -1) {
        dimension = 0;
    }
}
Polynomial operator +(const Polynomial& poly1, const Polynomial& poly2) {
    unsigned int dim;
    if (poly1.getDimension() > poly2.getDimension()) {
        dim = poly1.getDimension();
    }
    else {
        dim = poly2.getDimension();
    }
    double *sum = new double [dim + 1];
    for (int i = 0; i < dim + 1; i++) {
        sum[i] = 0.0;
    }
    for (int i = 0; i < poly1.getDimension() + 1; i++) {
        sum[i] = poly1.getCoeffs(i);
    }
    for (int i = 0; i < poly2.getDimension() + 1; i++){
        sum[i] += poly2.getCoeffs(i);
    }
    Polynomial result(sum, dim + 1);
    result.reduce();
    return result;
}
Polynomial operator -(const Polynomial& poly1, const Polynomial& poly2) {
    unsigned int dim;
    if (poly1.getDimension() > poly2.getDimension()) {
        dim = poly1.getDimension();
    }
    else {
        dim = poly2.getDimension();
    }
    double *diff = new double [dim + 1];
    for (int i = 0; i < dim + 1; i++) {
        diff[i] = 0.0;
    }
    for (int i = 0; i < poly1.getDimension() + 1; i++) {
        diff[i] = poly1.getCoeffs(i);
    }
    for (int i = 0; i < poly2.getDimension() + 1; i++){
        diff[i] -= poly2.getCoeffs(i);
    }
    Polynomial result(diff, dim + 1);
    result.reduce();
    return result;
}
Polynomial Polynomial::operator -() const {
    Polynomial result(getDimension() + 1);
    for (int i = 0; i < result.getDimension() + 1; i++) {
        result.coeffs[i] = -(this->coeffs[i]);
    }
    return result;
}
Polynomial operator *(const Polynomial& poly1, const Polynomial& poly2) {
    unsigned int size = poly1.getDimension() + poly2.getDimension() + 1;
    double *mult = new double[size];
    for (int i = 0; i < size; i++){
        mult[i] = 0.0;
    }
    for (int i = 0; i < poly1.getDimension() + 1; i++) {
        for (int j = 0; j < poly2.getDimension() + 1; j++){
            mult[i + j] += poly1.getCoeffs(i) * poly2.getCoeffs(j);
        }
    }
    Polynomial result(mult, size); 
    result.reduce();
    return result;
}
Polynomial operator /(const Polynomial& poly1, const Polynomial& poly2) {
    double quotient;
    unsigned int size;
    Polynomial result;
    Polynomial remains;
    Polynomial resOfMult;
    if (poly1.getDimension() < poly2.getDimension()) {
        throw std::logic_error("The degree of the second polynomial is greater than the first!");
    }
    for (int i = poly1.getDimension(), j = poly2.getDimension(); i >= 0; i--) {
        if (i == poly1.getDimension()) {
            quotient = poly1.getCoeffs(i) / poly2.getCoeffs(j);
            size = poly1.getDimension() - poly2.getDimension() + 1;
            Polynomial temp(size);
            temp.setCoeffs(size - 1, quotient);
            resOfMult = temp * poly2;
            remains = poly1 - resOfMult;
            result += temp;
            if (remains.getDimension() < poly2.getDimension()) {
                return result;
            }
        } else {
            quotient = remains.getCoeffs(remains.getDimension()) / poly2.getCoeffs(j);
            size = remains.getDimension() - poly2.getDimension() + 1;
            Polynomial temp(size);
            temp.setCoeffs(size - 1, quotient);
            resOfMult = temp * poly2;
            remains.reduce();
            remains = remains - resOfMult;
            result += temp;
            if ((remains.getDimension() < poly2.getDimension()) || (remains.getDimension()==0)) {
                return result;
            }
        }
    }
    return poly1;
}
Polynomial operator %(const Polynomial& poly1, const Polynomial& poly2) {
    double quotient;
    unsigned int size;
    Polynomial result;
    Polynomial remains;
    Polynomial resOfMult;
    
    for (int i = poly1.getDimension(), j = poly2.getDimension(); i >= 0; i--) {
        if (i == poly1.getDimension()) {
            quotient = poly1.getCoeffs(i) / poly2.getCoeffs(j);
            size = poly1.getDimension() - poly2.getDimension() + 1;
            Polynomial temp(size);
            temp.setCoeffs(size-1, quotient);
            resOfMult = temp * poly2;
            resOfMult.reduce();
            remains = poly1 - resOfMult;
            result += temp;
            if (remains.getDimension() < poly2.getDimension()) {
                return remains;
            }
        } else {
            quotient = remains.getCoeffs(remains.getDimension()) / poly2.getCoeffs(j);
            size = remains.getDimension() - poly2.getDimension() + 1;
            Polynomial temp(size);
            temp.setCoeffs(size-1, quotient);
            resOfMult = temp * poly2;
            resOfMult.reduce();
            remains.reduce();
            remains = remains - resOfMult;
            result += temp;
            if (remains.getDimension() < poly2.getDimension()) {
                return remains;
            }
        }
    }
    return poly1;
}
Polynomial& Polynomial::operator +=(const Polynomial& poly) {
    if (this == &poly){
        return *this;
    }
    double min_dimension;
    if (getDimension() >= poly.getDimension()) {
        min_dimension = poly.getDimension();
    } else {
        min_dimension = getDimension();
    }
    for (unsigned int i = 0; i <= min_dimension; i++) {
        coeffs[i] += poly.coeffs[i];
    }
    if (min_dimension == poly.dimension) {
        return *this;
    }
	double* new_coeffs = new double[poly.dimension + 1];
    for (unsigned int i = 0; i <= dimension; i++) {
        new_coeffs[i] = coeffs[i];
    }
    for (unsigned int i = dimension + 1; i <= poly.dimension; i++) {
        new_coeffs[i] = poly.coeffs[i];
    }
	dimension = poly.getDimension();
	coeffs = new_coeffs;
    reduce();
	return *this;
}
Polynomial& Polynomial::operator -=(const Polynomial& poly) {
    if (this == &poly){
        return *this;
    }
    double min_dimension;
    if (getDimension() >= poly.getDimension()) {
        min_dimension = poly.getDimension();
    } else {
        min_dimension = getDimension();
    }
    for (unsigned int i = 0; i <= min_dimension; i++) {
        coeffs[i] -= poly.coeffs[i];
    }
    if (min_dimension == poly.dimension) {
        return *this;
    }
    double* new_coeffs = new double[poly.dimension + 1];
    for (unsigned int i = 0; i <= dimension; i++) {
        new_coeffs[i] = coeffs[i];
    }
    for (unsigned int i = dimension + 1; i <= poly.dimension; i++) {
        new_coeffs[i] = poly.coeffs[i];
    }
    dimension = poly.getDimension();
    coeffs = new_coeffs;
    reduce();
    return *this;
}
Polynomial& Polynomial::operator *=(const Polynomial& poly) {
	const unsigned int new_dimension = getDimension() + poly.getDimension();
	double* new_coeffs = new double[new_dimension + 1];
    for (unsigned int i = 0; i <= new_dimension; i++) {
        new_coeffs[i] = 0;
    }
    for (unsigned int i = 0; i <= getDimension(); i++) {
        for (unsigned int j = 0; j <= poly.getDimension(); j++) {
            new_coeffs[i + j] += coeffs[i] * poly.coeffs[j];
        }
    }
	dimension = new_dimension;
	coeffs = new_coeffs;
	return *this;
}
Polynomial& Polynomial::operator /=(const Polynomial& poly2) {
    double quotient;
    unsigned int size;
    Polynomial result;
    Polynomial remains;
    Polynomial resOfMult;
    
    for (int i = getDimension(), j = poly2.getDimension(); i >= 0; i--) {
        if (i == getDimension()) {
            quotient = getCoeffs(i) / poly2.getCoeffs(j);
            size = getDimension() - poly2.getDimension() + 1;
            Polynomial temp(size);
            temp.setCoeffs(size - 1, quotient);
            resOfMult = temp * poly2;
            remains = *this - resOfMult;
            result = temp;
            if (remains.getDimension() < poly2.getDimension()) {
                return *this = result;
            }
        } else {
            quotient = remains.getCoeffs(remains.getDimension()) / poly2.getCoeffs(j);
            size = remains.getDimension() - poly2.getDimension() + 1;
            Polynomial temp(size);
            temp.setCoeffs(size - 1, quotient);
            resOfMult = temp * poly2;
            remains.reduce();
            remains = remains - resOfMult;
            result = result + temp;
            if (remains.getDimension() < poly2.getDimension()) {
                return *this = result;
            }
        }
    }
    return *this;
}
Polynomial& Polynomial::operator %=(const Polynomial& poly2) {
    double quotient;
    unsigned int size;
    Polynomial result;
    Polynomial remains;
    Polynomial resOfMult;
    
    for (int i = getDimension(), j = poly2.getDimension(); i >= 0; i--) {
        if (i == getDimension()) {
            quotient = getCoeffs(i) / poly2.getCoeffs(j);
            size = getDimension() - poly2.getDimension() + 1;
            Polynomial temp(size);
            temp.setCoeffs(size - 1, quotient);
            resOfMult = temp * poly2;
            remains = *this - resOfMult;
            result = temp;
            if (remains.getDimension() < poly2.getDimension()) {
                return *this = remains;
            }
        } else {
            quotient = remains.getCoeffs(remains.getDimension()) / poly2.getCoeffs(j);
            size = remains.getDimension() - poly2.getDimension() + 1;
            Polynomial temp(size);
            temp.setCoeffs(size - 1, quotient);
            resOfMult = temp * poly2;
            remains.reduce();
            remains = remains - resOfMult;
            result = result + temp;
            if (remains.getDimension() < poly2.getDimension()) {
                return *this = remains;
            }
        }
    }
    return *this;
}
double& Polynomial::operator [](const unsigned int index) const {
	return coeffs[index];
}
double& Polynomial::at(const unsigned int index) const {
    if (index <= dimension) {
        return coeffs[index];
    } else {
        throw std::logic_error("out of bounds");
    }
}
std::istream& operator >>(std::istream& in, Polynomial& poly) {
    for (int i = 0; i <= poly.getDimension(); i++) {
		in >> poly[i];
	}
	return in;
}
std::ostream& operator <<(std::ostream& out, const Polynomial& poly) {
    for (unsigned int i = poly.getDimension(); i > 0 ; i--) {
        if (((poly.getCoeffs(poly.getDimension())) < 0) && (i == poly.getDimension())) { out << " - "; }

        if (i == 1) {
            if (poly.getCoeffs(1) != 0) {
                out << abs(poly.getCoeffs(i)) << "x";
            }
        } else {
            if (poly.getCoeffs(i) != 0) {
                out << abs(poly.getCoeffs(i)) << "x^" << i;
            }
        }

        if (poly.getCoeffs(i - 1) < 0) {
            if (i == 1) {

            } else {
                out << " - ";
            }
        } else if (poly.getCoeffs(i - 1) != 0) {
            if (i == 1) {

            } else {
                out << " + ";
            }
        }
	}
    if (poly.getCoeffs(0) < 0) {
        out << " - ";
        out << abs(poly.getCoeffs(0)) << std::endl;
    }
    else if (poly.getCoeffs(0) > 0) {
        if (poly.getDimension() > 0) {
            out << " + ";
        }
        out << abs(poly.getCoeffs(0)) << std::endl;
    } else {
        out << std::endl;
    }
	return out;
}
