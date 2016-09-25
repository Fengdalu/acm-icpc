#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	if(A > C) swap(A, C), swap(B, D);
	if(E > G) swap(E, G), swap(F, H);
	int a = max(A, E);
	int b = max(B, F);
	int c = min(C, G);
	int d = min(D, H);
	int ret;
	if(c <= a || d <= b) ret = 0;
	else ret = (c - a) * (d - b);
	return (C - A) * (D - B) + (G - E) * (H - F) - ret;
    }
};

int main() {
    Solution s;
    cout << s.computeArea(0, 0, 0, 0, -1, -1, 1, 1) << endl;
    return 0;
}
