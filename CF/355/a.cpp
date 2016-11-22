#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    int n, h, tot = 0;
    scanf("%d%d", &n, &h);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if(x > h) tot++;
    }
    cout << n + tot << endl;
}
