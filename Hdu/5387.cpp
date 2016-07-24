#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int gcd(int x, int y)
{
    if(y == 0) return x;
    return gcd(y, x % y);
}

struct node
{
    int a; int b;
    node(){}
    node(int a, int b): a(a), b(b){ d(); }
    void d()
    {
        int p = gcd(abs(a), abs(b));
        a /= p;
        b /= p;
    }

    node operator + (node t)
    {
        return node(a * t.b + b * t.a, b * t.b);
    }
    node operator - (node t)
    {
        return node(a * t.b - b * t.a, b * t.b);
    }

    bool operator > (node t)
    {
        node t1(a, b);
        t1 = t1 - t;
        if(t1.a * t1.b > 0) return true;
        return false;
    }

    void output()
    {
        if(b == 1) printf("%d", a);
        else printf("%d/%d", a, b);
    }

    void trans()
    {
        a = abs(a);
        b = abs(b);
    }
};

int h, m, s;

node cp(node a)
{
    static node p(180, 1);
    if(a > p) return (node(360, 1) - a);
    return a;
}

int main()
{
//    freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d:%d:%d", &h, &m, &s);
        if(h >= 12) h -= 12;
        node a = node(6 * s, 1);
        node b = node(m * 6, 1) + node(s, 10);
        node c = node(h * 30, 1) + node(m, 2) + node(s, 120);

        node ans1 = c - b;
        node ans2 = c - a;
        node ans3 = b - a;
        ans1.trans(); ans1 = cp(ans1); ans1.d();
        ans2.trans(); ans2 = cp(ans2); ans2.d();
        ans3.trans(); ans3 = cp(ans3); ans3.d();
        ans1.output(); printf(" "); ans2.output(); printf(" "); ans3.output(); printf(" \n");
    }
    return 0;
}
