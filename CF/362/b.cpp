#include <bits/stdc++.h>

int main() {
  std::string s;
  std::cin >> s;
  int split = s.find('e');
  int b = atoi(s.substr(split + 1).c_str());
  s = s.substr(0, split);
  int p = s.find('.');
  if(p == s.npos) {
    while(b--) s.push_back('0');
  }
  else {
    while(p + 1 != s.size() && b) {
      std::swap(s[p], s[p + 1]);
      p++; b--;
    }
    if(p == s.size() - 1) s = s.substr(0, s.size() - 1);
    if(b) {
      while(b--) s.push_back('0');
    }
  }
  bool flag = false;
  for(int i = 0; i < s.size(); i++)
    if(s[i] != '0') {
      int J = s.size() - 1;
      if(s.find('.') != s.npos) {
        while(s[J] == '0') J--;
      }
      s = s.substr(i, J - i + 1);
      flag = true;
      break;
    }
  if(!flag) s = "0";
  if(s[0] == '.') s = "0" + s;
  if(s[s.size() - 1] == '.') s = s.substr(0, s.size() - 1);
  printf("%s\n", s.c_str());
  return 0;
}
