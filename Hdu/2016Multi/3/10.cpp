#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    double a, v1, v2;
    while(~scanf("%lf%lf%lf", &a, &v1, &v2)) {
        if(a == 0) puts("0.0\n");
        else if(v1 <= v2) puts("Infinity");
        else printf("%.12f\n", a * v1 / (v1 + v2) / (v1 - v2));
    }
    return 0;
}

