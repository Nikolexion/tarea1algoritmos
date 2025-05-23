#include "bruteforce.h"
#include <cfloat> // For DBL_MAX


double bruteforce(std::pair<double,double> n[], int tam) {
    double dist_min = -1;
    int index_min = -1;

    for (int i = 0; i < tam; i++) {
        for (int j = i + 1; j < tam; j++) {
            double aux = calculateDistance(n[i], n[j]);
            if (dist_min == -1 || aux < dist_min) {
                dist_min = aux;
                index_min = i;
            }
        }
    }

    return dist_min;
}



double bruteforce_optimized(const std::pair<double,double> n[], int tam){
    double dist_min = DBL_MAX;

    for (int i = 0; i < tam; i++) {
        for (int j = i + 1; j < tam; j++) {
            double aux = calculateDistance(n[i], n[j]);
            if (dist_min == -1 || aux < dist_min) {
                dist_min = aux;
            }
        }
    }

    return dist_min;
}