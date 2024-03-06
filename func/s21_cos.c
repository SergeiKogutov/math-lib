#include "../s21_math.h"

long double s21_cos(double x) {
  long double res = S21_NAN;
  if (x != S21_POS_INF || x != S21_NEG_INF || !S21_IS_NAN(x)) {
    res = s21_sin(S21_PI / 2 - x);
  }
  return res;
}