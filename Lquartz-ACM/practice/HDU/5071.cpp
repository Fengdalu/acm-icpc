#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int,int>PII;
#define MP make_pair
#define PB push_back
#define SZ size()
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define BG begin()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define SQ(x) ((x)*(x))

#define LEN 20111
//int debug = 1;

map<int, int> pos, mpos;//pos[u] --> pmin~pmax //mpos[pmin~pmax] --> u
int pmin, pmax;
map<int, LL> words; //words[u] --> cnt w
map<int, LL> :: iterator IL_IJ;
map<int, int> :: iterator II_IT;
int top;

//void my_debug() {
//    printf("\twords: ");
//    for(IL_IJ = words.BG; IL_IJ != words.ED; ++IL_IJ) {
//        printf("\t(%d, %I64d) ", (*IL_IJ).AA, (*IL_IJ).BB);
//    }
//    printf("\t\n");
//    printf("\tpos  : ");
//    for(II_IT = pos.BG; II_IT != pos.ED; ++II_IT) {
//        printf("\t(%d, %d) ", (*II_IT).AA, (*II_IT).BB);
//    }
//    printf("\t\n");
//    printf("\tmpos : ");
//    for(II_IT = mpos.BG; II_IT != mpos.ED; ++II_IT) {
//        printf("\t(%d, %d) ", (*II_IT).AA, (*II_IT).BB);
//    }
//    printf("\t\n");
//    printf("\ttop = %d\n", top);
//}

inline int LB(int x) {return x & (-x);}
struct BIT {
    int _[LEN];
    int n;
    void init(int m) {
        n = m + 5;
        memset(_, 0, sizeof(_));
    }
    int query(int w) {
        int ret = 0;
        for(w += 3; w > 0; w -= LB(w)) ret += _[w];
        return ret;
    }
    void update(int w, int d){
        for(w += 3; w <= n; w += LB(w)) _[w] += d;
    }
    int find_kth(int k) {
        int idx = 0;
        for(int i = 20; i >= 0; i--) {
            idx |= 1<<i;
            if(idx <= n && _[idx] < k) k -= _[idx];
            else idx ^= 1<<i;
        }
        return idx + 1 - 3;
    }
}bit;

void ready() {
    int i;
    bit.init(LEN - 10);
    mpos.clear();
    pos.clear();
    words.clear();
    top = 0;
    pmax = pmin = 10001;
}
int havePrior(int u) {//true have, false have no
    return words.find(u) != words.ED;
}
void movePos(int u, int p) {
    int org = pos[u];
    mpos.erase(org);
    mpos[p] = u;
    pos[u] = p;
//    printf("Move u=%d p=%d org=%d\n", u, p , org);
    bit.update(org, -1);
    bit.update(p, 1);
}
void Add(int u) {
    if(havePrior(u)) {
        printf("same priority");
    }
    else {
        pmax++;
        pos[u] = pmax;
        words[u] = 0;
        mpos[pmax] = u;
        bit.update(pmax, 1);
        printf("success");
    }
}
void Close(int u) {
    if(!havePrior(u)) {
        printf("invalid priority");
    }
    else {
        printf("close %d with %I64d", u, words[u]);
        bit.update(pos[u], -1);
        words.erase(u);
        mpos.erase(pos[u]);
        pos.erase(u);
        if(top == u) top = 0;
    }
}
void Chat(LL w) {
    if(words.empty()) {
        printf("empty");
    }
    else {
        if(top == 0) {
            II_IT = mpos.BG;
            IL_IJ = words.find((*II_IT).BB);
        }
        else {
            IL_IJ = words.find(top);
        }
        (*IL_IJ).BB += w;
        printf("success");
    }
}
void Rotate(int x) {
    int sz = words.size();
    if(x < 1 || x > sz) {
        printf("out of range");
    }
    else {
        int k = bit.find_kth(x);
//        int k;
//        int l = pmin - 1, r = pmax + 1, mid, y;
//        while(l + 1 < r) {
//            mid = (l + r) >> 1;
//            y = bit.query(mid);
//            if(y >= x) {
//                r = mid;
//            }
//            else if(y < x) {
//                l = mid + 1;
//            }
//        }
//        if(bit.query(l) == x) k = l;
//        else if(bit.query(r) == x) k = r;
        int u = mpos[k];
        pmin--;
//        printf("Rotate x=%d k=%d u=%d p=%d\n", x, k, u, pmin);
        movePos(u, pmin);
        printf("success");
    }
}
void Prior() {
    if(words.empty()) {
        printf("empty");
    }
    else {
        IL_IJ = --words.end();
        --pmin;
        movePos((*IL_IJ).AA, pmin);
        printf("success");
    }
}
void Choose(int u) {
    if(havePrior(u)) {
        --pmin;
        movePos(u, pmin);
        printf("success");
    }
    else {
        printf("invalid priority");
    }
}
void Top(int u) {
    if(havePrior(u)) {
        top = u;
        printf("success");
    }
    else {
        printf("invalid priority");
    }
}
void Untop() {
    if(top == 0) {
        printf("no such person");
    }
    else {
        top = 0;
        printf("success");
    }
}
void Bye() {
    //top mpos
    int u, k;
    if(top != 0) {
        u = top;
        if(words[u] > 0) 
        {
            printf("Bye %d: %I64d\n", u, words[u]);
        }
        words.erase(u);
        mpos.erase(pos[u]);
        pos.erase(u);
        top = 0;
    }
    for(II_IT = mpos.BG; II_IT != mpos.ED; ++II_IT) {
        IL_IJ = words.find((*II_IT).BB);
        if((*IL_IJ).BB > 0) printf("Bye %d: %I64d\n", (*IL_IJ).AA, (*IL_IJ).BB);
    }
}
int main() {
//    freopen("in.txt","r",stdin);
//    freopen("wa.txt", "w", stdout);
    int i,j,k,u,v,w, x;
    int n, te;
    char opt[100];
    scanf("%d", &te);
    for(int ca = 1; ca <= te; ca++) {
        scanf("%d", &n);
        ready();
        for(i = 1; i <= n; i++) {
            scanf("%s", opt);
            printf("Operation #%d: ", i);
            if(opt[0] == 'A') {
                scanf("%d", &u);
                Add(u);
            }
            else if(opt[0] == 'C' && opt[1] == 'l') {
                scanf("%d", &u);
                Close(u);
            }
            else if(opt[0] == 'C' && opt[1] == 'h' && opt[2] == 'a') {
                scanf("%d", &w);
                Chat(w);
            }
            else if(opt[0] == 'R') {
                scanf("%d", &x);
                Rotate(x);
            }
            else if(opt[0] == 'P') {
                Prior();
            }
            else if(opt[0] == 'C' && opt[1] == 'h' && opt[2] == 'o') {
                scanf("%d", &u);
                Choose(u);
            }
            else if(opt[0] == 'T') {
                scanf("%d", &u);
                Top(u);
            }
            else if(opt[0] == 'U') {
                Untop();
            }
            printf(".\n");
//            if(debug) my_debug();
        }
        Bye();
    }
    return 0;
}
/*
3
18
Prior
Add 1
Chat 1000000000
Add 2
Chat 2000000000

Top 2
Chat 3
Untop
Chat 4
Choose 2

Chat 5
Rotate 2
Chat 4
Close 2
Add 3

Prior
Chat 2000000000
Close 1



21
Add 4
Add 2
Add 3
Chat 1
Top 3

Prior
Chat 2
Choose 1
Choose 2
Untop

Chat 4
Top 2
Top 4
Close 4
Chat 8
Close 3

Close 2
Add 4
Add 1
Add 4

Chat 16


1
13
Close 1
Add 2
Close 2
Prior
Chat 3
Top 2
Add 2
Untop
Add 1
Rotate 1
Chat 3
Rotate 2
Chat 4
*/
