#ifndef DISTANCE_EUCL
#define DISTANCE_EUCL

#include <cmath>
#include <utility>

double calculateDistance(std::pair<double, double> p1, std::pair<double, double> p2);
double optimized_calculateDistance(const std::pair<double,double>& p1, const std::pair<double,double>& p2);

#endif