#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define LL long long
#define OP begin()
#define ED end()
#define PB(x) push_back(x)
#define SZ size()

const int Maxn = 3000100;

int Hash[Maxn];
PII ans[4000100];
PII S[4000100];
PII s[Maxn];
PII Q[3000100];
int cnt3;
int n, k;

void add(int l, int r) {
    if(!cnt3) {
        ans[cnt3++] = PII(l, r);
    }
    else {
        if(ans[cnt3 - 1].BB == l) ans[cnt3 - 1].BB = r;
        else ans[cnt3++] = PII(l, r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int cnt1 = 0;
    int cnt4 = 0;
    for(int i = 0; i < n; i++) cin >> Q[i].AA >> Q[i].BB;
    for(int i = 0; i < n; i++) s[cnt4++] = PII(Q[i].AA, -1);
    for(int i = 0; i < n; i++) s[cnt4++] = PII(Q[i].BB, 1);
    for(int i = 0; i < n; i++) Hash[cnt1++] = Q[i].AA;
    for(int i = 0; i < n; i++) Hash[cnt1++] = Q[i].BB;
    sort(s, s + cnt4);
    sort(Hash, Hash + cnt1);
    cnt1 = unique(Hash, Hash + cnt1) - Hash;
    int cnt2 = 0;
    for(int i = 0; i < cnt1 - 1; i++) {
        S[cnt2++] = MP(Hash[i], Hash[i]);
        S[cnt2++] = MP(Hash[i], Hash[i + 1]);
    }
    S[cnt2++] = MP(Hash[cnt1 - 1], Hash[cnt1 - 1]);
    int j = 0;
    int c = 0;
    cnt3 = 0;
    for(int i = 0; i < cnt2; i++) {
        if(S[i].AA != S[i].BB)while(j < cnt4) {
            PII x = s[j];
            x.AA = x.AA;
            if(x.BB > 0 && x.AA <= S[i].AA) {
                c--;
                j++;
            }
            else break;
        }
        while(j < cnt4) {
            PII x = s[j];
            x.AA = x.AA;
            if(x.BB < 0 && x.AA <= S[i].AA) {
                c++;
                j++;
            }
            else break;
        }
        if(c >= k) {
            add(S[i].AA, S[i].BB);
        }
    }
    printf("%d\n", cnt3);
    for(int i = 0; i < cnt3; i++) printf("%d %d\n", ans[i].AA, ans[i].BB);
    //cout << ans[i].AA << " " << ans[i].BB << endl;
    return 0;
}


