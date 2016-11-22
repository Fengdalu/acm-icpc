#include <algorithm>
#include <iostream>
#include <cstdio>

#define PII std::pair<int, int>
#define AA first
#define BB second
#define MP std::make_pair

using std::pair;
using std::string;

const int N = 500;
char buf[N];
pair<pair<int, int>, string> a[N];
pair<int, string> b[N];

int main() {
  int n;
  while(~scanf("%d", &n)) {
    for(int i = 0; i < n; i++) {
      scanf("%s%d", buf, &a[i].AA.AA);
      a[i].AA.AA *= -1;
      a[i].AA.BB = i;
      a[i].BB = string(buf);
    }
    for(int i = 0; i < n; i++) {
      scanf("%s%d", buf, &b[i].AA);
      b[i].BB = string(buf);
    }
    bool flag, flag1 = false;
    flag = false;
    for(int i = 0; i < n - 1; i++) {
      if(b[i].AA < b[i + 1].AA) { flag = true;  }
    }
    if(flag) { puts("Error"); flag1 = true; }
    std::sort(a, a + n);
    for(int i = 0; i < n; i++) a[i].AA.AA *= -1;
    if(!flag) {
      flag = false;
      for(int i = 0; i < n; i++)
      if(a[i].AA.AA != b[i].AA || a[i].BB != b[i].BB) {
        flag = true;
      }
      if(flag) { puts("Not Stable"); flag1 = true; }
      else puts("Right");
    }
    if(flag1) {
      for(int i = 0; i < n; i++) printf("%s %d\n", a[i].BB.c_str(), a[i].AA.AA);
    }
  }
  return 0;
}
