#include <bits/stdc++.h>

typedef long long ll;
struct node {
    int sum;
    int ed;
    int l, r;
} f[10000000];
int cnt = 0;

typedef long long ll;
char op[100];
char buf[100];
bool vis[100];

int insert(int &rt, ll num, int pos, int lim) {
    if(rt == -1) {
        rt = cnt;
        f[rt].sum = 0;
        f[rt].l = f[rt].r = -1;
        f[rt].sum = f[rt].ed = 0;
        cnt++;
    }
    if(pos == lim) {
        f[rt].ed++;
        return 0;
    }
    int r;
    if(num % 10ll % 2ll) r = insert(f[rt].r, num / 10ll, pos + 1, lim);
    else r = insert(f[rt].l, num / 10ll, pos + 1, lim);
    if(!r) f[rt].sum ++;
    r |= (num % 10ll % 2ll);
    return r;
}

int del(int &rt, ll num, int pos, int lim) {
    //std::cout << num << " ";
    if(pos == lim)  {
    //if(num == 0) {
        f[rt].ed--;
        return 0;
    }
    int r;
    if(num % 10ll % 2ll) r = del(f[rt].r, num / 10ll, pos + 1, lim);
    else r = del(f[rt].l, num / 10ll, pos + 1, lim);
    if(!r) f[rt].sum --;
    r |= (num % 10ll % 2ll);
    return r;
}

int cal(int &rt, int pos, int lim) {
    if(rt == -1) {
        rt = cnt;
        f[rt].sum = 0;
        f[rt].l = f[rt].r = -1;
        f[rt].sum = f[rt].ed = 0;
        cnt++;
    }
    if(pos == lim) return f[rt].ed;
    int add = 0;
    if(true)
        add = f[rt].ed;
    //std::cout << add << std::endl;
    if(op[pos] == '1') return add + cal(f[rt].r, pos + 1, lim);
    else return cal(f[rt].l, pos + 1, lim) + add;
}

int main() {
    int t;
    scanf("%d", &t);
    int rt = -1;
    ll ss;
    while(t--) {
        //std::cout << "TX "<< f[rt].sum << " " << f[rt].ed << std::endl;
        scanf("%s", buf);
        if(buf[0] == '+') {
            scanf("%I64d", &ss);
            insert(rt, ss, 0, 19);
        }
        else if(buf[0] == '-') {
            scanf("%I64d", &ss);
            del(rt, ss, 0, 19);
        }
        else {
            scanf("%s", op);
            int len = strlen(op);
            std::reverse(op, op + len);
            //vis[len - 1] = op[len - 1] == '1';
            //for(int i = len - 2; i >= 0; i--) vis[i] = vis[i + 1] | (op[i] == '1');
            while(len <= 19) op[len++] = '0';
            //for(int i = 0; i < len; i++) std::cout << vis[i]; std::cout << std::endl;
            printf("%d\n", cal(rt, 0, len));
        }
    }
    return 0;
}
