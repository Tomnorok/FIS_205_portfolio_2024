#include <iostream>
#include <cmath>

class FuncionesTrigonometricas {
public:
    static const int PRECISION = 10; // Número de términos para asegurar la precisión decimal

    static double sin(double x) {
        double suma = 0.0;
        double signo = 1.0;
        for (int n = 0; n < PRECISION; ++n) {
            double term = signo * std::pow(x, 2 * n + 1) / factorial(2 * n + 1);
            suma += term;
            signo *= -1.0; // Cambiar el signo para el siguiente término
        }
        return suma;
    }

    static double cos(double x) {
        double suma = 0.0;
        double signo = 1.0;
        for (int n = 0; n < PRECISION; ++n) {
            double term = signo * std::pow(x, 2 * n) / factorial(2 * n);
            suma += term;
            signo *= -1.0; // Cambiar el signo para el siguiente término
        }
        return suma;
    }

    static double tan(double x) {
        return sin(x) / cos(x);
    }

    static double sec(double x) {
        return 1.0 / cos(x);
    }

    static double csc(double x) {
        return 1.0 / sin(x);
    }

private:
    static double factorial(int n) {
        double result = 1.0;
        for (int i = 1; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
};

int main() {
    double x = M_PI / 4; // 45 grados en radianes
    std::cout << "Seno: " << FuncionesTrigonometricas::sin(x) << std::endl;
    std::cout << "Coseno: " << FuncionesTrigonometricas::cos(x) << std::endl;
    std::cout << "Tangente: " << FuncionesTrigonometricas::tan(x) << std::endl;
    std::cout << "Secante: " << FuncionesTrigonometricas::sec(x) << std::endl;
    std::cout << "Cosecante: " << FuncionesTrigonometricas::csc(x) << std::endl;
    return 0;
}
