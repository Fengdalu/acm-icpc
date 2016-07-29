#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
long long ss[maxn], m[maxn], w[maxn];
int to[maxn];
bool in[maxn];
bool vis[maxn];
ll q[maxn];
ll f[maxn];
ll mm[maxn];
ll pre[maxn];
int cnt;
ll K;

int main() {
    int n;
    scanf("%d%lld", &n, &K);
    for(int i = 0; i < n; i++) scanf("%d", &to[i]);
    for(int i = 0; i < n; i++) scanf("%lld", &w[i]);
    for(int i = 0; i < n; i++) in[to[i]] = true;

    for(int i = 0; i < n; i++) if(!in[i]) {
        cout << "bf " << i << endl;
        if(to[i] == i) {
            ss[i] = K * w[i];
            mm[i] = w[i];
            continue;
        }
        int k = i;
        while(!vis[k]) {
            vis[k] = true;
            k = to[k];
        }
        int rt = k;
        k = rt;
        cnt = 0;
        do {
            q[cnt++] = w[k];
            k = to[k];
            vis[k] = false;
        } while(k != rt);
        int t = i;
        int tot = K;
        multiset<long long>s;
        ll sum = 0;
        while(tot--) {
            t = to[t];
            s.insert(w[t]);
            sum += w[t];
            if(t == rt && tot >= cnt) {
                for(int i = 0; i < cnt; i++) s.insert(w[q[i]]);
                ll p = 0;
                for(int i = 0; i < cnt; i++) p += w[q[i]];
                sum += p * tot / cnt;
                for(int i = 0; i < tot % cnt; i++) sum += w[q[i]];
                t = q[tot % cnt];
                break;
            }
        }
        cout << "pt: " << i << endl;
        cout << sum << " " << t << endl;
        k = i;
        while(!vis[k]) {
            cout << "node : " << k << endl;
            vis[k] = true;
            ss[k] = sum;
            mm[k] = *s.begin();
            sum -= w[k];
            s.erase(s.find(w[k]));
            sum += w[t];
            s.insert(w[t]);
            t = to[t];
            k = to[k];
        }
        k = i;
    }
    for(int i = 0; i < n; i++) printf("%lld %lld\n", ss[i], mm[i]);
}
