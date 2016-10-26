#include <bits/stdc++.h>

const char* id[] = {"S", "M", "L", "XL", "XXL", "XXXL"};

int get(const char *s) {
    for(int i = 0; i < 6; i++)
        if(!strcmp(id[i], s)) return i;
}

const int N = 2e5;
struct node {
    int L, R;
    int id;
    int operator < (const node &p) const {
        if(L == p.L) return R < p.R;
        return L < p.L;
    }
} a[N];

int c[7];
char buf[20];
int ans[N];
int main() {
    for(int i = 0; i < 6; i++) scanf("%d", c + i);
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", buf);
        std::string s(buf);
        bool flag = false;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == ',') {
                a[i].L = get(s.substr(0, j).c_str());
                a[i].R = get(s.substr(j + 1, s.size() - j).c_str());
                flag = true;
            }
        }
        if(!flag) a[i].L = a[i].R = get(s.c_str());
        a[i].id = i;
    }
    std::fill(ans, ans + n, -1);
    std::sort(a, a + n);
    int J = 0;
    for(int i = 0; i < 6; i++) {
        while(J < n && a[J].L <= i && i <= a[J].R) {
            if(c[i] == 0) break;
            c[i]--;
            ans[a[J].id] = i;
            J++;
        }
    }
    if(*std::min_element(ans, ans + n) == -1) {
        puts("NO");
    }
    else {
        puts("YES");
        for(int i = 0; i < n; i++) printf("%s\n", id[ans[i]]);
    }
    return 0;
}
