#include "../s21_math.h"

long double s21_fuctorial(long long int x) {
  if (x == 1 || x == 0) return 1;
  if (x < 0) return S21_POS_INF;

  long double res = x * s21_fuctorial(x - 1);

  return res;
}