#include <algorithm>
#include <iostream>
#include <cstdio>

#define PII std::pair<int, int>
#define AA first
#define BB second
#define MP std::make_pair

const int N = 1e6;
int a[N];
int main() {
  int n;
  while(~scanf("%d", &n)) {
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    int mid = n / 2;
    std::nth_element(a, a + mid, a + n);
    printf("%d\n", a[mid]);
  }
  return 0;
}
