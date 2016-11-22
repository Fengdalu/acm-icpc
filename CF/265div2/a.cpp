#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int add = 1;
    int tot = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '0')  break;
        else tot++;
    }
    if(tot == s.size()) tot--;
    cout << tot + 1 << endl;
}
