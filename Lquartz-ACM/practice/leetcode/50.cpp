#include <bits/stdc++.h>
using namespace std;

//------------------------Start Solution

class Solution {
    double getPow(double x, int n) {
        if(n == 0) return 1.0;
        if(n == 1) return x;
        double y = 1.0;
        while(n) {
            if(n & 1) y *= x;
            n /= 2;
            x *= x;
        };
        return y;
    }
public:
    double myPow(double x, int n) {
        if(n < 0) {
            return getPow(1./x, -n);
        }
        else {
            return getPow(x, n);
        }
        
    }
};

//-------------------------End Solution

int main() {
    Solution s;
    return 0;
}
