#include "../s21_math.h"

long double s21_ceil(double x) {
  double res;
  if (x != x) {
    res = x;
  } else if (x == S21_POS_INF) {
    res = S21_POS_INF;
  } else if (x == S21_NEG_INF) {
    res = S21_NEG_INF;
  } else {
    res = (x - (long long int)x != 0 && x > 0) ? (long long int)x + 1
                                               : (long long int)x;
  }
  return res;
}