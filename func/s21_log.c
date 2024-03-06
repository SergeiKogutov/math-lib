#include "../s21_math.h"

long double s21_log(double x) {
  if (x == S21_POS_INF) {
    return x;
  }
  if (x == 0) {
    return S21_NEG_INF;
  }
  if (x < 0) {
    return S21_NAN;
  }
  long double res = 0, count = 0;
  int count_e = 0;
  for (; x >= S21_E; count_e++) {
    x /= S21_E;
  }
  for (int i = 0; i < 1000; i++) {
    count = res;
    res = count + 2 * (x - s21_exp(count)) / (x + s21_exp(count));
  }
  res += count_e;
  return res;
}