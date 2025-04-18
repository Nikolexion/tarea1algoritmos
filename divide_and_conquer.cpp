/***
 * El código de la funcion divide_and_conquer está basado en el algoritmo de la página
 * https://www.geeksforgeeks.org/closest-pair-of-points-using-divide-and-conquer-algorithm/
 *  **/


#include "divide_and_conquer.h"
#include "bruteforce.h"
#include <algorithm>
#include <cmath>
#include <cfloat>
#include <vector>

double divide_and__conquer(std::pair<double, double> n[], int tam, bool esta_desordenado) {
    if (esta_desordenado) {
        // Ordena solo una vez al comienzo según la variable x
        std::sort(n, n + tam);
    }

    if (tam <= 3)
        return bruteforce(n, tam);

    int mid = tam / 2;
    std::pair<double, double> midPoint = n[mid];

    double d1 = divide_and__conquer(n, mid, false);
    double d2 = divide_and__conquer(n + mid, tam - mid, false);
    double d = std::min(d1, d2);

    std::vector<std::pair<double, double>> strip;
    for (int i = 0; i < tam; ++i) {
        if (std::abs(n[i].first - midPoint.first) < d)
            strip.push_back(n[i]);
    }

    std::sort(strip.begin(), strip.end(), [](const std::pair<double, double>& a, const std::pair<double, double>& b) {
        return a.second < b.second;
    });

    for (int i = 0; i < static_cast<int>(strip.size()); ++i) {
        for (int j = i + 1; j < static_cast<int>(strip.size()) && (strip[j].second - strip[i].second) < d; ++j) {
            double dist = calculateDistance(strip[i], strip[j]);
            if (dist < d)
                d = dist;
        }
    }

    return d;
}