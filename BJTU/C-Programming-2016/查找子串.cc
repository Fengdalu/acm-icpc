#include <stdio.h>
#include <string.h>

#define N 1000000

char a[N], b[N];
int main() {
  scanf("%s%s", a, b);

  int i, j;

  int l1 = strlen(a), l2 = strlen(b);
  for(i = 0; i <= l1 - l2; i++) {
    int flag = 1;
    for(j = i; j < i + l2 && flag; j++)
      if(a[j] != b[j - i]) flag = 0;
    if(flag) {
      printf("%d\n", i);
      return 0;
    }
  }
  puts("-1");
  return 0;
}
