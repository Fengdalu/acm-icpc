#include <bits/stdc++.h>

int convert(int *day, int y, int m, int d) {
  return y * 365 + d + std::accumulate(day, day + m, 0);
}


int main() {
  freopen("king.in", "r", stdin);
  freopen("king.out", "w", stdout);
  int a[] = {1, 3, 5, 7, 8, 10, 12};
  int b[] = {4, 6, 9, 11};
  int day[13];
  day[0] = 0;
  for(int i = 0; i < sizeof(a) / sizeof(int); i++) day[a[i]] = 31;
  for(int i = 0; i < sizeof(b) / sizeof(int); i++) day[b[i]] = 30;
  day[2] = 28;
  int y, d, m;
  scanf("%d%d%d", &d, &m, &y);
  int ed = convert(day, y, m, d);
  int n; scanf("%d", &n);
  bool flag = false;
  int id, ans;
  for(int i = 0; i < n; i++) {
    scanf("%d%d%d", &d, &m, &y);
    int op = convert(day, y, m, d);
    int birth = (ed - op) / (365);
    if(birth < 18) continue;
    if(!flag || op > ans) {
      id = i;
      ans = op;
      flag = true;
    }
  }
  if(!flag) puts("-1");
  else printf("%d\n", id + 1);
  fclose(stdout);
  return 0;
}

