#include "distancia_euc.h"

double calculateDistance(std::pair<double,double> p1, std::pair<double, double> p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

double optimized_calculateDistance(const std::pair<double,double>& p1, const std::pair<double,double>& p2) {
    double dx = p1.first - p2.first;
    double dy = p1.second - p2.second;
    return dx * dx + dy * dy;
}
    