#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#define FOR(i, j, k) for (int i = 0; i < j; i++)
#define rep(i, n) for(int i = 0; i < n; i++)
#define reset(a) memset(a, 0, sizeof a)
#define PI acos(-1)
#define LL long long


using namespace std;

struct obj
{
    int x, y;
    obj(){};
    obj(int a, int b)	{x = a;	y = b;}
    
    int operator == (obj a){return (x == a.x && y == a.y);}
    
    int operator > (obj a){if (x == a.x) return y > a.y;return x > a.x;}
    
    obj operator - (obj a){return obj(x - a.x, y - a.y);}
    
    obj operator + (obj a){	return obj(x + a.x, y + a.y);}
}a[1111];
int n;
int find(obj x)
{
    int l = 0, r = n - 1;
    while(l < r - 1)
    {
        int mid = (l + r) >> 1;
        if(a[mid] > x) r = mid;else l = mid;
    }
    if (x == a[l] || x == a[r]) return 1;
    return 0;
}

int cmp(obj x, obj y)
{
    if (x.x == y.x) return x.y < y.y;
    return x.x < y.x;
}

int main()
{
    while(true)
    {
        scanf("%d", &n);
        if (n == 0) break;
        rep(i, n)scanf("%d%d", &a[i].x, &a[i].y);
        sort(a, a + n, cmp);
        int cnt = 0;
        rep(i, n)
        FOR(j, i + 1, n)
        if (i != j)
        {
            obj x = a[i] - a[j];
            obj y = a[j] - a[i];
            obj p1 = a[j] + obj(x.y, -x.x);
            obj p2 = a[i] + obj(-y.y, y.x);
            if (find(p1) & find(p2))  cnt++;
            /*
             if (find(p1) && find(p2))
             {
             cout << a[i].x << " " << a[i].y << endl;
             cout << a[j].x << " " << a[j].y << endl;
             cout << p1.x << " " << p1.y << endl;
             cout << p2.x << " " << p2.y << endl;
             cout << endl;
             }
             */
        }
        printf("%d\n", cnt >> 1);
    }
    return 0;
}