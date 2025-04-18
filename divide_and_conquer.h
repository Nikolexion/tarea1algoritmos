#ifndef DIVIDE_AND_CONQUER
#define DIVIDE_AND_CONQUER
#include "distancia_euc.h"

bool compararX(const std::pair<double, double>& a, const std::pair<double, double>& b);
bool compararY(const std::pair<double, double>& a, const std::pair<double, double>& b);
double divide_and__conquer(std::pair<double, double> n[], int tam, bool esta_desordenado);

#endif