#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <fstream>
using namespace std;

int main() {
    //dimension
    int dimension = 5000;
    ofstream file("files/5000.txt");
    // Crear un generador de números aleatorios
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);

    // Generar 100 puntos aleatorios en dimensión 10
    vector<vector<double>> puntos;
    for (int i = 0; i < 100; ++i) {
        vector<double> punto(dimension);
        for (int j = 0; j < dimension; ++j) {
            punto[j] = dis(gen);  // Generar un valor aleatorio entre 0 y 1
        }
        puntos.push_back(punto);
    }

    // Calcular la distancia Euclidiana entre todos los pares de puntos

    for (int i = 0; i < 100; ++i) {
        for (int j = i + 1; j < 100; ++j) {
            double distancia = 0.0;
            for (int k = 0; k < dimension; ++k) {
                double diff = puntos[i][k] - puntos[j][k];
                distancia += diff * diff;
            }
            distancia = sqrt(distancia);  // Aplicar la raíz cuadrada para obtener la distancia Euclidiana
            file << distancia << endl;
        }
    }

    return 0;
}
