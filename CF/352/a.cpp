#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char buf[1000];
string t(int x) {
    sprintf(buf, "%d", x);
    return string(buf);
}
int main() {
    string s("");
    for(int i = 1; i <= 1000; i++)  s += t(i);
    int n; cin >> n;
    cout << s[n - 1] << endl;
}
