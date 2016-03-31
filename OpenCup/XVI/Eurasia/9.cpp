#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;

unsigned get(unsigned x){
    unsigned a, b, c, d;

    x = x - (x << 16);
    a = x ^ (x >> 11);
    b = x ^ (a >> 11);
    x = (a & (((1 << 22) - 1) << 10)) | (b & ((1 << 10) - 1));

    c = 0;
    for(int i = 0; 3 * i < 32; i++) {
        a = x - (c << 3);
        c = c | (a & (((1 << 3) - 1) << (3 * i)));
    }
    x = c;


    c = 0;
    for(int i = 0; 6 * i <= 32; i++) {
        a = x ^ (c >> 6);
        unsigned mask = (((1 << 6) - 1) << (26 - 6 * i));
        if(26 - 6 * i < 0) mask = 3;
        c = c | (a & (mask));
    }
    x = c;
    a = x - (x << 10);
    b = x - (a << 10);
    c = x - (b << 10);
    x = (a & ((1 << 20) - 1)) | (b & (((1 << 10) - 1) << 20)) | (c & (3 << 30));
    return x;
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int q;
    scanf("%d", &q);
    while(q--) {
        unsigned x;
        scanf("%u", &x);
        printf("%u\n", get(x));
    }
}
