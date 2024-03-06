#include "../s21_math.h"

long double s21_tan(double x) {
  x = s21_fmod(x, S21_PI);
  long double res = s21_cos(x);
  return !res ? S21_NAN : s21_sin(x) / res;
}
