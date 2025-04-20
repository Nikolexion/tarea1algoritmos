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

/// @brief  D&C levemente optimizado, eliminando el uso de la función sqrt y pow en la
///         comparación de distancias, junto a otras pequeñas modificaciones.
/// @param n Arreglo de puntos (pares de coordenadas x, y)
/// @param tam Tamaño del arreglo
/// @param esta_desordenado Booleano usado para ordenar por coordenadas X si es necesario
/// @return Distancia mínima entre los puntos
double optimized_divide_and_conquer(std::pair<double, double> n[], int tam, bool esta_desordenado) {
    if (esta_desordenado) {
        std::sort(n, n + tam, compararX);
    }

    if (tam <= 3)
        return bruteforce(n, tam);

    int mid = tam / 2;
    const auto& midPoint = n[mid]; // Hacemos un pequeño cambio para utilizar solo X

    double d1 = optimized_divide_and_conquer(n, mid, false);
    double d2 = optimized_divide_and_conquer(n + mid, tam - mid, false);
    double d = std::min(d1, d2);
    double d_sq = d * d;
    std::vector<std::pair<double, double>> strip;
    for (int i = 0; i < tam; i++) {
        if (std::abs(n[i].first - midPoint.first) < d)
            strip.push_back(n[i]);
    }

    std::sort(strip.begin(), strip.end(), compararY);
    int strip_s = strip.size();
    for (int i = 0; i < strip_s; i++) {
        for (int j = i + 1; j < strip_s && (strip[j].second - strip[i].second) < d; j++) {
            double dist_sq = optimized_calculateDistance(strip[i], strip[j]);
            if (dist_sq < d_sq)
                d_sq = dist_sq;
        }
    }

    return std::sqrt(d_sq);
}