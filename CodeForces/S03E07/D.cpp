#include <bits/stdc++.h>

typedef long long ll;
const int N = 5e5;
struct node {int l, r, type, id;}; 
node nodes[N*5], *curNode;
ll ans[N];
int a[N];
int sz;

void add(int l, int r, int type, int id) {
  curNode->l = l;
  curNode->r = r;
  curNode->type = type;
  curNode->id = id;
  curNode++;
}


int operator < (const node &a, const node &b) {
  if(a.l / sz == b.l / sz) return a.r < b.r;
  return a.l / sz < b.l / sz;
}

int sum1[N], sum2[N];
void deal() {
  int l1 = 0, l2 = 0;
  ll tot = 0;
  for(int i = 0; i < curNode - nodes; i++) {
    node &cur = nodes[i];
    while(l2 < cur.r) { 
      l2++; 
      sum2[a[l2]]++; 
      tot += sum1[a[l2]];
    }
    while(l2 > cur.r) { 
      tot -= sum1[a[l2]]; 
      sum2[a[l2]]--; 
      l2--;
    }
    while(l1 < cur.l) { 
      l1++; 
      sum1[a[l1]]++; 
      tot += sum2[a[l1]]; 
    }
    while(l1 > cur.l) { 
      tot -= sum2[a[l1]]; 
      sum1[a[l1]]--; 
      l1--; 
    }
    ans[cur.id] += nodes[i].type * tot;
  }
}

int main() {
  int n; scanf("%d", &n);

  curNode = nodes;
  for(int i = 0; i < n; i++) scanf("%d", a + i + 1);
  int m; scanf("%d", &m);
  int cnt = 0;

  for(int i = 0; i < m; i++) {
    int l1, r1, l2, r2;
    scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
    add(r1, r2, 1, i);
    add(l1 - 1, r2, -1, i);
    add(r1, l2 - 1, -1, i);
    add(l1 - 1, l2 - 1, 1, i);
  }
  sz = sqrt(n);
  std::sort(nodes, curNode);

  deal();
  for(int i = 0; i < m; i++) printf("%I64d\n", ans[i]);
  return 0;
}
