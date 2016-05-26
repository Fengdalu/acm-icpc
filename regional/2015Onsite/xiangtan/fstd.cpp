#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200010;
struct tree
{
    int lt,rt,det,maxn,mii,flag;
}a[N << 2];

int c[N];
void init(int lt,int rt,int step) {
    a[step].lt = lt;
    a[step].rt = rt;
    a[step].det = 0;
    if(lt == rt) {
        a[step].maxn = a[step].mii = c[lt];
        return;
    }
    int mid = lt + rt >> 1;
    init(lt,mid,2 * step);
    init(mid + 1,rt,2 * step + 1);
    a[step].maxn = max(a[step * 2].maxn,a[2 * step + 1].maxn);
    a[step].mii = min(a[step * 2].mii,a[2 * step + 1].mii);
}

void add(int step,int val) {
    a[step].maxn += val;
    a[step].mii += val;
    a[step].det += val;
}

void down(int step) {
    add(2 * step,a[step].det);
    add(2 * step + 1,a[step].det);
    a[step].det = 0;
    a[2 * step].maxn = min(a[step].maxn,a[2 * step].maxn);
    a[2 * step].maxn = max(a[step].mii,a[2 * step].maxn);
    a[2 * step].mii = max(a[step].mii,a[2 * step].mii);
    a[2 * step].mii = min(a[step].maxn,a[2 * step].mii);

    a[2 * step + 1].maxn = min(a[step].maxn,a[2 * step + 1].maxn);
    a[2 * step + 1].maxn = max(a[step].mii,a[2 * step + 1].maxn);
    a[2 * step + 1].mii = max(a[step].mii,a[2 * step + 1].mii);
    a[2 * step + 1].mii = min(a[step].maxn,a[2 * step + 1].mii);
}

void add(int lt,int rt,int step,int val) {
    if(a[step].lt == lt && a[step].rt == rt) {
        add(step,val);
        return;
    }
    down(step);
    if(rt <= a[2 * step].rt) add(lt,rt,2 * step,val);
    else if(lt > a[2 * step].rt) add(lt,rt,2 * step + 1,val);
    else {
        add(lt,a[2 * step].rt,2 * step,val);
        add(a[2 * step + 1].lt,rt,2 * step + 1,val);
    }
    a[step].maxn = max(a[step * 2].maxn,a[2 * step + 1].maxn);
    a[step].mii = min(a[step * 2].mii,a[2 * step + 1].mii);
}

void update_min(int lt,int rt,int step,int val) {
    if(a[step].lt == lt && a[step].rt == rt) {
        a[step].flag = 1;
        a[step].mii = max(val,a[step].mii);
        a[step].maxn = max(val,a[step].maxn);
        //update(step);
        return;
    }
    down(step);
    if(rt <= a[2 * step].rt) update_min(lt,rt,2 * step,val);
    else if(lt > a[2 * step].rt) update_min(lt,rt,2 * step + 1,val);
    else {
        update_min(lt,a[2 * step].rt,2 * step,val);
        update_min(a[2 * step + 1].lt,rt,2 * step + 1,val);
    }
    a[step].maxn = max(a[step * 2].maxn,a[2 * step + 1].maxn);
    a[step].mii = min(a[step * 2].mii,a[2 * step + 1].mii);
}

void update_max(int lt,int rt,int step,int val) {
    if(a[step].lt == lt && a[step].rt == rt) {
        a[step].flag = 1;
        a[step].maxn = min(val,a[step].maxn);
        a[step].mii = min(val,a[step].mii);
        //update(step);
        return;
    }
    down(step);
    if(rt <= a[2 * step].rt) update_max(lt,rt,2 * step,val);
    else if(lt > a[2 * step].rt) update_max(lt,rt,2 * step + 1,val);
    else {
        update_max(lt,a[2 * step].rt,2 * step,val);
        update_max(a[2 * step + 1].lt,rt,2 * step + 1,val);
    }
    a[step].maxn = max(a[step * 2].maxn,a[2 * step + 1].maxn);
    a[step].mii = min(a[step * 2].mii,a[2 * step + 1].mii);
}

void query(int lt,int rt,int step,int &mx,int &mi) {
    if(a[step].lt == lt && a[step].rt == rt) {
        mx = max(mx,a[step].maxn);
        mi = min(mi,a[step].mii);
        return;
    }
    down(step);
    if(rt <= a[2 * step].rt) query(lt,rt,2 * step,mx,mi);
    else if(lt > a[2 * step].rt) query(lt,rt,2 * step + 1,mx,mi);
    else {
        query(lt,a[2 * step].rt,2 * step,mx,mi);
        query(a[2 * step + 1].lt,rt,2 * step + 1,mx,mi);
    }
}

void solve() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i ++) scanf("%d",&c[i]);
    init(1,n,1);
    int cd,x,y,z;
    while(m --) {
        scanf("%d%d%d",&cd,&x,&y);
        if(cd == 4) {
            int mx = -0x7fffffff;
            int mi = -mx;
            query(x,y,1,mx,mi);
            printf("%d %d\n",mi,mx);
        }
        else if(cd == 1) {
            scanf("%d",&z);
            add(x,y,1,z);
        }
        else if(cd == 3) {
            scanf("%d",&z);
            update_min(x,y,1,z);
        }
        else {
            scanf("%d",&z);
            update_max(x,y,1,z);
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t --) solve();
    return 0;
}
