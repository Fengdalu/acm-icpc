#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int main() {	
  ios::sync_with_stdio(false);
  int T; cin >> T; for(int ii = 0; ii < T; ii++) {
    cin >> n;
    for(int i = 0; i < n; i++) cout << " ";
    cout << "^" << endl;
    for(int i = 1; i < n; i++) {
      for(int j = 0; j < n - i; j++) cout << " ";
      cout << "*";
      for(int j = 0; j < 2 * i - 1; j++) cout << " ";
      cout << "*" << endl;			
    }
    cout << "<";
    for(int j = 0; j < 2 * n - 1; j++) cout << " ";
    cout << ">" << endl;
    for(int i = n - 1; i >= 1; i--) {
      for(int j = 0; j < n - i; j++) cout << " ";
      cout << "*";
      for(int j = 0; j < 2 * i - 1; j++) cout << " ";
      cout << "*" << endl;			
    }
    for(int i = 0; i < n; i++) cout << " ";
    cout << "v" << endl;
  }
  return 0;
}
