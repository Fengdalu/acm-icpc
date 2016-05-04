#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;
const double pi = acos(-1);

int main() {
    double d, h, v, e;
    cin >> d >> h >> v >> e;
    double p = pi * (d / 2.0) * (d / 2.0) * e;
    if(p >= v) cout << "NO";
    else {
        cout << "YES" << endl;
        cout << setprecision(16) <<  h * pi * (d / 2) * (d / 2) / (v - p) << endl;
    }
    return 0;
}
