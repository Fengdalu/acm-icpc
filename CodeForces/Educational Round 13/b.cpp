#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;
int leap(int y) {
    if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) return true;
    return false;
}

int main() {
    int y, tot = 0;
    cin >> y;
    bool g = leap(y);
    do {
        if(leap(y)) tot += 366;
        else tot += 365;
        y++;
    } while(tot % 7 || leap(y) != g);
    cout << y << endl;
}
