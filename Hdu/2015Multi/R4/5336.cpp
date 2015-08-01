#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <cassert>
using namespace std;
#define N 200
#define INF 0x3f3f3f
#define MP(x, y) make_pair(x, y)
#define X first
#define Y second
#define AA first
#define BB second
#define cmin(x, y) x = min(x, y)
#define PII pair<int, int>

const PII VEC[4] = { PII(1, 0), PII(-1, 0), PII(0, 1), PII(0, -1) };
int r, c, n, T;
int f[N][N];
int time[N];
int id[N][N];
int X[N], Y[N];


vector< pair<PII, int> > s, s1;
vector< pair<PII, int> >::iterator iter, tmp;
set<PII>q;
set<PII>::iterator iter1;

int main()
{
    //freopen("1010.in", "r", stdin);
    //freopen("1010.txt", "w", stdout);
    while(~scanf("%d%d%d%d", &r, &c, &n, &T)){
        memset(f, 0, sizeof f);
        memset(time, 0, sizeof time);

        for(int i = 0; i < n; i++) {
            int x, y; scanf("%d%d", &x, &y);
            scanf("%d", &f[x][y]);
            id[x][y] = i;
            X[i] = x; Y[i] = y;
        }
        int xx, yy; scanf("%d%d", &xx, &yy);
        s.clear();
        q.clear();
        s1.clear();
        for(int i = 0; i < 4; i++) s.push_back(MP(PII(xx, yy), i));
        for(int t = 0; t < T; t++) {

            for(int i = 0; i < s.size(); i++){
                PII v = VEC[s[i].BB];
                s[i].AA.X += v.X;
                s[i].AA.Y += v.Y;
            }

            for(iter = s.begin(); iter != s.end(); iter++)
            if(1 <= iter->AA.X && iter->AA.X <= r && 1 <= iter->AA.Y && iter->AA.Y <= c) {
                s1.push_back(MP(PII(iter->AA.X, iter->AA.Y), iter->BB));
            }
            swap(s, s1);
            s1.clear();

            /*
            for(int i = 0; i < s.size(); i++){
                cout << "SHUIDI: " << s[i].AA.X << " " << s[i].AA.Y << " " << s[i].BB << endl;
            }
            */
            q.clear();
            for(iter = s.begin(); iter != s.end(); iter++) if(f[iter->AA.X][iter->AA.Y] > 0){
                f[iter->AA.X][iter->AA.Y] += 1;
            }
            else s1.push_back(MP(PII(iter->AA.X, iter->AA.Y), iter->BB));


            for(iter = s.begin(); iter != s.end(); iter++) if(f[iter->AA.X][iter->AA.Y] > 0){
                if(f[iter->AA.X][iter->AA.Y] > 4) {
                    q.insert(MP(iter->AA.X, iter->AA.Y));
                }
            }

            //cout << "INSERT" << endl;
            swap(s, s1);
            s1.clear();

            for(iter1 = q.begin(); iter1 != q.end(); iter1++){
                time[id[iter1->X][iter1->Y]] = t;
                f[iter1->X][iter1->Y] = 0;
                for(int i = 0; i < 4; i++){
                    s.push_back(MP(MP(iter1->X, iter1->Y), i));
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(f[X[i]][Y[i]] > 0) printf("1 %d\n", f[X[i]][Y[i]]);
            else printf("0 %d\n", time[i] + 1);
        }
        //break;
    }
    return 0;
}
