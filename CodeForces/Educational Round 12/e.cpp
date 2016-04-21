#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct node {
    node* ch[2];
    int s;
    node() { s = 0; ch[0] = ch[1] = 0; }
}*rt;
int k;
unsigned b = 1 << 31;

int Cnt(node *t) {
    if(t == 0) return 0;
    return t->s;
}

int count(node *t, unsigned mask, int num, int k)  {
    if(t == 0 || mask == 0) return 0;
    bool g = bool(num & mask) ^ 1;
    if(bool(k & mask)) return count(t->ch[g], mask >> 1, num, k);
    else return Cnt(t->ch[g]) + count(t->ch[g ^ 1], mask >> 1, num, k);
}

void insert(node* t, unsigned mask, int num) {
    t->s++;
    if(mask == 0) return;
    if(t->ch[bool(mask & num)] == 0) t->ch[bool(mask & num)] = new node();
    insert(t->ch[bool(mask & num)], mask >> 1, num);
}

int main() {
    rt = new node();
    insert(rt, b, 0);
    int n, k;
    scanf("%d%d", &n, &k);
    k--;
    long long tot = 0;
    int cur = 0;
    for(int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        cur ^= x;
        tot += (long long)count(rt, b, cur, k);
        insert(rt, b, cur);
    }
    cout << tot << endl;
}
