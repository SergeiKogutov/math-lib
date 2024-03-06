#include "s21_math.h"

#include <check.h>
#include <math.h>
#include <stdlib.h>

START_TEST(abs_tests) {
  int inf_pos = 1.0 / 0.0;
  int inf_neg = -1.0 / 0.0;
  int nan = 0.0 / 0.0;

  ck_assert_int_eq(abs(-10), s21_abs(-10));
  ck_assert_int_eq(abs(-0), s21_abs(-0));
  ck_assert_int_eq(abs(-13), s21_abs(-13));
  ck_assert_int_eq(abs(13), s21_abs(13));
  ck_assert_int_eq(abs(-1000), s21_abs(-1000));
  ck_assert_int_eq(abs(32346234), s21_abs(32346234));
  ck_assert_int_eq(abs(0), s21_abs(0));
  ck_assert_int_eq(abs(inf_pos), s21_abs(inf_pos));
  ck_assert_int_eq(abs(inf_neg), s21_abs(inf_neg));
  ck_assert_int_eq(abs(inf_pos), s21_abs(inf_neg));
  ck_assert_int_eq(abs(nan), s21_abs(nan));
}
END_TEST

START_TEST(fabs_tests) {
  ck_assert_double_eq_tol(fabs(-13.21313), s21_fabs(-13.21313), 1e-6);
  ck_assert_double_eq_tol(fabs(13.21313), s21_fabs(13.21313), 1e-6);
  ck_assert_double_eq_tol(fabs(-1000.21313), s21_fabs(-1000.21313), 1e-6);
  ck_assert_double_eq_tol(fabs(32346234.21313), s21_fabs(32346234.21313), 1e-6);
  ck_assert_double_eq_tol(fabs(3.0), s21_fabs(3.0), 1e-6);
  ck_assert_double_eq_tol(fabs(-3.0), s21_fabs(-3.0), 1e-6);
  ck_assert_double_eq_tol(fabs(-0.0), s21_fabs(-0.0), 1e-6);
  ck_assert_double_eq_tol(fabs(0.0), s21_fabs(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(fabs(S21_PI), s21_fabs(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(fabs(S21_PI_2), s21_fabs(S21_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(fabs(S21_PI_3), s21_fabs(S21_PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(fabs(S21_PI_6), s21_fabs(S21_PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(fabs(S21_PI_8), s21_fabs(S21_PI_8), 1e-6);
  ck_assert_double_infinite(s21_fabs(S21_NEG_INF));
  ck_assert_double_infinite(s21_fabs(S21_POS_INF));
  ck_assert_double_nan(s21_fabs(S21_NAN));
}
END_TEST

START_TEST(fmod_tests) {
  ck_assert_double_eq_tol(fmod(-13.21313, 2.5), s21_fmod(-13.21313, 2.5), 1e-6);
  ck_assert_double_eq_tol(fmod(13.21313, 2.5), s21_fmod(13.21313, 2.5), 1e-6);
  ck_assert_double_eq_tol(fmod(-1000.21313, 2.5), s21_fmod(-1000.21313, 2.5),
                          1e-6);
  ck_assert_double_eq_tol(fmod(32346234.21313, 2.5),
                          s21_fmod(32346234.21313, 2.5), 1e-6);
  ck_assert_double_eq_tol(fmod(0, 2.5), s21_fmod(0, 2.5), 1e-6);
  ck_assert_double_eq_tol(fmod(2.5, 2.5), s21_fmod(2.5, 2.5), 1e-6);
  ck_assert_double_eq_tol(fmod(+5.1, +3.0), s21_fmod(+5.1, +3.0), 1e-6);

  ck_assert_double_eq_tol(fmod(-5.1, +3.0), s21_fmod(-5.1, +3.0), 1e-6);
  ck_assert_double_eq_tol(fmod(+5.1, -3.0), s21_fmod(+5.1, -3.0), 1e-6);
  ck_assert_double_eq_tol(fmod(-5.1, -3.0), s21_fmod(-5.1, -3.0), 1e-6);
  ck_assert_double_eq_tol(fmod(+0.0, 1.0), s21_fmod(+0.0, 1.0), 1e-6);
  ck_assert_double_eq_tol(fmod(-0.0, 1.0), s21_fmod(-0.0, 1.0), 1e-6);
  ck_assert_double_eq_tol(fmod(5.1, S21_NEG_INF), s21_fmod(5.1, S21_NEG_INF),
                          1e-6);
  ck_assert_ldouble_nan(s21_fmod(+5.1, 0));
  ck_assert_ldouble_eq_tol(fmod(S21_PI, 3.222), s21_fmod(S21_PI, 3.222), 1e-6);
  ck_assert_ldouble_eq_tol(fmod(S21_PI_2, 3.222), s21_fmod(S21_PI_2, 3.222),
                           1e-6);
  ck_assert_ldouble_eq_tol(fmod(S21_PI_6, 3.222), s21_fmod(S21_PI_6, 3.222),
                           1e-6);
  ck_assert_ldouble_eq_tol(fmod(S21_PI_8, 3.222), s21_fmod(S21_PI_8, 3.222),
                           1e-6);
  ck_assert_double_nan(s21_fmod(S21_NEG_INF, S21_NEG_INF));
  ck_assert_double_nan(s21_fmod(S21_POS_INF, S21_POS_INF));
  ck_assert_double_nan(fmod(S21_POS_INF, S21_NEG_INF));
  ck_assert_double_nan(s21_fmod(S21_NAN, S21_POS_INF));
  ck_assert_ldouble_nan(s21_fmod(S21_POS_INF, S21_NEG_INF));
  ck_assert_ldouble_nan(s21_fmod(S21_NEG_INF, S21_NAN));
}
END_TEST

START_TEST(pow_tests) {
  ck_assert_double_eq_tol(pow(3404.21313, 2.5), s21_pow(3404.21313, 2.5), 1e-6);
  ck_assert_double_eq_tol(pow(0, 2.5), s21_pow(0, 2.5), 1e-6);
  ck_assert_double_eq_tol(pow(123, -2), s21_pow(123, -2), 1e-6);
  ck_assert_ldouble_eq_tol(pow(S21_PI, 3), s21_pow(S21_PI, 3), 1e-6);
  ck_assert_ldouble_eq_tol(pow(S21_PI_2, 3), s21_pow(S21_PI_2, 3), 1e-6);
  ck_assert_ldouble_eq_tol(pow(S21_PI_3, 3), s21_pow(S21_PI_3, 3), 1e-6);
  ck_assert_ldouble_eq_tol(pow(S21_PI_6, 3), s21_pow(S21_PI_6, 3), 1e-6);
  ck_assert_ldouble_eq_tol(pow(S21_PI_8, 3), s21_pow(S21_PI_8, 3), 1e-6);
  ck_assert_ldouble_eq_tol(pow(S21_NEG_INF, 0.0), s21_pow(S21_NEG_INF, 0.0),
                           1e-6);
  ck_assert_double_infinite(s21_pow(-0.0, -1.0));
  ck_assert_ldouble_eq_tol(pow(-1, S21_POS_INF), s21_pow(-1, S21_POS_INF),
                           1e-6);
  ck_assert_double_infinite(s21_pow(-0.0, S21_NEG_INF));
  ck_assert_double_infinite(s21_pow(S21_NEG_INF, 5));
  ck_assert_double_infinite(s21_pow(S21_NEG_INF, 1));
  ck_assert_double_nan(s21_pow(S21_NEG_INF, S21_NAN));
  ck_assert_double_eq(s21_pow(S21_NEG_INF, -1), 0);
  ck_assert_double_infinite(s21_pow(S21_POS_INF, 2));
  ck_assert_ldouble_eq(s21_pow(S21_POS_INF, S21_NEG_INF), 0);
  ck_assert_double_eq(s21_pow(-3.3, S21_NEG_INF), 1);
  ck_assert_double_eq(s21_pow(S21_NEG_INF, S21_NEG_INF), 0);
  ck_assert_double_nan(s21_pow(S21_NAN, S21_POS_INF));
  ck_assert_double_nan(s21_pow(-13.21313, 2.5));
  ck_assert_double_eq(s21_pow(S21_POS_INF, S21_NEG_INF), 0);
  ck_assert_double_eq_tol(pow(2, 10), s21_pow(2, 10), 1e-6);
  ck_assert_double_eq_tol(pow(2, 0.5), s21_pow(2, 0.5), 1e-6);
  ck_assert_double_eq_tol(pow(-2, -3), s21_pow(-2, -3), 1e-6);
  ck_assert_double_nan(s21_pow(-1, S21_NAN));
  ck_assert_double_eq_tol(pow(+1, S21_NAN), s21_pow(+1, S21_NAN), 1e-6);
  ck_assert_double_infinite(s21_pow(S21_NEG_INF, 2));
  ck_assert_double_eq_tol(pow(S21_NEG_INF, -1), s21_pow(S21_NEG_INF, -1), 1e-6);
  ck_assert_double_eq_tol(pow(-1, 1 / 3), s21_pow(-1, 1 / 3), 1e-6);
  ck_assert_double_infinite(s21_pow(-0, -3));
}
END_TEST

START_TEST(ceil_tests) {
  ck_assert_double_eq_tol(ceil(-13.54), s21_ceil(-13.54), 1e-6);
  ck_assert_double_eq_tol(ceil(13.54), s21_ceil(13.54), 1e-6);
  ck_assert_double_eq_tol(ceil(1000), s21_ceil(1000), 1e-6);
  ck_assert_double_eq_tol(ceil(102.0000002), s21_ceil(102.0000002), 1e-6);
  ck_assert_ldouble_eq_tol(ceil(S21_PI), s21_ceil(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(ceil(S21_PI_2), s21_ceil(S21_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(ceil(S21_PI_3), s21_ceil(S21_PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(ceil(S21_PI_6), s21_ceil(S21_PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(ceil(S21_PI_8), s21_ceil(S21_PI_8), 1e-6);
  ck_assert_ldouble_eq_tol(ceil(-0.0), s21_ceil(-0.0), 1e-6);
  ck_assert_double_nan(s21_ceil(S21_NAN));
  ck_assert_double_infinite(s21_ceil(S21_NEG_INF));
  ck_assert_double_infinite(s21_ceil(S21_POS_INF));
}
END_TEST

START_TEST(floor_tests) {
  ck_assert_double_eq_tol(floor(-13.54), s21_floor(-13.54), 1e-6);
  ck_assert_double_eq_tol(floor(13.54), s21_floor(13.54), 1e-6);
  ck_assert_double_eq_tol(floor(1000), s21_floor(1000), 1e-6);
  ck_assert_double_eq_tol(floor(102.0000002), s21_floor(102.0000002), 1e-6);
  ck_assert_ldouble_eq_tol(floor(S21_PI), s21_floor(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(floor(S21_PI_2), s21_floor(S21_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(floor(S21_PI_3), s21_floor(S21_PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(floor(S21_PI_6), s21_floor(S21_PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(floor(S21_PI_8), s21_floor(S21_PI_8), 1e-6);
  ck_assert_ldouble_eq_tol(floor(-0.0), s21_floor(-0.0), 1e-6);
  ck_assert_double_nan(s21_floor(S21_NAN));
  ck_assert_double_infinite(s21_floor(S21_NEG_INF));
  ck_assert_double_infinite(s21_floor(S21_POS_INF));
}
END_TEST

START_TEST(exp_tests) {
  ck_assert_double_eq_tol(exp(-13.54), s21_exp(-13.54), 1e-6);
  ck_assert_double_eq_tol(exp(13.54), s21_exp(13.54), 1e-6);
  ck_assert_double_eq_tol(exp(-0.54), s21_exp(-0.54), 1e-6);
  ck_assert_double_eq_tol(exp(705), s21_exp(705), 1e-6);
  ck_assert_double_eq_tol(exp(1), s21_exp(1), 1e-6);
  ck_assert_double_eq_tol(exp(2), s21_exp(2), 1e-6);
  ck_assert_double_eq_tol(exp(-1), s21_exp(-1), 1e-6);
  ck_assert_double_eq_tol(exp(0), s21_exp(0), 1e-6);
  ck_assert_double_eq_tol(exp(700), s21_exp(700), 1e-6);
  ck_assert_double_eq_tol(exp(1.2345), s21_exp(1.2345), 1e-6);
  ck_assert_double_eq_tol(exp(1.23454656768), s21_exp(1.23454656768), 1e-6);
  ck_assert_ldouble_eq_tol(exp(S21_PI), s21_exp(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(exp(S21_PI_2), s21_exp(S21_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(exp(S21_PI_3), s21_exp(S21_PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(exp(S21_PI_6), s21_exp(S21_PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(exp(S21_PI_8), s21_exp(S21_PI_8), 1e-6);
  ck_assert_double_infinite(s21_exp(MAX_LONG_DOUBLE));
  ck_assert_float_eq(exp(MAX_LONG_DOUBLE), s21_exp(MAX_LONG_DOUBLE));
  ck_assert_double_nan(s21_exp(S21_NAN));
  ck_assert_ldouble_eq_tol(exp(S21_NEG_INF), s21_exp(S21_NEG_INF), 1e-6);
  ck_assert_ldouble_eq_tol(exp(S21_E), s21_exp(S21_E), 1e-6);
  ck_assert_ldouble_eq(exp(-0), s21_exp(-0));
  ck_assert_double_infinite(s21_exp(S21_POS_INF));
  ck_assert_double_infinite(s21_exp(710));
}
END_TEST

START_TEST(sin_tests) {
  ck_assert_double_eq_tol(sin(-13.54), s21_sin(-13.54), 1e-6);
  ck_assert_double_eq_tol(sin(13.54), s21_sin(13.54), 1e-6);
  ck_assert_double_eq_tol(sin(0.0), s21_sin(0.0), 1e-6);
  ck_assert_double_eq_tol(sin(-0.0), s21_sin(-0.0), 1e-6);
  ck_assert_double_eq_tol(sin(+0.0), s21_sin(+0.0), 1e-6);
  ck_assert_double_eq_tol(sin(1.0), s21_sin(1.0), 1e-6);
  ck_assert_double_eq_tol(sin(2.5), s21_sin(2.5), 1e-6);
  ck_assert_double_eq_tol(sin(6.28), s21_sin(6.28), 1e-6);
  ck_assert_double_eq_tol(sin(2.2343), s21_sin(2.2343), 1e-6);
  ck_assert_double_eq_tol(sin(0.1234), s21_sin(0.1234), 1e-6);
  ck_assert_double_eq_tol(sin(S21_PI), s21_sin(S21_PI), 1e-6);
  ck_assert_double_eq_tol(sin(S21_PI_2), s21_sin(S21_PI_2), 1e-6);
  ck_assert_double_eq_tol(sin(S21_PI_3), s21_sin(S21_PI_3), 1e-6);
  ck_assert_double_eq_tol(sin(S21_PI_4), s21_sin(S21_PI_4), 1e-6);
  ck_assert_double_eq_tol(sin(-3 * S21_PI_4), s21_sin(-3 * S21_PI_4), 1e-6);
  ck_assert_double_eq_tol(sin(S21_PI_6), s21_sin(S21_PI_6), 1e-6);
  ck_assert_double_eq_tol(sin(S21_PI_8), s21_sin(S21_PI_8), 1e-6);
  ck_assert_double_nan(s21_sin(S21_NAN));
  ck_assert_double_nan(s21_sin(S21_NEG_INF));
  ck_assert_double_infinite(s21_sin(S21_POS_INF));
}
END_TEST

START_TEST(cos_tests) {
  ck_assert_double_eq_tol(cos(-13.54), s21_cos(-13.54), 1e-6);
  ck_assert_double_eq_tol(cos(13.54), s21_cos(13.54), 1e-6);
  ck_assert_double_eq_tol(cos(0.0), s21_cos(0.0), 1e-6);
  ck_assert_double_eq_tol(cos(+0.0), s21_cos(+0.0), 1e-6);
  ck_assert_double_eq_tol(cos(-0.0), s21_cos(-0.0), 1e-6);
  ck_assert_double_eq_tol(cos(1.0), s21_cos(1.0), 1e-6);
  ck_assert_double_eq_tol(cos(2.5), s21_cos(2.5), 1e-6);
  ck_assert_double_eq_tol(cos(6.28), s21_cos(6.28), 1e-6);
  ck_assert_double_eq_tol(cos(2.2343), s21_cos(2.2343), 1e-6);
  ck_assert_double_eq_tol(cos(0.1234), s21_cos(0.1234), 1e-6);
  ck_assert_ldouble_eq_tol(cos(S21_PI), s21_cos(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(
      cos(S21_PI_2), s21_cos(S21_PI_2),
      1e-6);  // @todo сравнение работает до 6 знаков после замятой. При
              // точности long double - будет расхождение
  ck_assert_ldouble_eq_tol(cos(S21_PI_3), s21_cos(S21_PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(cos(-3 * S21_PI_4), s21_cos(-3 * S21_PI_4), 1e-6);
  ck_assert_ldouble_eq_tol(cos(S21_PI_4), s21_cos(S21_PI_4), 1e-6);
  ck_assert_ldouble_eq_tol(cos(S21_PI_6), s21_cos(S21_PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(cos(S21_PI_8), s21_cos(S21_PI_8), 1e-6);
  ck_assert_double_nan(s21_cos(S21_NAN));
  ck_assert_double_infinite(s21_cos(S21_NEG_INF));
  ck_assert_double_nan(s21_cos(S21_POS_INF));
}
END_TEST

START_TEST(tan_tests) {
  ck_assert_double_eq_tol(tan(-13.54), s21_tan(-13.54), 1e-6);
  ck_assert_double_eq_tol(tan(13.54), s21_tan(13.54), 1e-6);
  ck_assert_double_eq_tol(tan(-0.0), s21_tan(-0.0), 1e-6);
  ck_assert_double_eq_tol(tan(0.0), s21_tan(0.0), 1e-6);
  ck_assert_double_eq_tol(tan(+0.0), s21_tan(+0.0), 1e-6);
  ck_assert_double_eq_tol(tan(1.0), s21_tan(1.0), 1e-6);
  ck_assert_double_eq_tol(tan(2.5), s21_tan(2.5), 1e-6);
  ck_assert_double_eq_tol(tan(6.28), s21_tan(6.28), 1e-6);
  ck_assert_double_eq_tol(tan(2.2343), s21_tan(2.2343), 1e-6);
  ck_assert_double_eq_tol(tan(0.1234), s21_tan(0.1234), 1e-6);
  ck_assert_ldouble_eq_tol(tan(1 * S21_PI_4), s21_tan(1 * S21_PI_4), 1e-6);
  ck_assert_ldouble_eq_tol(tan(3 * S21_PI_4), s21_tan(3 * S21_PI_4), 1e-6);
  ck_assert_ldouble_eq_tol(tan(5 * S21_PI_4), s21_tan(5 * S21_PI_4), 1e-6);
  ck_assert_ldouble_eq_tol(tan(7 * S21_PI_4), s21_tan(7 * S21_PI_4), 1e-6);
  ck_assert_double_eq_tol(tan(S21_PI), s21_tan(S21_PI), 1e-06);
  ck_assert_ldouble_eq_tol(tan(S21_PI_3), s21_tan(S21_PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(tan(S21_PI_6), s21_tan(S21_PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(tan(S21_PI_8), s21_tan(S21_PI_8), 1e-6);
  ck_assert_double_nan(s21_tan(S21_NAN));
  ck_assert_double_nan(tan(S21_POS_INF));
  ck_assert_double_nan(s21_tan(S21_NEG_INF));
}
END_TEST

START_TEST(sqrt_tests) {
  ck_assert_double_eq_tol(sqrt(0.0), s21_sqrt(0.0), 1e-6);
  ck_assert_double_eq_tol(sqrt(-0.0), s21_sqrt(-0.0), 1e-6);
  ck_assert_double_eq_tol(sqrt(1.0), s21_sqrt(1.0), 1e-6);
  ck_assert_double_eq_tol(sqrt(2), s21_sqrt(2), 1e-6);
  ck_assert_double_eq_tol(sqrt(3.14), s21_sqrt(3.14), 1e-6);
  ck_assert_double_eq_tol(sqrt(6.28), s21_sqrt(6.28), 1e-6);
  ck_assert_double_eq_tol(sqrt(2.2343), s21_sqrt(2.2343), 1e-6);
  ck_assert_double_eq_tol(sqrt(S21_PI), s21_sqrt(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(sqrt(S21_PI_2), s21_sqrt(S21_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(sqrt(S21_PI_3), s21_sqrt(S21_PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(sqrt(S21_PI_6), s21_sqrt(S21_PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(sqrt(S21_PI_8), s21_sqrt(S21_PI_8), 1e-6);
  ck_assert_double_nan(s21_sqrt(-1));
  ck_assert_double_nan(s21_sqrt(S21_NEG_INF));
  ck_assert_double_infinite(s21_sqrt(S21_POS_INF));
  ck_assert_double_nan(s21_sqrt(S21_NAN));
}

START_TEST(log_tests) {
  ck_assert_double_eq_tol(log(13.54), s21_log(13.54), 1e-6);
  ck_assert_float_eq(log(0.0), s21_log(0.0));
  ck_assert_double_eq_tol(log(1.0), s21_log(1.0), 1e-6);
  ck_assert_double_eq_tol(log(3.14), s21_log(3.14), 1e-6);
  ck_assert_double_eq_tol(log(6.28), s21_log(6.28), 1e-6);
  ck_assert_double_eq_tol(log(2.2343), s21_log(2.2343), 1e-6);
  ck_assert_double_eq_tol(log(0.1234), s21_log(0.1234), 1e-6);
  ck_assert_ldouble_eq_tol(log(S21_PI), s21_log(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(log(S21_PI_2), s21_log(S21_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(log(S21_PI_3), s21_log(S21_PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(log(S21_PI_6), s21_log(S21_PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(log(S21_PI_8), s21_log(S21_PI_8), 1e-6);
  ck_assert_double_nan(s21_log(S21_NAN));
  ck_assert_ldouble_eq_tol(log(1), s21_log(1), 1e-6);
  ck_assert_double_nan(s21_log(-1));
  ck_assert_double_infinite(s21_log(S21_POS_INF));
  ck_assert_double_infinite(s21_log(0));
}
END_TEST

START_TEST(asin_tests) {
  ck_assert_double_eq_tol(asin(S21_EPS10), s21_asin(S21_EPS10), 1e-6);
  ck_assert_double_eq_tol(asin(0.1234), s21_asin(0.1234), 1e-6);
  ck_assert_double_eq_tol(asin(0.0), s21_asin(0.0), 1e-6);
  ck_assert_double_nan(s21_asin(1.1));
  ck_assert_double_eq_tol(asin(1), s21_asin(1), 1e-6);
  ck_assert_double_eq_tol(asin(-1), s21_asin(-1), 1e-6);
  ck_assert_double_eq_tol(asin(0.5), s21_asin(0.5), 1e-6);
  ck_assert_double_eq_tol(asin(-0.5), s21_asin(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(asin(S21_PI_6), s21_asin(S21_PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(asin(S21_PI_8), s21_asin(S21_PI_8), 1e-6);
  ck_assert_double_nan(s21_asin(S21_NAN));
  ck_assert_double_nan(s21_asin(-13.54));
  ck_assert_double_nan(s21_asin(S21_PI));
  ck_assert_double_nan(asin(S21_PI_2));
  ck_assert_double_nan(asin(S21_PI_3));
  ck_assert_double_nan(asin(S21_NEG_INF));
  ck_assert_double_nan(asin(S21_POS_INF));
}
END_TEST

START_TEST(acos_tests) {
  ck_assert_double_eq_tol(acos(S21_EPS10), s21_acos(S21_EPS10), 1e-6);
  ck_assert_double_eq_tol(acos(0.1234), s21_acos(0.1234), 1e-6);
  ck_assert_double_eq_tol(acos(0), s21_acos(0), 1e-6);
  ck_assert_double_eq_tol(acos(1), s21_acos(1), 1e-6);
  ck_assert_double_eq_tol(acos(-1), s21_acos(-1), 1e-6);
  ck_assert_double_eq_tol(acos(0.5), s21_acos(0.5), 1e-6);
  ck_assert_double_eq_tol(acos(-0.5), s21_acos(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(acos(S21_PI_4), s21_acos(S21_PI_4), 1e-6);
  ck_assert_ldouble_eq_tol(acos(S21_PI_6), s21_acos(S21_PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(acos(S21_PI_8), s21_acos(S21_PI_8), 1e-6);
  ck_assert_double_nan(s21_acos(13.54));
  ck_assert_double_nan(s21_acos(S21_NAN));
  ck_assert_double_nan(s21_acos(S21_PI));
  ck_assert_double_nan(s21_acos(S21_PI_2));
  ck_assert_double_nan(s21_acos(S21_NEG_INF));
  ck_assert_double_nan(s21_acos(S21_POS_INF));
}
END_TEST

START_TEST(atan_tests) {
  ck_assert_double_eq_tol(atan(-13.54), s21_atan(-13.54), 1e-6);
  ck_assert_double_eq_tol(atan(13.54), s21_atan(13.54), 1e-6);
  ck_assert_double_eq_tol(atan(3.14), s21_atan(3.14), 1e-6);
  ck_assert_double_eq_tol(atan(6.28), s21_atan(6.28), 1e-6);
  ck_assert_double_eq_tol(atan(2.234), s21_atan(2.234), 1e-6);
  ck_assert_double_eq_tol(atan(0.1234), s21_atan(0.1234), 1e-6);
  ck_assert_double_eq_tol(atan(0.0), s21_atan(0.0), 1e-6);
  ck_assert_double_eq_tol(atan(1), s21_atan(1), 1e-6);
  ck_assert_double_eq_tol(atan(-1), s21_atan(-1), 1e-6);
  ck_assert_double_eq_tol(atan(3.5), s21_atan(3.5), 1e-6);
  ck_assert_double_eq_tol(atan(0.5), s21_atan(0.5), 1e-6);
  ck_assert_double_eq_tol(atan(-3.5), s21_atan(-3.5), 1e-6);
  ck_assert_ldouble_eq_tol(atan(S21_PI), s21_atan(S21_PI), 1e-6);
  // ck_assert_ldouble_eq_tol(atan(S21_PI_2), s21_atan(S21_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(atan(S21_PI_8), s21_atan(S21_PI_8), 1e-6);
  ck_assert_double_nan(s21_atan(S21_NAN));
  ck_assert_double_infinite(s21_atan(S21_NEG_INF));
  ck_assert_double_infinite(s21_atan(S21_POS_INF));
}
END_TEST

Suite *s21_math_tests_create() {
  Suite *s21_math = suite_create("s21_math");
  TCase *s21_math_tests = tcase_create("S21_MATH");
  tcase_add_test(s21_math_tests, ceil_tests);
  tcase_add_test(s21_math_tests, floor_tests);
  tcase_add_test(s21_math_tests, exp_tests);
  tcase_add_test(s21_math_tests, sin_tests);
  tcase_add_test(s21_math_tests, cos_tests);
  tcase_add_test(s21_math_tests, tan_tests);
  tcase_add_test(s21_math_tests, abs_tests);
  tcase_add_test(s21_math_tests, fabs_tests);
  tcase_add_test(s21_math_tests, fmod_tests);
  tcase_add_test(s21_math_tests, pow_tests);
  tcase_add_test(s21_math_tests, sqrt_tests);
  tcase_add_test(s21_math_tests, log_tests);
  tcase_add_test(s21_math_tests, asin_tests);
  tcase_add_test(s21_math_tests, acos_tests);
  tcase_add_test(s21_math_tests, atan_tests);
  suite_add_tcase(s21_math, s21_math_tests);
  return s21_math;
}

int main() {
  Suite *s21_math = s21_math_tests_create();
  SRunner *s21_math_runner = srunner_create(s21_math);
  float number_failed;
  srunner_run_all(s21_math_runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(s21_math_runner);
  srunner_free(s21_math_runner);

  return number_failed == 0 ? 0 : 1;
}