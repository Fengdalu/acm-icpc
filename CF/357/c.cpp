#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 1000010;
priority_queue<int>q;
int op[maxn], c[maxn];
string ans[maxn];
char buf[maxn];
char buf1[maxn];
int cnt = 0;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%s", buf);
        if(buf[0] != 'r') scanf("%d", &x);
        if(buf[0] == 'i') q.push(-x);
        if(buf[0] == 'r') {
            if(q.size() == 0) {
                q.push(-1000000000);
                sprintf(buf1, "insert -1000000000\n");
                ans[cnt++] = string(buf1);
            }
            q.pop();
        }
        if(buf[0] == 'g') {
            if(q.size() == 0 || x < -q.top()) {
                q.push(-x);
                sprintf(buf1, "insert %d\n", x);
                ans[cnt++] = string(buf1);
            }
            else if(x > -q.top()) {
                while(q.size() && x > -q.top()) {
                    sprintf(buf1, "removeMin\n");
                    ans[cnt++] = string(buf1);
                    q.pop();
                }
                if(q.size() == 0 || x != -q.top()) {
                    sprintf(buf1, "insert %d\n", x);
                    ans[cnt++] = string(buf1);
                    q.push(-x);
                }
            }
        }
        if(buf[0] != 'r')
            sprintf(buf1, "%s %d\n", buf, x);
        else sprintf(buf1, "%s\n", buf);
        ans[cnt++] = string(buf1);
    }
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++)
        printf("%s", ans[i].c_str());
    return 0;
}
