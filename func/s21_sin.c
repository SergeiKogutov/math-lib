#include "../s21_math.h"

long double s21_sin(double x) {
  long double res = 0.0;
  if (S21_ISNAN(x)) {
    res = S21_NAN;
  } else if (x == S21_POS_INF) {
    return S21_POS_INF;
  } else {
    x = s21_fmod(x, 2 * S21_PI);
    for (int i = 0; i < 15; i++) {
      res += s21_pow_int(-1, i) * s21_pow_int(x, 2 * i + 1) /
             s21_fuctorial(2 * i + 1);
    }
  }
  return res;
}
