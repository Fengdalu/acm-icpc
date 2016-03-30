#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

unsigned long long mask(string s) {
    unsigned long long tot = 0;
    for(int i = 0; i < s.size(); i++)
        tot += tot * 27LL + (s[i] - 'a' + 1LL);
    return tot;
}

char s[1000000];
char x[1000000], y[1000000];
int tree[300000];
int id[300000];
map<unsigned long long, int>dic;
int n;


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for(int i = 0; i < (1 << n); i++) {
        scanf("%s", s);
        dic[mask(string(s))] = i;
    }
    scanf("%s", s);
    queue<int>q;
    for(int i = 0; i < (1 << n); i++) q.push(i);
    int cnt = 0;
    for(int i = 0; i < (1 << n) - 1; i++) {
        int x = q.front();
        q.pop();
        int y = q.front();
        q.pop();
        tree[cnt++] = x;
        tree[cnt++] = y;
        if(s[i] == 'W') {
            q.push(x);
        }
        else q.push(y);
    }
    tree[cnt++] = q.front();
    reverse(tree, tree + cnt);
    memset(id, -1, sizeof id);
    for(int i = 0; i < cnt; i++)
    if(id[tree[i]] == -1) {
        id[tree[i]] = i + 1;
    }
    int Q;
    scanf("%d", &Q);
    while(Q--) {
        scanf("%s%s", x, y);
        int a = id[dic[mask(string(x))]], b = id[dic[mask(string(y))]];
        int flag = 0;
        if(a < b) {
            swap(a, b);
            flag = 1;
        }
        //cout << a << " " << b << endl;
        while(a > b) a /= 2;
        if(a == b)  {
            if(flag) puts("Win");
            else puts("Lose");
        }
        else puts("Unknown");
    }
    return 0;
}
