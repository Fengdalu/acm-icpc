#include <stdio.h>

int a[100010];
int main() {
  int n; 
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", a + i);
  scanf("%d", a + n);
  int J = 0;
  int i;
  while(a[J] <= a[n] && J <= n) J++;
  int p = a[n];
  for(i = n; i >= J; i--) a[i] = a[i - 1];
  a[J] = p;
  for(i = 0; i < n + 1; i++) 
    printf("%d ", a[i]);
  puts("");
  return 0;
}
