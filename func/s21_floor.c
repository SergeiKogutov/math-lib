#include "../s21_math.h"

long double s21_floor(double x) {
  if (S21_IS_NAN(x) || S21_IS_INF(x)) {
    return x;
  }
  int res = (int)x;
  res -= (x < 0 && (x - res));
  return (long double)res;
}