#include <bits/stdc++.h>

using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second
#define MP make_pair

const int N = 2e6+1000;
char a[N];
int f[N], Next[N];
int getNext(char b[N], int m) {
  int j, k;
  j = 0;
  k = -1;
  Next[0] = -1;
  for(int i = 0; i < m; i++) {
    while(k != -1 && b[k + 1] != b[i]) k = Next[k];
    if(b[k + 1] == b[i] && k + 1 != i) k++;
    Next[i] = k;
  }
  return Next[m - 1];
}

int main() {
//  freopen("a.in", "r", stdin);
  int n, m;
  scanf("%d%d", &n, &m);
  scanf("%s", a);
  int cnt = n;
  int k = getNext(a, cnt);
  bool flag = true;
  while(m--) {
    int op; scanf("%d", &op);
    if(op == 2) { if(flag) f[cnt - 1]++; flag = false;}
    else if(op == 1) {
      char buf[5]; scanf("%s", buf);
      a[cnt++] = buf[0];
      while(k != -1 && a[k + 1] != a[cnt - 1]) k = Next[k];
      if(a[k + 1] == a[cnt - 1] && k + 1 != cnt - 1) k++;
      Next[cnt - 1] = k;
      f[cnt - 1] = f[k];
      flag = true;
    }
    else {
        if(m == 0) printf("%d", f[cnt - 1]);
        else printf("%d\n", f[cnt - 1]);
    }
  }
  return 0;
}
