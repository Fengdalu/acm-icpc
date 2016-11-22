#include <bits/stdc++.h>


int cp(int i, int j) {
    static char buf[10];
    printf("? %d %d\n", i, j);
    fflush(stdout);
    scanf("%s", buf);
    if(buf[0] == '=') return 0;
    if(buf[0] == '<') return -1;
    if(buf[0] == '>') return 1;
}


int main() {
    int T; scanf("%d", &T);
    while(T--) {
        int n; scanf("%d", &n);
        std::vector<int> q(n, 0);
        for(int i = 0; i < n; i++) q[i] = i + 1;
        if(n == 1) {
            printf("! %d %d\n", 1, 1);
            fflush(stdout);
            continue;
        }
        std::deque<int> a, b;
        std::random_shuffle(q.begin(), q.end());
        int pre;
        for(int i = 0; i < n; i += 2) {
            if(i + 1 == n) {
                b.push_back(q[n - 1]);
                a.push_back(q[n - 1]);
                continue;
            }
            int u = q[i], v = q[i + 1];
            int r = cp(u, v);
            if(r <= 0) { a.push_back(u); b.push_back(v); }
            else { b.push_back(u); a.push_back(v); }
        }
        while(a.size() > 1)  {
            int q = a.front(); a.pop_front();
            if(cp(q, a.front()) <= 0) {
                a.pop_front(); a.push_back(q);
            }
        }
        while(b.size() > 1) {
            int q = b.front(); b.pop_front();
            if(cp(q, b.front()) >= 0) {
                b.pop_front(); b.push_back(q);
            }
        }
        std::vector<int> FL;
        while(a.size()) { FL.push_back(a.front()); a.pop_front(); }
        while(b.size()) { FL.push_back(b.front()); b.pop_front(); }
        if(FL.size() == 1) {
            printf("! %d %d\n", FL[0], FL[0]);
            fflush(stdout);
        }
        else {
            /*
            if(cp(FL[0], FL[1]) > 0)
                std::swap(FL[0], FL[1]);
                */
            printf("! %d %d\n", FL[0], FL[1]);
            fflush(stdout);
        }
    }
    return 0;
}


