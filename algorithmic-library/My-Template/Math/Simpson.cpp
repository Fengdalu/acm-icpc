/*
 * 自适应 Simpson
 * 验题 :hdu4978
 * Kyb 待验证
 */
#include <cmath>
const double eps = 1e-6;
double f(double x) { return x; }

long double simpson(long double a, long double b) {
  long double c = a + (b - a) / 2;
  return (f(a) + 4 * f(c) + f(b)) * (b - a) / 6;
}
long double asr(long double a, long double b, long double eps, long double A) {
  long double c = a + (b - a) / 2;
  long double L = simpson(a, c), R = simpson(c, b);
  if (std::fabs(L + R - A) < 15 * eps) return L + R + (L + R - A) / 15.;
  return asr(a, c, eps / 2, L) + asr(c, b, eps / 2, R);
}
long double asr(long double a, long double b, long double eps) {
  return asr(a, b, eps, simpson(a, b));
}
