#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define LL long long

char s[1000010];
bool vis[1000010];
deque<char> Q;
int n;

int op(char s) {
    return (s == '{') || (s == '(') || (s == '[') || (s == '<');
}

char mt(char s) {
    if(s == ')') return '(';
    if(s == ']') return '[';
    if(s == '>') return '<';
    if(s == '}') return '{';
}

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(s[i] == '{' || s[i] == '(' || s[i] == '[' || s[i] == '<') Q.push_back(s[i]);
        else {
            if(Q.size() && op(Q.back())) {
                if(mt(s[i]) != Q.back()) ans++;
                Q.pop_back();
            }
            else {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    if(Q.size()) cout << "Impossible" << endl;
    else cout << ans << endl;
    return 0;
}
