#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1000
#define M (N * N * 2)
#define INF 0x3f3f3f

// ISAP O(m*n^2)
const int Maxn = 1000;
const int Maxm = Maxn * Maxn;
struct node {
    int u, v, c, next;
}e[Maxm];
int tot, last[Maxn];
void adde(int u, int v, int c, int c1) {
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].c = c1; e[tot].next = last[v]; last[v] = tot++;
}

int dist[Maxn], cur[Maxn], gap[Maxn], pre[Maxn];
int ISAP(int s, int t, int n) {
    int i, j, u, v, det;
    int maxflow = 0;
    memset(dist, 0, sizeof(dist[0]) * (n + 3));
    memset(gap, 0, sizeof(gap[0]) * (n + 3));
    for (i = 0; i < n; i ++ )
        cur[i] = last[i];
    u = s;
    gap[0] = n;
    pre[s] = -1;
    while (dist[s] <= n) {
        bool flag = false;
        for (j = cur[u]; j != -1; j = e[j].next) {
            v = e[j].v;
            if (e[j].c > 0 && dist[u] == dist[v] + 1) {
                flag = true;
                pre[v] = u;
                cur[u] = j;
                u = v;
                break;
            }
        }
        if (flag) {
            if (u == t) {
                int det = INF;
                for (i = u; i != s; i = pre[i])
                    det = min(det, e[cur[pre[i]]].c);
                for (i = u; i != s; i = pre[i]) {
                    e[cur[pre[i]]].c -= det;
                    e[cur[pre[i]] ^ 1].c += det;
                }
                maxflow += det;
                u = s;
            }
        }
        else {
            int mind = n;
            for (j = last[u]; j != -1; j = e[j].next ) {
                v = e[j].v;
                if (e[j].c > 0 && dist[v] < mind) {
                    mind = dist[v];
                    cur[u] = j;
                }
            }
            if (( -- gap[dist[u]]) == 0) break;
            gap[dist[u] = mind + 1] ++ ;
            if (u != s) u = pre[u];
        }
    }
    return maxflow;
}


int n;
int a[200], b[200];
int H[400];
int cnt1;

int check(int k)
{
    tot = 0;
    memset(last, -1, sizeof last);
    int ST = 0, ED = cnt1 + 1 + n + 2;
    for(int i = 0; i < cnt1 - 1; i++)
    {
        adde(ST, i + 1, H[i + 1] - H[i], 0);
    }
    for(int i = 0; i < n; i++)
    {
        int L = lower_bound(H, H + cnt1, a[i]) - H;
        int R = lower_bound(H, H + cnt1, b[i]) - H;
        for(int j = L; j < R; j++)
        {
            adde(j + 1, i + cnt1, INF, 0);
        }
    }
    for(int i = 0; i < n; i++)
    {
        adde(i + cnt1, ED, k, 0);
    }
    return ISAP(ST, ED, ED + 1) == (k * n);
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    int L = 0, R = INF;
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for(int i = 0; i < n; i++) R = min(R, b[i] - a[i]);
    cnt1 = 0;
    for(int i = 0; i < n; i++) H[cnt1++] = a[i];
    for(int i = 0; i < n; i++) H[cnt1++] = b[i];
    sort(H, H + cnt1);
    cnt1 = unique(H, H + cnt1) - H;

    while(L < R)
    {
        int mid = (L + R + 1) / 2;
        if(check(mid)) L = mid;
        else R = mid - 1;
    }
    cout << n * L << endl;
    return 0;
}
