#include <iostream>
#include <cstdio>
#include <algorithm>
#include <algorithm>
#include <map>
using namespace std;

map<string, double> f;
void init() {
    f["A"] =  4.0;
    f["A-"] = 3.7;
    f["B+"] = 3.3;
    f["B"] = 3.0;
    f["B-"] = 2.7;
    f["C+"] = 2.3;
    f["C"] = 2.0;
    f["C-"] = 1.7;
    f["D"] = 1.3;
    f["D-"] = 1.0;
    f["F"] = 0.0;
}

char buf[10];
int main() {
    int n;
    init();
    while(~scanf("%d", &n)) {
        int x;
        double a = 0, b = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d%s", &x, buf);
            string t = string(buf);
            if(f.find(t) != f.end()) {
                a += x;
                b += f[t] * (double)x;
            }
        }
        if(a != 0)
        printf("%.2f\n", b / a);
        else puts("0.00");
    }
    return 0;
}
