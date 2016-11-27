#include <bits/stdc++.h>

const int N = 1e6;
struct obj {
  int l, r;
  char op;
} objs[N<<1];
char s[N];

int main() {
  freopen("a.in", "r", stdin);
  while(gets(s)) {
    int len = strlen(s);
    int j = 0;
    for(int i = 0; i < len; i++){
      if(s[i] != ' ') s[j++] = s[i];
    }
    len = j;
  }
  return 0;
}
