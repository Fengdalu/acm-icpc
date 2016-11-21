#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

string a, b, buf;


int main() {
  ios::sync_with_stdio(false);	
  int T; cin >> T;
  for(int ii = 0; ii < T; ii++) {
    cout << "Case #" << ii + 1 << ": ";
    cin >> buf >> a >> b;
    if(a == b) cout << "Once again!";
    else if(a == "scissors" && b == "paper") cout << "I made it!~";
    else if(a == "rock" && b == "scissors") cout << "I made it!~";
    else if(a == "paper" && b == "rock") cout << "I made it!~";
    else cout << "No no no!";
    cout << endl;	
  }
  return 0;
}
