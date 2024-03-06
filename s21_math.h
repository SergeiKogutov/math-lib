#ifndef S21_MATH_H_
#define S21_MATH_H_
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_POS_INF +1.0 / 0.0
#define S21_NEG_INF -1.0 / 0.0
#define S21_NAN 0.0 / 0.0
#define S21_IS_NAN(x) (x != x)
#define S21_LN2 0.69314718055994530941
#define S21_E 2.7182818284590452353602874
#define S21_IS_INF(x) (x == S21_NEG_INF || x == S21_POS_INF)
#define S21_ISNAN(x) (!(x >= 0) && !(x < 0))

#define S21_PI 3.14159265358979323846264338327950288
#define S21_PI_2 S21_PI / 2
#define S21_PI_3 S21_PI / 3
#define S21_PI_4 S21_PI / 4
#define S21_PI_6 S21_PI / 6
#define S21_PI_8 S21_PI / 8
#define S21_PI_X2 S21_PI * 2
#define S21_PI_X4 S21_PI * 4
#define S21_PI_X8 S21_PI * 8
#define S21_EPS10 0.0000000001
#define MAX_LONG_DOUBLE 1.79769313486231571e+308

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double s21_pow_int(double base, double exp);
long double s21_fuctorial(long long int x);
int is_nan_answer(double x, double y);

#endif