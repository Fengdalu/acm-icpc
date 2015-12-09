#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char f['Z' + 10];
char buf[1000];
string s;
int n;

int main() {
    freopen("arrange.in", "r", stdin);
    freopen("arrange.out", "w", stdout);
    cin >> n;
    gets(buf);
    for(int i = 0; i < n; i++) {
        gets(buf);
        f[buf[0]] = 1;
    }
    int ans = 0;
    int tot = 0;
    for(char c = 'A'; c <= 'Z'; c++) {
        if(!f[c]) { cout << (int)(c - 'A') << endl; return 0; }
    }
    cout << 26 << endl;
    return 0;
}
