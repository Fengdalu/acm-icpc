#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <unordered_map>
#include <queue>
#include <map>
#include <cassert>
using namespace std;
#define SZ size()
#define ull unsigned long long
struct CUBE {
    struct MTX {
        char a[2][2];
        MTX(char _a=0, char _b=0, char _c=0, char _d=0) {
            a[0][0] = _a;
            a[0][1] = _b;
            a[1][0] = _c;
            a[1][1] = _d;
        }
        void R() {
            char p = a[0][0];
            a[0][0] = a[1][0];
            a[1][0] = a[1][1];
            a[1][1] = a[0][1];
            a[0][1] = p;
        }
        void RR() {
            char p = a[0][0];
            a[0][0] = a[0][1];
            a[0][1] = a[1][1];
            a[1][1] = a[1][0];
            a[1][0] = p;
        }
        void print() {
            for(int i = 0; i < 2; i++)
                for(int j = 0; j < 2; j++) {
                    printf("%c", a[i][j]);
                    if(j == 1) printf("\n");
                }
        }
    } f[6];
    CUBE(char buf[8][10]) {
        f[0] = MTX(buf[0][0], buf[0][1], buf[1][0], buf[1][1]);
        f[1] = MTX(buf[2][0], buf[2][1], buf[3][0], buf[3][1]);
        f[2] = MTX(buf[2][2], buf[2][3], buf[3][2], buf[3][3]);
        f[3] = MTX(buf[2][4], buf[2][5], buf[3][4], buf[3][5]);
        f[4] = MTX(buf[4][0], buf[4][1], buf[5][0], buf[5][1]);
        f[5] = MTX(buf[6][0], buf[6][1], buf[7][0], buf[7][1]);
    }
    ull hash() {
        ull tot = 0;
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 2; j++)
                for(int k = 0; k < 2; k++)
                    tot = tot * 6ll + (ull)(f[i].a[j][k] - '1');
        }
        return tot;
    }
    ull val() {
        CUBE t = *this;
        ull v = hash();
        for(int i = 0; i < 4; i++) {
            MTX g = f[0];
            f[0] = f[2];
            f[2] = f[4];
            f[4] = f[5];
            f[5] = f[6];
            f[6] = g;
            f[3].R();
            f[1].RR();
            v = min(v, t.hash());
        }
        return v;
    }
    void X() {
        f[0].R();
        queue<char>q;
        for(int i = 1; i < 4; i++) {
            q.push(f[i].a[0][0]);
            q.push(f[i].a[0][1]);
        }
        q.push(f[5].a[1][1]);
        q.push(f[5].a[1][0]);
        q.push(q.front());
        q.pop();
        for(int i = 1; i < 4; i++) {
            f[i].a[0][0] = q.front(); q.pop();
            f[i].a[0][1] = q.front(); q.pop();
        }
        f[5].a[1][1] = q.front(); q.pop();
        f[5].a[1][0] = q.front(); q.pop();
        assert(q.size() == 0);
    }
    void Y() {
        static int _index[] = {0, 2, 4, 5};
        f[3].R();
        queue<int>q;
        for(int i = 0; i < 4; i++) {
            int t = _index[i];
            q.push(f[t].a[0][1]);
            q.push(f[t].a[1][1]);
        }
        q.push(q.front());
        q.pop();
        for(int i = 0; i < 4; i++) {
            int t = _index[i];
            f[t].a[0][1] = q.front(); q.pop();
            f[t].a[1][1] = q.front(); q.pop();
        }
        assert(q.size() == 0);
    }
    void print() {
        cout << "----"<< endl;
        for(int i = 0; i < 2; i++) {
            printf("  ") ;
            for(int j = 0; j < 2; j++) printf("%c", f[0].a[i][j]);
            printf("\n");
        }
        for(int i = 0; i < 2; i++) {
            for(int j = 1; j <= 3; j++)
                for(int k = 0; k < 2; k++)
                    printf("%c", f[j].a[i][k]);
            printf("\n");
        }
        for(int i = 0; i < 2; i++) {
            printf("  ") ;
            for(int j = 0; j < 2; j++) printf("%c", f[4].a[i][j]);
            printf("\n");
        }
        for(int i = 0; i < 2; i++) {
            printf("  ") ;
            for(int j = 0; j < 2; j++) printf("%c", f[5].a[i][j]);
            printf("\n");
        }

        cout << "-----"<<endl;
    }
};

char buf[8][10];
char target[8][10];
int main() {
    while(~scanf("%s", buf[0])) {
        for(int i = 1; i < 8; i++) scanf("%s", buf[i]);
        for(int i = 0; i < 8; i++) scanf("%s", target[i]);
        cout << "RDED" << endl;
        unordered_map<ull, bool>vis;
        queue<CUBE>q;
        q.push(CUBE(buf));
        vis[q.front().val()] = 1;
        int cnt = 1e5;
        auto g = CUBE(target).val();
        //q.front().print();
        while(q.SZ && !vis[g] && cnt--) {
            CUBE p = q.front(); q.pop();
            CUBE a = p, b = p;
            a.X(); b.Y();
            auto t1 = a.val(), t2 = b.val();
            if(!vis[t1]) q.push(a);
            if(!vis[t2]) q.push(b);
            vis[t1] = vis[t2] = 1;
        }
        if(vis[g])  puts("yes");
        else puts("no");
    }
    return 0;
}

