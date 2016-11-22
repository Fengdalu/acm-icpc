#include <bits/stdc++.h>

#define PII std::pair<int, int>
#define AA first
#define BB second
#define MP std::make_pair

const int N = 1e6;
int f[N];
char s[N];

int main() {
  while(~scanf("%s", s)) {
    std::string line(s);
    int cnt = 0;
    for(int i = 0; i < line.size(); i++)
      if(line[i] == '5') line[i] = ' ';
    std::istringstream in(line);
    int x;
    while(in >> x) {
      f[cnt++] = x;
    }
    std::sort(f, f + cnt);
    for(int i = 0; i < cnt; i++) {
      if(i == 0) printf("%d", f[i]);
      else printf(" %d", f[i]);
    }
    puts("");
  }
  return 0;
}

