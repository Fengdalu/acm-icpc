#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)

PII s[10000];

int main() {
    int n, S;
    cin >> n >> S;
    for(int i = 0; i < n; i++) cin >> s[i].AA >> s[i].BB;
    sort(s, s + n);
    reverse(s, s + n);
    int t = 0, l = S;
    for(int i = 0; i < n; i++) {
        t += l - s[i].AA;
        l = s[i].AA;
        t = max(s[i].BB, t);
    }
    t += l;
    cout << t << endl;
    return 0;
}
