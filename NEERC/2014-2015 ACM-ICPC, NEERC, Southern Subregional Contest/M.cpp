#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <queue>
#include <map>
#include <vector>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define SZ size()
#define PB(x) push_back(x)
#define OP begin()
#define ED end()

int n;
typedef map< char, PII > obj;
map< char, deque<PII> >f;
deque< obj >q;
obj::iterator it;
char buf[100000];

int main() {
    scanf("%d", &n);
    gets(buf);

    map<char, PII>p;
    for(int i = 1; i <= n; i++) {
        gets(buf + 1);
        int Len = strlen(buf + 1);
        for(int j = 1; j <= Len; j++) if(buf[j] != ' '){
            if(buf[j] == '{') {
                q.PB(p);
                p = obj();
            }
            else if(buf[j] == '}') {
                for(it = p.OP; it != p.ED; it++) f[it->AA].pop_back();
                p = q.back();
                q.pop_back();
            }
            else if('a' <= buf[j] && buf[j] <= 'z') {
                if(!f[buf[j]].empty()) {
                    PII it = f[buf[j]].back();
                    printf("%d:%d: warning: shadowed declaration of %c, the shadowed position is %d:%d\n", i, j, buf[j], it.AA, it.BB);
                }
                f[buf[j]].PB(PII(i, j));
                p[buf[j]] = PII(i, j);
            }
        }
    }
    return 0;
}
