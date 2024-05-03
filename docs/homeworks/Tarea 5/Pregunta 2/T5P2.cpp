#include <iostream>
#include <stdexcept>

class Matrix2x2 {
private:
    double data[2][2];

public:
    // Default constructor
    Matrix2x2() {
        data[0][0] = data[0][1] = data[1][0] = data[1][1] = 0.0;
    }

    // Constructor that initializes the matrix with specific values
    Matrix2x2(double a, double b, double c, double d) {
        data[0][0] = a;
        data[0][1] = b;
        data[1][0] = c;
        data[1][1] = d;
    }

    // Copy constructor
    Matrix2x2(const Matrix2x2& other) {
        data[0][0] = other.data[0][0];
        data[0][1] = other.data[0][1];
        data[1][0] = other.data[1][0];
        data[1][1] = other.data[1][1];
    }

    // Assignment operator
    Matrix2x2& operator=(const Matrix2x2& other) {
        if (this != &other) {
            data[0][0] = other.data[0][0];
            data[0][1] = other.data[0][1];
            data[1][0] = other.data[1][0];
            data[1][1] = other.data[1][1];
        }
        return *this;
    }

    // Unary subtraction operator
    Matrix2x2 operator-() const {
        return Matrix2x2(-data[0][0], -data[0][1], -data[1][0], -data[1][1]);
    }

    // Binary addition operator
    Matrix2x2 operator+(const Matrix2x2& other) const {
        return Matrix2x2(data[0][0] + other.data[0][0], data[0][1] + other.data[0][1],
                         data[1][0] + other.data[1][0], data[1][1] + other.data[1][1]);
    }

    // Binary subtraction operator
    Matrix2x2 operator-(const Matrix2x2& other) const {
        return Matrix2x2(data[0][0] - other.data[0][0], data[0][1] - other.data[0][1],
                         data[1][0] - other.data[1][0], data[1][1] - other.data[1][1]);
    }

    // Method to multiply matrix by a constant
    Matrix2x2 operator*(double scalar) const {
        return Matrix2x2(data[0][0] * scalar, data[0][1] * scalar,
                         data[1][0] * scalar, data[1][1] * scalar);
    }

    // Function to get the determinant of the matrix
    double determinant() const {
        return data[0][0] * data[1][1] - data[0][1] * data[1][0];
    }

    // Function to get the inverse of the matrix
    Matrix2x2 inverse() const {
        double det = determinant();
        if (det == 0) {
            throw std::runtime_error("Inverse does not exist for matrices with zero determinant.");
        }
        return Matrix2x2(data[1][1] / det, -data[0][1] / det,
                         -data[1][0] / det, data[0][0] / det);
    }

    // Function to print matrix (for debugging and output purposes)
    void print() const {
        std::cout << "[" << data[0][0] << ", " << data[0][1] << "]\n"
                  << "[" << data[1][0] << ", " << data[1][1] << "]" << std::endl;
    }
};

// To use and test the class
int main() {
    Matrix2x2 A(1, 2, 3, 4);
    Matrix2x2 B(2, 3, 4, 5);
    Matrix2x2 C;

    C = A + B;
    C.print();

    C = A - B;
    C.print();

    C = -A;
    C.print();

    C = A * 2.5;
    C.print();

    try {
        Matrix2x2 invA = A.inverse();
        invA.print();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
