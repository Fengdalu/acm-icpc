#include <bits/stdc++.h>

int n;

int qry1(int x1, int y1, int x2, int y2, int mk) {
    if(mk)
        printf("? %d %d %d %d\n", x1, y1, x2, y2);
    else
        printf("? %d %d %d %d\n", y1, x1, y2, x2);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    return x;
}

void solve1(int &x1, int &x2, int &x3, int &x4, int mk) {
    int l, r;
    l = 1, r = n;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(qry1(1, 1, mid, n, mk) == 2) r = mid;
        else l = mid + 1;
    }
    x4 = l;

    l = 1, r = x4;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(qry1(mid, 1, n, n, mk) == 2) l = mid;
        else r = mid - 1;
    }
    x1 = l;
    if(x1 == x4) {
        x2 = x3 = x1;
        return ;
    }
    l = x1, r = x4;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(qry1(x1, 1, mid, n, mk) == 0) l = mid + 1;
        else r = mid;
    }
    x2 = l;
    l = x2, r = x4;
    if(qry1(x2, 1, x2, n, mk) == 1) l++;
    if(l > x4) {
        x2 = x4;
        x3 = x4;
        return;
    }
    while(l < r) {
        int mid = (l + r + 1) / 2;
        if(qry1(mid, 1, x4, n, mk) == 0) r = mid - 1;
        else l = mid;
    }
    x3 = l;
    if(qry1(x3, 1, x4, n, mk) == 0) {
        l = x1, r = x2;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(qry1(mid, 1, x4, n, mk)) l = mid;
            else r = mid - 1;
        }
        x3 = l;
        if(qry1(x3, 1, x2, n, mk) == 1) {
            int L = x4;
            x4 = x2;
            x2 = L;
        }
    }
}

int main() {
    int x1, x2, x3, x4;
    int y1, y2, y3, y4;
    scanf("%d", &n);
    solve1(x1, x2, x3, x4, 1);
    solve1(y1, y2, y3, y4, 0);
    int a1 = qry1(x1, y1, x2, y2, 1); int a2 = qry1(x3, y3, x4, y4, 1);
    if(a1 == 1 && a2 == 1)
        printf("! %d %d %d %d %d %d %d %d\n", x1, y1, x2, y2, x3, y3, x4, y4);
    else
        printf("! %d %d %d %d %d %d %d %d\n", x1, y3, x2, y4, x3, y1, x4, y2);
    fflush(stdout);
    return 0;
}
