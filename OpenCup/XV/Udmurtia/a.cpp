#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
#include <set>
using namespace std;

map<string, int>f, g, p;
int getnum(string x) {
    if(f.find(x) != f.end()) return f[x];
    if(g.find(x) != g.end()) return g[x];
    if(p.find(x) != p.end()) return p[x];
    return -1;
}
int getformat(string x) {
    if(f.find(x) != f.end()) return 0;
    if(g.find(x) != g.end()) return 1;
    if(p.find(x) != p.end()) return 2;
    return -1;
}

bool prime(int x) {
    return (x == 3 || x == 2 || x == 5);
}
const string name[10] = {
    "John",
    "David",
    "Peter",
    "Robert",
    "Mark",
    "Paul",
    "Patrick",
    "Jack",
    "Max",
    "Alex"
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    f["1"] = 1;
    f["2"] = 2;
    f["3"] = 3;
    f["4"] = 4;
    f["5"] = 5;
    f["6"] = 6;
    g["."] = 1;
    g[".."] = 2;
    g["..."] = 3;
    g["...."] = 4;
    g["....."] = 5;
    g["......"] = 6;
    p["I"] = 1;
    p["II"] = 2;
    p["III"] = 3;
    p["IV"] = 4;
    p["V"] = 5;
    p["VI"] = 6;

    bool check[10];
    map<string, int>count;
    set<string>format[3];
    for(int i = 0; i < 10; i++) check[i] = true;
    for(int i = 0; i < 3; i++) {
        string a, b;
        cin >> a >> b;
        if(b[0] != '.') check[0] = false;
        if(p.find(b) != p.end()) check[1] = false;
        if(a != "W") check[2] = false;
        if(a != "W" && a != "B") check[3] = false;
        int x = getnum(b);
        if(x % 2 == 1 && a != "W") check[4] = false;
        if(x % 2 == 0 && a != "B") check[4] = false;
        if(prime(x) && f.find(b) == f.end()) check[5] = false;
        if(!prime(x) && f.find(b) != f.end()) check[5] = false;
        count[a]++;
        if(count.size() > 1) check[6] = false;
        if(count.size() == 1 && (a == "W" || a == "B")) check[6] = false;
        if(p.find(b) != p.end() && a != "Y") check[7] = false;
        format[getformat(b)].insert(a);
    }
    if(count.size() != 3) check[8] = false;
    set<string>q;
    for(int i = 0; i < 3; i++) {
        if(format[i].size() > 1) check[9] = false;
        if(format[i].size() != 0) {
            if(q.find(*format[i].begin()) != q.end()) check[9] = false;
            q.insert(*format[i].begin());
        }
    }

    for(int i = 0; i < 10; i++) if(check[i]){
        printf("%s ", name[i].c_str());
    }
    return 0;
}
