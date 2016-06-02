#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll f[300];
const ll mod = 1e9 + 7;
string s;
int get(char a) {
    for(int i = 0; i < s.size(); i++)
        if(s[i] == a) return i;
    return -1;
}

void init() {
    for(int i = 0; i < 10; i++) s.push_back('0' + i);
    for(int i = 0; i < 26; i++) s.push_back('A' + i);
    for(int i = 0; i < 26; i++) s.push_back('a' + i);
    s.push_back('-');
    s.push_back('_');
    for(int i = 0; i < s.size(); i++)
        for(int j = 0; j < s.size(); j++)
            f[get(s[i]) & get(s[j])]++;
}

char q[100100];
int main() {
    init();
    scanf("%s", q);
    int len = strlen(q);
    ll ans = 1;
    for(int i = 0; i < len; i++)
        ans = (ans * f[get(q[i])]) % mod;
    cout << ans << endl;
}
