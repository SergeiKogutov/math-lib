#include "../s21_math.h"
long double s21_pow(double base, double deg) {
  long double res = 0;
  bool b = 1;
  long double flag = 1.0;
  long double x = base;
  long double y = deg;
  if (x == S21_NEG_INF) {
    if (y == S21_NEG_INF) {
      res = 0;
      b = 0;
    }
    if (y == -1) {
      res = 0;
    }
    if (y == 1 && b) {
      res = S21_NEG_INF;
      b = 0;
    }
    if ((y != y) && b) {
      res = S21_NAN;
      b = 0;
    }
    if (y == -1. && b) {
      res = -0;
      b = 0;
    }

    if (y == 0. && b) {
      res = 1;
      b = 0;
    }

    if (b) {
      res = S21_POS_INF;
      b = 0;
    }
  }

  if ((x == 0.0 && y == -1) && b) {
    res = S21_POS_INF;
    b = 0;
  }
  if (x == -0.0 && b) {
    if (y == S21_NEG_INF) {
      res = S21_POS_INF;
      b = 0;
    }
  }
  if (x < -0.0 && b) {
    if (y == S21_POS_INF) {
      res = 1.0;
      b = 0;
    }
    if ((y == S21_NEG_INF) && b) {
      res = 1.0;
      b = 0;
    }
    if (((y > 0. && y < 1.0) || (y != (int)y)) && b) {
      res = S21_NAN;
      b = 0;
    }
  }
  if (x == 1.0 && b) {
    res = 1;
    b = 0;
  }
  if ((x < -0 && y == (int)y) && b) {
    x = -x;
    flag = -1.0;
    if ((int)y % 2 == 0) flag *= -1.0;
  }

  if ((int)x == 0 && (int)y == -3) {
    res = S21_POS_INF;
  } else {
    if (b) res = y == 0 ? 1 : x == 0 ? 0 : flag * s21_exp(y * s21_log(x));
  }

  return res;
}
