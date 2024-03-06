#include "../s21_math.h"

long double s21_sqrt(double x) {
  long double res = s21_pow(x, 0.5);
  if (S21_IS_NAN(x) || x == S21_NEG_INF || x < 0) {
    res = S21_NAN;
  }
  if (x == S21_POS_INF || x == 0) {
    res = (long double)x;
  }
  return res;
}