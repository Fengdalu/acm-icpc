#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int x[10], y[10];
int px[100], py[100];
int main() {
    int n;
    int cnt = 1;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) {
            x[cnt] = i;
            y[cnt] = j;
            cnt++;
        }
    x[0] = 3, y[0] = 1;
    string s;
    cin >> n;
    cin >> s;
    for(int i = 0; i < n - 1; i++) {
        int a = s[i] - '0', b = s[i + 1] - '0';
        px[i] = x[b] - x[a];
        py[i] = y[b] - y[a];
    }
    bool flag = true;
    for(int i = 0; i < 10; i++) if(i != s[0] - '0') {
        int sx = x[i], sy = y[i];
        bool ff = true;
        for(int j = 0; j < n - 1; j++) {
            sx = sx + px[j];
            sy = sy + py[j];
            if(0 <= sx && sx < 3 && 0 <= sy && sy < 3) continue;
            else if(sx == 3 && sy == 1) continue;
            else { ff = false; break; }
        }
        if(ff) flag = false;
    }
    if(flag) cout << "YES";
    else cout << "NO";
    return 0;
}
