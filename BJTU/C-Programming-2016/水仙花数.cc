#include <stdio.h>


int main() {
  int a[4] = {153, 370, 371, 407};
  int n; scanf("%d", &n);
  int i;
  for(i = 0; i < 4; i++) if(a[i] <= n) {
    if(i == 0) printf("%d", a[i]);
    else printf(" %d", a[i]);
  }
  puts("");
  return 0;
}
