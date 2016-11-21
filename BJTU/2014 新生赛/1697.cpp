#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int x, g, h, k;
int buf[100];
int n;

int main() {
  ios::sync_with_stdio(false);
  int T; cin >> T;
  for(int ii = 0; ii < T; ii++) {
    cin >> x >> g >> h >> k >> n;
    for(int i = 0; i < n; i++) cin >> buf[i];
    int c1 = 0, c2 = 0, c3 = 0;
    for(int i = 0; i < n; i++) {
      if(buf[i] <= x + g) c1++;
      if(buf[i] <= x + h) c2++;
      if(buf[i] <= x + k) c3++;			
    }
    cout << c1 << " " << c2 << " " << c3 << endl;
  }
  return 0;
}
