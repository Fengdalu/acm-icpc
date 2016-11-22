#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;


inline int lowbit(int x)
{
    return x & (-x);
}

vector<int>ans;
int main()
{
    ios::sync_with_stdio(false);
    int n, sum; cin >> sum >> n;
    ans.clear();
    for(int i = n; i >= 1; i--)
    {
        if(lowbit(i) <= sum) { ans.push_back(i); sum -= lowbit(i); }
    }
    if(!sum)
    {
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
    }
    else cout << -1 << endl;
    return 0;
}
