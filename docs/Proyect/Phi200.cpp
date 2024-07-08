#include <iostream>
#include <fstream>
#include <cmath>
#include <random>
#include <vector>

const double a0 = 1.0; // Radio de Bohr

// Definir las funciones de onda
double phi_200(double r) {
    return (1.0 / (4 * sqrt(2 * M_PI * pow(a0, 3)))) * (2 - r / a0) * exp(-r / (2 * a0));
}

double phi_21m1(double r) {
    return (1.0 / (8 * sqrt(6 * M_PI * pow(a0, 3)))) * (r / a0) * exp(-r / (2 * a0));
}

// Implementar el algoritmo de Metropolis-Hastings
std::vector<double> metropolis_hastings(int num_samples, double initial_r, double step_size, int burn_in, double (*phi)(double)) {
    std::vector<double> samples;
    samples.reserve(num_samples);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    std::uniform_real_distribution<> step_dis(-step_size, step_size);

    double current_r = initial_r;
    double current_prob = pow(phi(current_r), 2); // Distribución proporcional a |Phi|^2

    // Fase de burn-in
    for (int i = 0; i < burn_in; ++i) {
        double proposed_r = current_r + step_dis(gen);
        if (proposed_r < 0) proposed_r = -proposed_r; // Reflejar en el origen para mantener r positivo

        double proposed_prob = pow(phi(proposed_r), 2);
        double acceptance_ratio = proposed_prob / current_prob;

        if (dis(gen) < acceptance_ratio) {
            current_r = proposed_r;
            current_prob = proposed_prob;
        }
    }

    // Recolección de muestras después de burn-in
    for (int i = 0; i < num_samples; ++i) {
        double proposed_r = current_r + step_dis(gen);
        if (proposed_r < 0) proposed_r = -proposed_r; // Reflejar en el origen para mantener r positivo

        double proposed_prob = pow(phi(proposed_r), 2);
        double acceptance_ratio = proposed_prob / current_prob;

        if (dis(gen) < acceptance_ratio) {
            current_r = proposed_r;
            current_prob = proposed_prob;
        }

        samples.push_back(current_r);
    }

    return samples;
}

int main() {
    int num_samples = 50000; // Incrementar el número de muestras
    int burn_in = 10000; // Incrementar el número de iteraciones de burn-in
    double initial_r = a0; // Empezamos con el radio de Bohr
    double step_size = 0.05 * a0; // Ajustar el tamaño del paso

    // Generar muestras para Phi_200
    std::vector<double> samples_200 = metropolis_hastings(num_samples, initial_r, step_size, burn_in, phi_200);
    std::ofstream outfile_200("samples_200.txt");
    for (double sample : samples_200) {
        outfile_200 << sample << "\n";
    }
    outfile_200.close();

    // Generar muestras para Phi_21m1
    std::vector<double> samples_21m1 = metropolis_hastings(num_samples, initial_r, step_size, burn_in, phi_21m1);
    std::ofstream outfile_21m1("samples_21m1.txt");
    for (double sample : samples_21m1) {
        outfile_21m1 << sample << "\n";
    }
    outfile_21m1.close();

    // Imprimir algunos valores de ejemplo en la consola para Phi_200
    std::cout << "Primeros 20 valores muestreados para Phi_200:" << std::endl;
    for (int i = 0; i < 20 && i < samples_200.size(); ++i) {
        std::cout << samples_200[i] << std::endl;
    }

    // Imprimir algunos valores de ejemplo en la consola para Phi_21m1
    std::cout << "Primeros 20 valores muestreados para Phi_21m1:" << std::endl;
    for (int i = 0; i < 20 && i < samples_21m1.size(); ++i) {
        std::cout << samples_21m1[i] << std::endl;
    }

    return 0;
}
