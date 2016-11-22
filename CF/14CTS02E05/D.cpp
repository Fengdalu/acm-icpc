#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long

LL a, b, c;
LL f1, f2;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> a >> b >> c;
    f1 = f2 = 1;
    LL cnt = 0;
    do{
        cnt++;
        f1 = (a * f1 + f1 % b) % c;
        f2 = (a * f2 + f2 % b) % c;
        f2 = (a * f2 + f2 % b) % c;
        if(cnt > 20000000) { cout << -1 << endl; return 0;}
    }while(f1 != f2);
    f1 = 1;
    cnt = 0;
    while(f1 != f2) {
        cnt++;
        f1 = (a * f1 + f1 % b) % c;
        f2 = (a * f2 + f2 % b) % c;
    }
    do{
        cnt++;
        f1 = (a * f1 + f1 % b) % c;
    }while(f1 != f2);
    cout << cnt << endl;
    return 0;
}
