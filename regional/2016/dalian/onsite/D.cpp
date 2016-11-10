#include <bits/stdc++.h>

int gcd(int a, int b) { if(b == 0) return a; return gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int sqr(int x) { return x * x; }
int main() {
  int a, b; 
  while(~scanf("%d%d", &a, &b)) {
    if((a / 2) * (a - a / 2) < b) {puts("No Solution"); continue;}
    int s = gcd(a, b);
    a /= s; b /= s;

    int d = (a * a - 4 * b);
    if(sqr(sqrt(d)) == d) {
      if(a > int(sqrt(d)) && (a - int(sqrt(d))) % 2 == 0) {
        int x = (a - int(sqrt(d)) ) / 2;
        printf("%d %d\n", x * s, (a - x) * s);
      }
      else if((a + int(sqrt(d))) % 2 == 0) {
        int x = (a + int(sqrt(d)) ) / 2;
        printf("%d %d\n", x * s, (a - x) * s);
      }
      else puts("No Solution");
    }
    else puts("No Solution");
  }
  return 0;
}
