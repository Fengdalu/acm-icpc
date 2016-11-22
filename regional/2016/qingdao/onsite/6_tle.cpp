#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>

using std::string;
using std::set;
using std::istringstream;
using std::swap;

const int N = 4e5;
char buf[1000];
string s;
struct state {
  int L, R;
  set<string> mk;
  int a, b;
  int op;
  int fa;
  state(int L, int R, set<string> mk = set<string>(), int op = 0) : L(L), R(R), op(op), mk(mk) {
    a = -1; b = -1; op = 0; fa = -1;
  }
  state() { a = -1; b = -1; op = 0; fa = -1; }
} stk[N];
std::set<std::string> ans[N];

void cal(int len) {
  int tot = 0;
  stk[tot++] = state(0, len - 1);

  for(int i = 0; i < tot; i++) {
    ans[i].erase(ans[i].begin(), ans[i].end());
    if(tot >= N) exit(-12);
    state &cur = stk[i];
    int id = i;
    int &L = cur.L, &R = cur.R;
    std::set<std::string> &mk = cur.mk; int &op = cur.op;
    while(true) {
      bool modify = false;
      while(s[L] == ' ') L++; while (s[R] == ' ') R--;
      if(s[L] == '(' && s[R] == ')') {
        int cv = 0, flag = true;
        for(int i = L; i < R; i++) {
          if(s[i] == '(') cv++; else if(s[i] == ')') cv--;
          if(cv == 0) flag = false;
        }
        if(flag) {L++; R--; modify = true;}
      }
      if(!modify) break;
    }
    // printf("cal: %s %d %d\n", s.substr(L, R - L + 1).c_str(), L, R);

    if(L + 6 <= R && s.substr(L, 6) == "lambda" && (s[L + 6] == '(' || s[L + 6] == ' ')) {
      L += 6;
      while(s[L] != '(') L++;
      int J = L;
      while(s[J] != ')') J++;
      stk[tot] = state(J + 1, R, mk);
      stk[tot].mk.insert(s.substr(L + 1, J - L - 1));
      // printf("MK: %s\n", s.substr(L + 1, J - L - 1).c_str());
      stk[tot].fa = id;
      stk[tot].op = 1;
      tot++;
      continue;
    }
    bool flag = true;
    for(int i = L; i <= R; i++) if(s[i] == '(' || s[i] == ')') flag = false;
    if(flag) {
      istringstream in(s.substr(L, R - L + 1));
      string word;
      int tmp = 0;
      while(in >> word) if(mk.find(word) == mk.end()) {
        ans[id].insert(word);
      }
      continue;
    }
    int cv = 0;
    int pre = L;
    for(int i = L; i <= R; i++) {
      if(s[i] == '(') cv++; else if(s[i] == ')') cv--;
      if(cv == 0 && (s[i] == ' ' || i == R)) {
        stk[tot] = state(pre, i, cur.mk); stk[tot].op = 2; stk[tot].fa = id; tot++;
        pre = i + 1;
      }
    }
  }

  for(int i = tot - 1; i >= 0; i--) {
    state &cur = stk[i];
    if(cur.op == 1) ans[cur.fa] = ans[i];
    if(cur.op == 2) {
        ans[cur.fa].insert(ans[i].begin(), ans[i].end());
        if(ans[cur.fa].size() > ans[i].size()) {
            ans[cur.fa].insert(ans[i].begin(), ans[i].end());
        }
        else {
          ans[i].insert(ans[cur.fa].begin(), ans[cur.fa].end());
          std::swap(ans[i], ans[cur.fa]);
        }
    }
  }
}


int main() {
  // freopen("a.in", "r", stdin); //freopen("a.txt", "w", stdout);
  int T; scanf("%d", &T); gets(buf);
  for(int cas = 1; cas <= T; cas++) {
    gets(buf);
    s = string(buf);
    cal(s.size());
    printf("Case #%d:", cas);
    for(auto &word : ans[0]) {
      printf(" %s", word.c_str());
    }
    puts("");
  }
  return 0;
}

/*
7
x
y
(lambda (x) (x y))
(lambda (y) (x y))
( (lambda (x) x) (x y) )
( lambda (y) ( lambda (z) (x (y z)) ) )
(lambda (x) (((lambda (x) ((lambda (x) (((lambda (x) ((lambda (x) (((lambda (x) (x ( lambda (y) ( lambda (z) (x (y z)) ) ))) b o) y)) ( lambda (y) ( lambda (z) (x (y z)) ) ))) b c) y)) ( lambda (y) ( lambda (z) (x (y z)) ) ))) b c) y))
*/
