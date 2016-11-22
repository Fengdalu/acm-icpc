#include <bits/stdc++.h>
using namespace std;

char s[2000];
int main() {
    scanf("%s", s);
    int n = strlen(s);
    string q = "AHIMOTUVWXYovwx";
    for(int i = 0; i <= n / 2; i++) {
        char a = s[i], b = s[n - i - 1];
        if(q.find(a) != q.npos && q.find(b) != q.npos && a == b) continue;
        if(a == 'b' && b == 'd') continue;
        if(b == 'b' && a == 'd') continue;
        if(a == 'p' && b == 'q') continue;
        if(b == 'p' && a == 'q') continue;
        cout << "NIE"; return 0;
    }
    cout << "TAK" << endl;
}
