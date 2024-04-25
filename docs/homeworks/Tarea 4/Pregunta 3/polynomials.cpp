#include <iostream>
#include <vector>
#include <cmath>

class Polynomial {
private:
    int degree;
    std::vector<double> coefficients;

public:
    // Constructor
    Polynomial(int deg) : degree(deg), coefficients(deg + 1, 0.0) {}

    // Destructor
    ~Polynomial() {}

    // Set coefficient for a given degree
    void setCoefficient(int deg, double coef) {
        if (deg >= 0 && deg <= degree) {
            coefficients[deg] = coef;
        } else {
            std::cerr << "Degree out of range." << std::endl;
        }
    }

    // Get coefficient for a given degree
    double getCoefficient(int deg) const {
        if (deg >= 0 && deg <= degree) {
            return coefficients[deg];
        } else {
            std::cerr << "Degree out of range." << std::endl;
            return 0.0;
        }
    }

    // Addition of two polynomials
    Polynomial operator+(const Polynomial& other) const {
        int maxDegree = std::max(degree, other.degree);
        Polynomial result(maxDegree);
        for (int i = 0; i <= maxDegree; ++i) {
            result.setCoefficient(i, coefficients[i] + other.getCoefficient(i));
        }
        return result;
    }

    // Subtraction of two polynomials
    Polynomial operator-(const Polynomial& other) const {
        int maxDegree = std::max(degree, other.degree);
        Polynomial result(maxDegree);
        for (int i = 0; i <= maxDegree; ++i) {
            result.setCoefficient(i, coefficients[i] - other.getCoefficient(i));
        }
        return result;
    }

    // Multiplication of two polynomials
    Polynomial operator*(const Polynomial& other) const {
        int resultDegree = degree + other.degree;
        Polynomial result(resultDegree);
        for (int i = 0; i <= degree; ++i) {
            for (int j = 0; j <= other.degree; ++j) {
                result.setCoefficient(i + j, result.getCoefficient(i + j) + coefficients[i] * other.getCoefficient(j));
            }
        }
        return result;
    }

    // Output function
    void print() const {
        for (int i = degree; i >= 0; --i) {
            if (coefficients[i] != 0) {
                std::cout << coefficients[i] << "x^" << i;
                if (i > 0) {
                    std::cout << " + ";
                }
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    Polynomial* p1 = new Polynomial(3);
    p1->setCoefficient(0, 2);
    p1->setCoefficient(1, 1);
    p1->setCoefficient(2, 3);
    p1->setCoefficient(3, 4);

    Polynomial* p2 = new Polynomial(2);
    p2->setCoefficient(0, 1);
    p2->setCoefficient(1, 2);
    p2->setCoefficient(2, 3);

    Polynomial p3 = (*p1) + (*p2);
    p3.print();

    Polynomial p4 = (*p1) * (*p2);
    p4.print();

    delete p1;
    delete p2;

    return 0;
}
