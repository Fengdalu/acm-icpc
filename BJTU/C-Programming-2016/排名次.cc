#include <stdio.h>

#define N 1010
int a[N], b[N];
int p[N];

int main() {
  int n; scanf("%d", &n);

  int i, j;
  for(i = 0; i < n; i++) scanf("%d", a + i);
  for(i = 0; i < n; i++) p[i] = i;

  for(i = 0; i < n; i++)
    for(j = 0; j + 1 < n; j++) {
      if(a[p[j]] < a[p[j + 1]]) {
        p[j] ^= p[j + 1];
        p[j + 1] ^= p[j];
        p[j] ^= p[j + 1];
      }
    }

  j = 0;
  for(i = 0; i < n; i++) b[p[i]] = j++;
  for(int i = 0; i < n - 1; i++)
    if(a[p[i + 1]] == a[p[i]]) b[p[i + 1]] = b[p[i]];
  for(i = 0; i < n; i++)
    printf("%d %d\n", a[i], b[i] + 1);
  return 0;
}
