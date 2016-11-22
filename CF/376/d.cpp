#include <bits/stdc++.h>

const int N = 5e5+100;
const int M = 1e6+10;
int cover[M<<2];

void add(int rt, int l, int r, int a, int b) {
    if(a <= l && r <= b) {
        cover[rt]++;
        return ;
    }
    int mid = (l + r) >> 1;
    if(b <= mid) add(rt << 1, l, mid, a, b);
    else if(a > mid) add(rt << 1 ^ 1, mid + 1, r, a, b);
    else {
        add(rt << 1, l, mid, a, b);
        add(rt << 1 ^ 1, mid + 1, r, a, b);
    }
}

int cal(int rt, int l, int r, int p) {
    if(l == r) return cover[rt];
    int mid = (l + r) >> 1;
    if(p <= mid) return cover[rt] + cal(rt << 1, l, mid, p);
    return cover[rt] + cal(rt << 1 ^ 1, mid + 1, r, p);
}

std::vector<int> Q[N];
int main() {
    int n, c;
    scanf("%d%d", &n, &c);
    for(int i = 0; i < n; i++) {
        int L; scanf("%d", &L);
        for(int j = 0; j < L; j++) {
            int p; scanf("%d", &p);
            Q[i].push_back(p);
        }
    }
    for(int i = 0; i < n - 1; i++) {
        int up = std::min(Q[i].size(), Q[i + 1].size());
        bool flag = false;
        for(int j = 0; j < up && !flag; j++) {
            if(Q[i][j] == Q[i + 1][j]) continue;
            else {
                flag = true;
                int a = Q[i][j];
                int b = Q[i + 1][j];
                if(a < b) {
                    add(1, 0, c - 1, 0, c - b);
                    if(c + 1 - a <= c - 1) {
                        add(1, 0, c - 1, c + 1 - a, c - 1);
                    }
                    flag = true;
                }
                else {
                    add(1, 0, c - 1, c - a + 1, c - b);
                    flag = true;
                }
            }
        }
        if(!flag && Q[i].size() > Q[i + 1].size()) {
            puts("-1");
            return 0;
        }
        else if(!flag) add(1, 0, c - 1, 0, c - 1);
    }
    for(int i = 0; i < c; i++) {
        if(cal(1, 0, c - 1, i) == n - 1) {
            printf("%d\n", i);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
