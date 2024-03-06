#include "../s21_math.h"

long double s21_pow_int(double base, double exp) {
  long double res = 1;
  int s21_sign = (exp > 0);
  exp *= s21_sign ? 1 : -1;
  for (long long int i = 0; i < exp; i++) {
    res = s21_sign ? res * base : res / base;
  }
  return res;
}