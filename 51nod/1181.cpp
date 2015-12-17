#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool prime[1000100];
vector<int>nums;
vector<int>ans;

void gen() {
    memset(prime, 0, sizeof prime);
    for(int i = 2; i < 1000100; i++) {
        if(!prime[i]) nums.push_back(i);
        for(int j = 0; j < nums.size() && nums[j] * i < 1000100; j++) {
            prime[i * nums[j]] = true;
            if(i % nums[j] == 0) break;
        }
    }
    for(int i = 0; i < nums.size(); i++) if(!prime[i + 1]){
        ans.push_back(nums[i]);
    }
}

int main() {
    gen();
    int n; scanf("%d", &n);
    int p = upper_bound(ans.begin(), ans.end(), n) - ans.begin();
    if(!prime[n]) printf("%d\n", n);
    else printf("%d\n", ans[p]);
}
