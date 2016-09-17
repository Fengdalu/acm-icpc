#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

const int N = 100000 + 5;
long long a[N];
int n;
long long T;
long long q[N];
int l, r;
int p;

void init()
{
    p = 0;
    l = 0;
    r = 0;
    while(p + 1 < n && a[p + 1] == 0) p++;
}
inline int getsize()
{
    return n - p + r - l;
}
inline int getfirst(int k)
{
    int n = getsize();
    while(n - (k - 1) >= 1) n -= k - 1;
    return n;
}
inline long long getmin()
{
    if(p == n) return q[l++];
    if(l == r) return a[p++];
    if(q[l] < a[p]) return q[l++];
    return a[p++];
}
long long chk(int k)
{

    init();
    //while(!Q.empty()) Q.pop();
    //std::priority_queue<long long> Q;
    long long ret = 0;
    /*for(int i = 0; i < n; i++)
    {
        Q.push(-a[i]);
    }*/
    long long now = 0;
    int num;
    int first = getfirst(k);
    int cntk;
    while(1)
    {
        if(getsize() == 1) break;
        now = 0;
        num = 0;
        if(first - 1)
        {
            cntk = first;
            first = 1;
        }
        else cntk = k;
        while(getsize() && num < cntk)
        {
            num++;
            now += getmin();
        }
        ret += now;
        if(ret > T) return ret;
        q[r++] = now;
    }
    //printf("%lld\n", ret);
    return ret;
}
inline int read()
{
    char ch;bool flag = false;int a = 0;
    while(!((((ch = getchar()) >= '0') && (ch <= '9')) || (ch == '-')));
    if(ch != '-'){a *= 10;a += ch - '0';}else{flag = true;}
    while(((ch = getchar()) >= '0') && (ch <= '9')){a *= 10;a += ch - '0';}
    if(flag)a = -a;return a;
}
void run()
{
    //I64d
    /*
    scanf("%d%I64d",&n,&T);
    for(int i = 0; i < n; i++)
        scanf("%I64d",&a[i]);*/
    n = read(); T = read();
    for(int i = 0; i < n; i++) a[i] = read();
    std::sort(a, a + n);
    int l = 2;
    int r = n;
    int mid;
    while(l < r)
    {
        mid = (l + r) >> 1;
        if(chk(mid) <= T) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--) run();
}
