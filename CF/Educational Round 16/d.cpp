#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//扩展欧几里得
//ax+by=d;
//x'=x+b/d;
//y'=y-a/d;
//a,b要求非负!
ll exgcd(ll a,ll b,ll &x,ll &y) {
    if(b==0) {
        x=1;
        y=0;
        return a;
    }
    else
    {
        ll ret=exgcd(b,a%b,x,y);
        ll temp=x;
        x=y;
        y=temp-a/b*y;
        return ret;
    }
}

ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    else return gcd(b,a%b);
}

int main() {
    ll a1, b1, a2, b2, L, R;
    cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
    if(b2 < b1) {
        swap(a1, b1);
        swap(a2, b2);
    }
    if((b2 - b1) % gcd(a1, a2) != 0) {
        puts("0");
        return 0;
    }
    ll k, l;
    exgcd(a1, a2, k, l);
    ll d = gcd(a1, a2);
    if(l > 0) {
        ll k = l * d / a1;
        k += a2 / d * k;
        l -= a1 / d * k;
    }
    ll t = k * d / a2;
    k -= a2 / d * t;
    l += a1 / d * t;
    ll w = (b2 - b1) / gcd(a1, a2);
    k *= (b2 - b1) / d;
    l *= (b1 - b2) / d;
    ll right = (R - b1 - a1 * k)  / w;
    ll left = (L - 1 - b1 - a1 * k) / 2;
    cout << right - left << endl;
    return 0;
}
