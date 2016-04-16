#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define ONES(x) __builtin_popcount(x)

map<int, int>::iterator it;
int n;

int main() {
    int T;
    cin >> T;
    for(int ii = 0; ii < T; ii++) {
        cin >> n;
        int mask = 0;
        map<int, int>f;
        for(int i = 0; i < 2 * n - 1; i++) {
            for(int j = 0; j < n; j++) {
            int x;
            cin  >> x;
            f[x]++;

        }
        }
        vector<int>ans;
        for(it = f.begin(); it != f.end(); it++)
        if(it->second % 2 == 1)  ans.push_back(it->first);
        sort(ans.begin(), ans.end());
        cout << "Case #"  << ii + 1 << ": ";
        for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
    }
}
