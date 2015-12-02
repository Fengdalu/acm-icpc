#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define LL long long
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define PII pair<int, int>

const int Maxn = 10000;
const int Maxm = 100000;
string line[1010];
string pre[1010], text[1010];
int n;
struct node {
    int type;
    int id;
    node(int type, int id): type(type), id(id) {}
    node(){}
}f[Maxm];
int cnt;
int Node(int type, int id) {
    f[cnt] = node(type, id);
    return cnt++;
}

int ind[Maxn];
int t[Maxm], nt[Maxm];

void add(int x, int y) {
    t[cnt] = y;
    nt[cnt] = ind[x];
    ind[x] = cnt++;
}

void build(int rt, int L, int R) {
    int op = L;
    for(int i = L + 1; i <= R; i++) {
        if(pre[i] == "" || (pre[op][0] != '#' && pre[op][0] != '*') || pre[i - 1][0] != pre[i][0] ) {
            if(op == i - 1) {
                int p = Node(3, op);
                text[op] = pre[op] + text[op];
                add(rt, p);
                op = i;
            }
            else if(pre[op] == "") {
                int p = Node(3, op);
                add(rt, p);
                op = i;
            }
            else if(pre[op][0] == '*') {
                int p = Node(1, -1);
                add(rt, p);
                for(int j = op; j < i; j++) pre[j] = pre[j].substr(1);
                build(p, op, i - 1);
                op = i;
            }
            else if(pre[op][0] == '#') {
                int p = Node(2, -1);
                add(rt, p);
                for(int j = op; j < i; j++) pre[j] = pre[j].substr(1);
                build(p, op, i - 1);
                op = i;
            }
        }
    }

    if(op == R) {
        int p = Node(3, op);
        text[op] = pre[op] + text[op];
        add(rt, p);
    }
    else if(pre[op] == "") {
        int p = Node(3, op);
        add(rt, p);
    }
    else if(pre[op][0] == '*') {
        int p = Node(1, -1);
        add(rt, p);
        for(int j = op; j <= R; j++) pre[j] = pre[j].substr(1);
        build(p, op, R);
    }
    else if(pre[op][0] == '#') {
        int p = Node(2, -1);
        add(rt, p);
        for(int j = op; j <= R; j++) pre[j] = pre[j].substr(1);
        build(p, op, R);
    }
}

void disp(int rt) {
    if(f[rt].type == 1) cout << "<ul>" << endl;
    else if(f[rt].type == 2) cout << "<ol>" << endl;

    if(f[rt].type == 3) cout << text[f[rt].id] << endl;
    else
    for(int k = ind[rt]; k != -1; k = nt[k]) {
        if(f[rt].type != -1) cout << "<li>" << endl;
        disp(t[k]);
        if(f[rt].type != -1) cout << "</li>" << endl;
    }
    if(f[rt].type == 1) cout << "</ul>" << endl;
    else if(f[rt].type == 2) cout << "</ol>" << endl;
}

void merge(int rt) {
    string &s = line[f[t[ind[rt]]].id];
    if(f[rt].type == 1) s = '*' + s;
    else s = '#' + s;
    f[rt].type = 3;
    f[rt].id = f[t[ind[rt]]].id;
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    n = 0; cnt = 1;
    memset(ind, -1, sizeof ind);
    while(cin >> line[n]) n++;
    reverse(line, line + n);
    for(int i = 0; i < n; i++)
    {
        string &s = line[i];
        int j;
        for(j = 0; j < s.length(); j++) if(s[j] != '#' && s[j] != '*') {
            break;
        }
        pre[i] = s.substr(0, j);
        text[i] = s.substr(j);
    }
    int rt = Node(-1, -1);
    build(rt, 0, n - 1);
    disp(rt);
//    disp(rt);
    fclose(stdout);
    return 0;
}
