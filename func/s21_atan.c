#include "../s21_math.h"

long double s21_atan(double x) {
  long double res = 0;
  if (x == S21_POS_INF) {
    res = S21_POS_INF;
  }
  if (x == S21_NEG_INF) {
    res = S21_NEG_INF;
  }
  if (x == 1) {
    res = S21_PI / 4;
  }
  if (x == -1) {
    res = -S21_PI / 4;
  }
  if (x != x) {
    res = x;
  }
  if (res == 0) {
    int is_a_range = (x > -1 && x < 1);
    res = is_a_range ? x : 1.0 / x;
    for (int i = 1; i < 7000; i++) {
      double a = s21_pow_int(-1, i);
      double b = s21_pow_int(x, (1 + 2 * i) * (is_a_range ? 1 : -1));
      double c = 1 + 2 * i;
      res += a * b / c;
    }
    if (!is_a_range) res = (S21_PI * s21_fabs(x) / (2 * x)) - res;
  }
  return res;
}
