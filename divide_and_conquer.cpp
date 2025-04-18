/***
 * El código de la funcion divide_and_conquer está basado en el algoritmo de la página
 * https://www.geeksforgeeks.org/closest-pair-of-points-using-divide-and-conquer-algorithm/ 
 * 
 ***/


#include "divide_and_conquer.h"
#include "bruteforce.h"
#include <algorithm>
#include <cmath>
#include <cfloat>
#include <vector>

/// Comparador para ordenar según coordenadas X
bool compararX(const std::pair<double, double>& a, const std::pair<double, double>& b) {
    return a.first < b.first;
}   
/// Comparador para ordenar según coordenadas Y
bool compararY(const std::pair<double, double>& a, const std::pair<double, double>& b) {
    return a.second < b.second;
}

/// @brief  Algoritmo Divide and Conquer para encontrar la distancia euclidiana mínima entre dos puntos
/// @param n Arreglo de puntos (pares de coordenadas x, y)
/// @param tam Tamaño del arreglo
/// @param esta_desordenado Booleano usado para ordenar por coordenadas X si es necesario
/// @return Distancia mínima entre los puntos
double divide_and_conquer(std::pair<double, double> n[], int tam, bool esta_desordenado) {
    if (esta_desordenado) {
        std::sort(n, n + tam, compararX);
    }

    if (tam <= 3)
        return bruteforce(n, tam);

    int mid = tam / 2;
    std::pair<double, double> midPoint = n[mid];

    double d1 = divide_and_conquer(n, mid, false);
    double d2 = divide_and_conquer(n + mid, tam - mid, false);
    double d = std::min(d1, d2);

    std::vector<std::pair<double, double>> strip;
    for (int i = 0; i < tam; i++) {
        if (std::abs(n[i].first - midPoint.first) < d)
            strip.push_back(n[i]);
    }

    std::sort(strip.begin(), strip.end(), compararY);

    for (size_t i = 0; i < strip.size(); i++) {
        for (size_t j = i + 1; j < strip.size() && (strip[j].second - strip[i].second) < d; j++) {
            double dist = calculateDistance(strip[i], strip[j]);
            if (dist < d)
                d = dist;
        }
    }

    return d;
}